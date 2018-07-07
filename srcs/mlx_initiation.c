/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initiation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:59:49 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/04/21 15:59:53 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fractol.h"

void		mlx_initiation(t_mlx *p)
{
	if ((p->p_mlx = mlx_init()) == NULL)
	{
		ft_putstr("mlx init error\n");
		exit(0);
	}
	if ((p->p_win = mlx_new_window(p->p_mlx, W_W, W_H, "fractol")) == NULL)
	{
		ft_putstr("mlx window init error\n");
		exit(0);
	}
	if ((p->p_img = mlx_new_image(p->p_mlx, W_W, W_H)) == NULL)
	{
		ft_putstr("mlx image init error\n");
		exit(0);
	}
	if ((p->p_screen = (int *)mlx_get_data_addr(p->p_img,
		&p->bpp, &p->size, &p->endian)) == NULL)
	{
		ft_putstr("mlx image get data error\n");
		exit(0);
	}
	mlx_put_image_to_window(p->p_mlx, p->p_win, p->p_img, 0, 0);
}
