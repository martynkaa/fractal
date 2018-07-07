/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:05:24 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/06/06 20:05:32 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fractol.h"

void	legend(t_mlx *p)
{
	char *iter;

	iter = ft_itoa(p->p_set->maxiterations);
	mlx_string_put(p->p_mlx, p->p_win, 10, 10, 0xd4d8dd, "Instructions: ");
	mlx_string_put(p->p_mlx, p->p_win, 10, 30, 0xFFFFFF, "iterations: ");
	mlx_string_put(p->p_mlx, p->p_win, 130, 30, 0xFFFFFF, iter);
	mlx_string_put(p->p_mlx, p->p_win, 10, 50, 0xFFFFFF, "move: arrows");
	mlx_string_put(p->p_mlx, p->p_win, 10, 70, 0xFFFFFF, "zoom: mouse scroll");
	mlx_string_put(p->p_mlx, p->p_win, 10, 90, 0xFFFFFF, "change power: P / O");
	mlx_string_put(p->p_mlx, p->p_win, 10, 110, 0xFFFFFF,
		"(available only for M and J)");
	mlx_string_put(p->p_mlx, p->p_win, 10, 130, 0xFFFFFF, "color: QWERTY");
	mlx_string_put(p->p_mlx, p->p_win, 10, 150, 0xFFFFFF,
		"hide instructions: TAB");
	mlx_string_put(p->p_mlx, p->p_win, 10, 830, 0xFFFFFF, "Fractals: ");
	mlx_string_put(p->p_mlx, p->p_win, 10, 850, 0xFFFFFF, "1 - Mandelbrot");
	mlx_string_put(p->p_mlx, p->p_win, 10, 870, 0xFFFFFF, "2 - Julia");
	mlx_string_put(p->p_mlx, p->p_win, 10, 890, 0xFFFFFF, "3 - Tricorn");
	mlx_string_put(p->p_mlx, p->p_win, 10, 910, 0xFFFFFF, "4 - Celtic");
	mlx_string_put(p->p_mlx, p->p_win, 10, 930, 0xFFFFFF, "5 - Burning Ship");
	mlx_string_put(p->p_mlx, p->p_win, 10, 950, 0xFFFFFF, "6 - Heart");
	mlx_string_put(p->p_mlx, p->p_win, 10, 970, 0xFFFFFF, "7 - Buffalo");
	free(iter);
}
