/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:13:55 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/05/20 16:13:56 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fractol.h"

static double		interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

static void			zoomchik(t_screen *scr, t_set *set, int x, int y)
{
	double			interpolation;

	scr->zoom_x = (double)x / (W_W / (set->xmax - set->xmin)) + set->xmin;
	scr->zoom_y = (double)y / (W_H / (set->ymax - set->ymin)) + set->ymin;
	interpolation = 1.0 / scr->zoomfactor;
	set->xmin = interpolate(scr->zoom_x, set->xmin, interpolation);
	set->ymin = interpolate(scr->zoom_y, set->ymin, interpolation);
	set->xmax = interpolate(scr->zoom_x, set->xmax, interpolation);
	set->ymax = interpolate(scr->zoom_y, set->ymax, interpolation);
}

int					mouse(int key, int mouse_x, int mouse_y, t_mlx *p)
{
	if (key == SCROLL_OUT)
	{
		p->p_scr->zoomfactor = 1.1;
		zoomchik(p->p_scr, p->p_set, mouse_x, mouse_y);
	}
	if (key == SCROLL_IN)
	{
		p->p_scr->zoomfactor = 0.9;
		zoomchik(p->p_scr, p->p_set, mouse_x, mouse_y);
	}
	clear_window(p);
	draw_fract(p);
	return (0);
}

int					motion(int mouse_x, int mouse_y, t_mlx *p)
{
	if (p->p_scr->motion == 1)
	{
		p->p_set->mouse_x = (mouse_x + p->p_set->xmax - p->p_set->xmin) / (W_W);
		p->p_set->mouse_y = (mouse_y + p->p_set->ymax - p->p_set->ymin) / (W_H);
	}
	clear_window(p);
	draw_fract(p);
	return (0);
}
