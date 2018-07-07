/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:47:21 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/03/27 16:50:18 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_bytelen(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0x7FFF)
		return (3);
	else if (c <= 0x1FFFFF)
		return (4);
	return (-1);
}

size_t	ft_wstrlen(wchar_t *str)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (str[i])
	{
		len += ft_bytelen(str[i]);
		i++;
	}
	return (len);
}
