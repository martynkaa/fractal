/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:16:24 by mpopovyc          #+#    #+#             */
/*   Updated: 2017/11/11 19:17:24 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dest;
	unsigned const char *str;

	i = 0;
	dest = (unsigned char *)dst;
	str = (unsigned const char *)src;
	if (src == NULL && dst == NULL)
		return (NULL);
	if (dest < str)
	{
		while (i < len)
		{
			dest[i] = str[i];
			i++;
		}
	}
	else if (dest > str)
	{
		while (len-- > 0)
			dest[len] = str[len];
	}
	return (dest);
}
