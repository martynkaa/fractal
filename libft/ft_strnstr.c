/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:27:07 by mpopovyc          #+#    #+#             */
/*   Updated: 2017/11/12 12:01:15 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	if (needle == NULL & haystack == NULL)
		return (NULL);
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		k = 0;
		while (haystack[i + k] == needle[k] && (i + k) < len)
		{
			if (needle[k + 1] == '\0')
				return ((char *)haystack + i);
			k++;
		}
		i++;
	}
	return (NULL);
}
