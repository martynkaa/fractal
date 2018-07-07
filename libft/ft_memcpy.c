/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 11:42:26 by mpopovyc          #+#    #+#             */
/*   Updated: 2017/11/16 13:21:16 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dest;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (unsigned char *)dst;
	while (n-- > 0)
		*dest++ = *(unsigned char *)src++;
	return (dst);
}
