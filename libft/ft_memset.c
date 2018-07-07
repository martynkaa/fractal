/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:16:38 by mpopovyc          #+#    #+#             */
/*   Updated: 2017/11/11 19:16:41 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t len)
{
	size_t i;

	i = 0;
	while (len-- > 0)
	{
		*((unsigned char *)src + i) = (unsigned char)c;
		i++;
	}
	return (src);
}
