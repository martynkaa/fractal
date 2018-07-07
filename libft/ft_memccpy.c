/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:43:35 by mpopovyc          #+#    #+#             */
/*   Updated: 2017/11/11 19:17:16 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *dest;
	unsigned char *str;

	dest = (unsigned char *)dst;
	str = (unsigned char *)src;
	while (n-- > 0)
	{
		*dest = *str;
		if (*dest == (unsigned char)c)
			return (dest + 1);
		dest++;
		str++;
	}
	return (NULL);
}
