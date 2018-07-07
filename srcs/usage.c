/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:52:13 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/06/07 14:52:13 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fractol.h"

void	usage(void)
{
	ft_putendl("Usage ./fractol");
	ft_putendl("-m (Mandelbrot)");
	ft_putendl("-j (Julia)");
	ft_putendl("-t (Tricorn)");
	ft_putendl("-c (Celtic)");
	ft_putendl("-b (Burning Ship)");
	ft_putendl("-h (Heart)");
	ft_putendl("-f (Buffalo)");
}
