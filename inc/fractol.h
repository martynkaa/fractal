/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:54:58 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/05/15 18:55:01 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <OpenCL/opencl.h>

/*
** width and height of the window
*/

# define W_W 1000
# define W_H 1000

/*
** functions fractals with higher pows
*/

# define SQR(n) n * n
# define SQRD(n) SQR(n) * SQR(n)

/*
** KEYS
*/

# define SCROLL_OUT 4
# define SCROLL_IN 5
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define PLUS_ITER 24
# define MINUS_ITER 27
# define STOP_MOTION 49
# define PLUS_POW 35
# define MINUS_POW 31
# define RESET 6
# define HIDE_LEGEND 48

/*
** COLORS
*/

# define SILVER 12
# define CHERRY 13
# define WARMIE 14
# define FREAKY 15
# define PINKY 17
# define BLUIE 16

/*
** FRACTALS
*/

# define MANDELBROT 18
# define JULIA 19
# define TRICORN 20
# define CELTIC 21
# define BURNING_SHIP 23
# define HEART 22
# define BUFFALO 26

/*
** opencl structure
*/

typedef	struct			s_cl
{
	char				*line;
	cl_device_id		device_id;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_double			*constants;
	cl_mem				buffer;
	cl_mem				output;
	cl_program			program;
	cl_kernel			kernel;
}						t_cl;

/*
** fractal set structure (x - real, y - imaginary)
*/

typedef struct			s_set
{
	int					set;
	double				dx;
	double				dy;
	double				xmin;
	double				ymin;
	double				xmax;
	double				ymax;
	double				mouse_x;
	double				mouse_y;
	int					pow;
	int					maxiterations;
}						t_set;

/*
** screen effect structure
*/

typedef struct			s_screen
{
	double				move_x;
	double				move_y;
	double				zoom_x;
	double				zoom_y;
	double				zoomfactor;
	int					motion;
	int					hide;
	int					beforecolor;
	int					aftercolor;
	int					magic;
}						t_screen;

/*
** mlx structure
*/

typedef	struct			s_mlx
{
	t_set				*p_set;
	t_screen			*p_scr;
	t_cl				*p_cl;
	void				*p_mlx;
	void				*p_win;
	void				*p_img;
	int					*p_screen;
	int					bpp;
	int					size;
	int					endian;
}						t_mlx;

/*
** mlx and window functions
*/

void					mlx_initiation(t_mlx *p);
void					ft_putpixel(t_mlx *p, int x, int y, int color);
void					create_str(t_mlx *p, t_set *set,
						t_screen *scr, t_cl *cl);
void					clear_window(t_mlx *p);
void					clear_arr(t_mlx *p);

/*
** opencl functions
*/

void					read_source(t_cl *cl);
void					opencl_initiation(t_cl *cl, t_mlx *p);

/*
** hook functions
*/

int						exit_x(void);
int						press_key(int key, t_mlx *p);
void					stop_key(t_mlx *p);
void					ficha_keys(int key, t_mlx *p);
int						mouse(int key, int mouse_x, int mouse_y, t_mlx *p);
int						motion(int mouse_x, int mouse_y, t_mlx *p);

/*
**helpful functions
*/

void					draw_fract(t_mlx *p);
void					set_default(t_mlx *p);
void					set_center(t_mlx *p);
void					legend(t_mlx *p);
void					usage(void);

#endif
