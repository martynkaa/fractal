/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:34:37 by mpopovyc          #+#    #+#             */
/*   Updated: 2017/11/11 19:25:13 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *s;

	if (size)
	{
		s = (void*)malloc(size);
		if (!s)
			return (NULL);
		ft_bzero(s, size);
		return (s);
	}
	return (NULL);
}
