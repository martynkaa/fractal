/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:41:49 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/05/17 16:41:51 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fractol.h"

static void			set_fract(t_mlx *p, char **argv)
{
	if (argv[1][1] == 'm')
		p->p_set->set = 1;
	else if (argv[1][1] == 'j')
		p->p_set->set = 2;
	else if (argv[1][1] == 't')
		p->p_set->set = 3;
	else if (argv[1][1] == 'c')
		p->p_set->set = 4;
	else if (argv[1][1] == 'b')
		p->p_set->set = 5;
	else if (argv[1][1] == 'h')
		p->p_set->set = 6;
	else if (argv[1][1] == 'f')
		p->p_set->set = 7;
	else
	{
		usage();
		exit(0);
	}
}

static void			det_fract(t_mlx *p, char **argv)
{
	if (argv[1][0] == '-')
	{
		set_fract(p, argv);
		set_default(p);
	}
	else
	{
		usage();
		exit(0);
	}
}

int					main(int argc, char **argv)
{
	t_mlx			p;
	t_screen		scr;
	t_set			set;
	t_cl			cl;

	if (argc == 2)
	{
		create_str(&p, &set, &scr, &cl);
		det_fract(&p, argv);
		mlx_initiation(&p);
		draw_fract(&p);
		mlx_hook(p.p_win, 17, 1L << 1, exit_x, &p);
		mlx_hook(p.p_win, 2, 1, &press_key, &p);
		if (p.p_scr->motion == 0)
			mlx_hook(p.p_win, 6, 1, &motion, &p);
		mlx_mouse_hook(p.p_win, &mouse, &p);
		mlx_loop(p.p_mlx);
	}
	else
		usage();
	return (0);
}
