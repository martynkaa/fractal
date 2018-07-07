/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_source.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 19:46:36 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/06/04 19:46:39 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fractol.h"

void		read_source(t_cl *cl)
{
	int		fd;
	int		ret;
	char	buff[1001];

	cl->line = strdup("");
	if ((fd = open("main/fractals.cl", O_RDONLY)) == -1)
	{
		perror(buff);
		return ;
	}
	while ((ret = read(fd, buff, 1000)) > 0)
	{
		buff[ret] = '\0';
		cl->line = ft_strjoin_freestr1(cl->line, buff);
	}
	close(fd);
}
