/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl_initiation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 20:27:31 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/05/23 20:27:33 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./../inc/fractol.h"

static void		load_arg(t_cl *cl, t_mlx *p)
{
	cl->constants[0] = p->p_set->xmin;
	cl->constants[1] = p->p_set->ymin;
	cl->constants[2] = (p->p_set->xmax - p->p_set->xmin) / (W_W);
	cl->constants[3] = (p->p_set->ymax - p->p_set->ymin) / (W_H);
	cl->constants[4] = p->p_set->mouse_x;
	cl->constants[5] = p->p_set->mouse_y;
	cl->constants[6] = p->p_set->maxiterations;
	cl->constants[7] = p->p_set->pow;
	cl->constants[8] = p->p_scr->beforecolor;
	cl->constants[9] = p->p_scr->aftercolor;
	cl->constants[10] = p->p_set->set;
	cl->constants[11] = p->p_scr->magic;
}

static int		start_init(t_cl *cl, t_mlx *p)
{
	int			ret;

	cl->constants = (double *)malloc(sizeof(double) * 12);
	if (clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1,
		&cl->device_id, NULL) != CL_SUCCESS)
		return (-1);
	cl->context = clCreateContext(NULL, 1, &cl->device_id, NULL, NULL, &ret);
	cl->command_queue = clCreateCommandQueue(cl->context,
		cl->device_id, 0, &ret);
	if (ret != CL_SUCCESS)
		return (-1);
	cl->buffer = clCreateBuffer(cl->context, CL_MEM_READ_WRITE,
		sizeof(double) * 12, NULL, &ret);
	if (ret)
		return (-1);
	cl->output = clCreateBuffer(cl->context, CL_MEM_READ_WRITE,
		sizeof(int) * W_W * W_H, NULL, &ret);
	if (ret)
		return (-1);
	load_arg(cl, p);
	return (0);
}

static int		start_program(t_cl *cl)
{
	int			ret;
	size_t		global_item_size;
	size_t		local_item_size;

	local_item_size = 200;
	ret = clEnqueueWriteBuffer(cl->command_queue, cl->buffer, CL_FALSE, 0,
		sizeof(cl_double) * 12, cl->constants, 0, NULL, NULL);
	cl->program = clCreateProgramWithSource(cl->context, 1,
		(const char**)&cl->line, NULL, &ret);
	if (ret != CL_SUCCESS)
		return (-1);
	if ((ret = clBuildProgram(cl->program, 1, &cl->device_id,
		NULL, NULL, NULL)) != CL_SUCCESS)
		return (-1);
	cl->kernel = clCreateKernel(cl->program, "fractals", &ret);
	ret = clSetKernelArg(cl->kernel, 0, sizeof(cl_mem), (void *)&cl->output);
	ret = clSetKernelArg(cl->kernel, 1, sizeof(cl_mem), (void *)&cl->buffer);
	global_item_size = W_W * W_H;
	ret = clEnqueueNDRangeKernel(cl->command_queue, cl->kernel, 1, NULL,
		&global_item_size, &local_item_size, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		return (-1);
	return (0);
}

static int		read_cl(t_cl *cl, t_mlx *p)
{
	int			ret;

	ret = clEnqueueReadBuffer(cl->command_queue, cl->output, CL_TRUE, 0,
		sizeof(int) * W_W * W_H, p->p_screen, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		return (-1);
	clFlush(cl->command_queue);
	clFinish(cl->command_queue);
	clReleaseKernel(cl->kernel);
	clReleaseProgram(cl->program);
	clReleaseMemObject(cl->output);
	clReleaseMemObject(cl->buffer);
	clReleaseCommandQueue(cl->command_queue);
	clReleaseContext(cl->context);
	free(cl->constants);
	free(cl->line);
	return (0);
}

void			opencl_initiation(t_cl *cl, t_mlx *p)
{
	int			err;

	read_source(cl);
	if ((err = start_init(cl, p)) != 0)
		exit(0);
	if ((err = start_program(cl)) != 0)
		exit(0);
	if ((err = read_cl(cl, p)) != 0)
		exit(0);
	mlx_put_image_to_window(p->p_mlx, p->p_win, p->p_img, 0, 0);
}
