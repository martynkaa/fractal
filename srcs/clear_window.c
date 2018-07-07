/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:18:42 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/05/20 15:18:43 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fractol.h"

void		clear_arr(t_mlx *p)
{
	int i;

	i = -1;
	while (++i < W_W * W_H)
		p->p_screen[i] = 0x0;
}

void		clear_window(t_mlx *p)
{
	clear_arr(p);
	mlx_clear_window(p->p_mlx, p->p_win);
}
