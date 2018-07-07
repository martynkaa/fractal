/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hookie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 20:28:04 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/06/09 20:28:05 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fractol.h"

int		exit_x(void)
{
	exit(1);
	return (0);
}

void	stop_key(t_mlx *p)
{
	if (p->p_scr->motion == 0)
		p->p_scr->motion = 1;
	else
		p->p_scr->motion = 0;
}

void	ficha_keys(int key, t_mlx *p)
{
	if (key == PLUS_POW && p->p_set->pow < 5)
		p->p_set->pow += 1;
	if (key == MINUS_POW && p->p_set->pow > 2)
		p->p_set->pow -= 1;
	set_default(p);
}
