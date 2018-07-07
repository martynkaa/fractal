/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:21:54 by mpopovyc          #+#    #+#             */
/*   Updated: 2017/11/12 10:59:40 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	if (needle == NULL && haystack == NULL)
		return (NULL);
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		k = 0;
		while (haystack[i + k] == needle[k])
		{
			if (needle[k + 1] == '\0')
				return ((char *)haystack + i);
			k++;
		}
		i++;
	}
	return (NULL);
}
