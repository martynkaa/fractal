/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:26:40 by mpopovyc          #+#    #+#             */
/*   Updated: 2017/11/12 16:45:02 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *str)
{
	char	*begin;
	char	*s;
	size_t	len;

	if (str)
	{
		len = ft_strlen(str);
		if (!(s = (char *)malloc(sizeof(*str) + 1)))
			return (NULL);
		begin = s;
		while (len-- > 0)
			*s++ = str[len];
		*s = '\0';
		return (begin);
	}
	return (NULL);
}
