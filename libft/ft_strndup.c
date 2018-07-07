/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 12:22:58 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/03/24 12:40:16 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strndup(const char *s1, int n)
{
	int		i;
	int		len;
	char	*buff;

	i = 0;
	len = 0;
	while (len < n)
		len++;
	buff = (char*)malloc(sizeof(char) * (len + 1));
	if (buff == NULL)
		return (NULL);
	while (i < n)
	{
		buff[i] = s1[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
