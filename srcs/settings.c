/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:38:52 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/05/29 20:38:53 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fractol.h"

void	set_center(t_mlx *p)
{
	if (p->p_set->set == 1 || p->p_set->set == 6)
	{
		p->p_set->xmin = -2;
		p->p_set->ymin = -1.25;
		p->p_set->xmax = 0.5;
		p->p_set->ymax = 1.25;
	}
	else if (p->p_set->set == 4)
	{
		p->p_set->xmin = -2;
		p->p_set->ymin = -1.75;
		p->p_set->xmax = 0.5;
		p->p_set->ymax = 1.75;
	}
	else if (p->p_set->set == 5 || p->p_set->set == 7)
	{
		p->p_set->xmin = -2.8;
		p->p_set->ymin = -2.7;
		p->p_set->xmax = 1.6;
		p->p_set->ymax = 2;
	}
}

void	set_default(t_mlx *p)
{
	p->p_scr->zoomfactor = 1;
	p->p_scr->beforecolor = 0x0;
	p->p_set->maxiterations = 42;
	p->p_set->xmin = -2;
	p->p_set->ymin = -2;
	p->p_set->xmax = 2;
	p->p_set->ymax = 2;
	p->p_set->mouse_x = 0;
	p->p_set->mouse_y = 0;
	if ((p->p_set->set == 1 || p->p_set->set == 4 || p->p_set->set == 5 ||
		p->p_set->set == 6 || p->p_set->set == 7)
		&& p->p_set->pow == 2)
		set_center(p);
}
