/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_strctr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 19:47:53 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/05/17 19:47:54 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fractol.h"

void	create_str(t_mlx *p, t_set *set, t_screen *scr, t_cl *cl)
{
	p->p_set = set;
	p->p_scr = scr;
	p->p_cl = cl;
	p->p_scr->hide = 0;
	p->p_scr->move_x = 0;
	p->p_scr->move_y = 0;
	p->p_scr->zoom_x = 0;
	p->p_scr->zoom_y = 0;
	p->p_scr->zoomfactor = 1;
	p->p_scr->beforecolor = 0x0;
	p->p_scr->aftercolor = 0xcecccc;
	p->p_scr->magic = 0;
	p->p_scr->motion = 0;
	p->p_set->maxiterations = 42;
	p->p_set->xmin = -2;
	p->p_set->ymin = -2;
	p->p_set->xmax = 2;
	p->p_set->ymax = 2;
	p->p_set->mouse_x = 0;
	p->p_set->mouse_y = 0;
	p->p_set->pow = 2;
}
