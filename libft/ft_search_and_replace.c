/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_and_replace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:02:17 by mpopovyc          #+#    #+#             */
/*   Updated: 2017/11/12 16:45:53 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_search_and_replace(char *s, char a, char b)
{
	char *begin;

	if (s)
	{
		begin = s;
		while (*s != '\0')
		{
			if (*s == a)
				*s = b;
			s++;
		}
		return (begin);
	}
	return (NULL);
}
