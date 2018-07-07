/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:28:46 by mpopovyc          #+#    #+#             */
/*   Updated: 2017/11/18 15:16:13 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t res;

	if (ft_strlen(dst) >= size)
		return (ft_strlen((char*)src) + size);
	res = ft_strlen(dst) + ft_strlen(src);
	while (*dst && size--)
		dst++;
	while (size-- > 1 && *src)
		*(dst++) = *(src++);
	*dst = '\0';
	return (res);
}
