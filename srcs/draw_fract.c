/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 20:32:22 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/06/09 20:32:25 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fractol.h"

void	draw_fract(t_mlx *p)
{
	opencl_initiation(p->p_cl, p);
	if (p->p_scr->hide == 0)
		legend(p);
}