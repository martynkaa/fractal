/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:03:21 by mpopovyc          #+#    #+#             */
/*   Updated: 2017/11/11 19:18:32 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*buff;

	i = 0;
	len = ft_strlen(s1);
	if (!s1)
		return (NULL);
	buff = (char*)malloc(sizeof(char) * (len + 1));
	if (buff == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		buff[i] = s1[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
