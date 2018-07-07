/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:22:03 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/05/17 20:22:04 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fractol.h"

static void		fractals(int key, t_mlx *p)
{
	if (key == 18)
		p->p_set->set = 1;
	else if (key == 19)
		p->p_set->set = 2;
	else if (key == 20)
		p->p_set->set = 3;
	else if (key == 21)
		p->p_set->set = 4;
	else if (key == 23)
		p->p_set->set = 5;
	else if (key == 22)
		p->p_set->set = 6;
	else if (key == 26)
		p->p_set->set = 7;
	p->p_set->pow = 2;
	set_default(p);
}

static void		key_move(int key, t_mlx *p)
{
	if (key == RIGHT)
	{
		p->p_set->xmin -= 0.01 * (p->p_set->xmax - p->p_set->xmin);
		p->p_set->xmax -= 0.01 * (p->p_set->xmax - p->p_set->xmin);
	}
	else if (key == LEFT)
	{
		p->p_set->xmax += 0.01 * (p->p_set->xmax - p->p_set->xmin);
		p->p_set->xmin += 0.01 * (p->p_set->xmax - p->p_set->xmin);
	}
	else if (key == UP)
	{
		p->p_set->ymin += 0.01 * (p->p_set->ymax - p->p_set->ymin);
		p->p_set->ymax += 0.01 * (p->p_set->ymax - p->p_set->ymin);
	}
	else if (key == DOWN)
	{
		p->p_set->ymin -= 0.01 * (p->p_set->ymax - p->p_set->ymin);
		p->p_set->ymax -= 0.01 * (p->p_set->ymax - p->p_set->ymin);
	}
	else if (key == PLUS_ITER)
		p->p_set->maxiterations += 1;
	else if (key == MINUS_ITER)
		p->p_set->maxiterations -= 1;
}

static void		colors_key(int key, t_mlx *p)
{
	if (key == SILVER || key == CHERRY)
	{
		key == SILVER ? p->p_scr->aftercolor = 0xcecccc : 0;
		key == CHERRY ? p->p_scr->aftercolor = 0x87273e : 0;
		p->p_scr->magic = 0;
	}
	else if (key == WARMIE)
		p->p_scr->magic = -2147483;
	else if (key == FREAKY)
		p->p_scr->magic = -214748379;
	else if (key == BLUIE)
		p->p_scr->magic = 2147459;
	else if (key == PINKY)
		p->p_scr->magic = 214745911;
	else if (key == HIDE_LEGEND)
	{
		if (p->p_scr->hide == 0)
			p->p_scr->hide = 1;
		else
			p->p_scr->hide = 0;
	}
}

int				press_key(int key, t_mlx *p)
{
	if (key == 53)
		exit(0);
	else if (key == MANDELBROT || key == JULIA || key == TRICORN ||
		key == CELTIC || key == BURNING_SHIP || key == HEART || key == BUFFALO)
		fractals(key, p);
	else if (key == RIGHT || key == LEFT || key == UP || key == DOWN ||
		key == PLUS_ITER || key == MINUS_ITER)
		key_move(key, p);
	else if (key == STOP_MOTION)
		stop_key(p);
	else if (key == SILVER || key == CHERRY || key == WARMIE ||
		key == FREAKY || key == BLUIE || key == PINKY || key == HIDE_LEGEND)
		colors_key(key, p);
	else if (key == PLUS_POW || key == MINUS_POW || key == RESET)
		ficha_keys(key, p);
	clear_window(p);
	draw_fract(p);
	return (0);
}
