/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:34:42 by mpopovyc          #+#    #+#             */
/*   Updated: 2017/11/12 18:39:04 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_mas_size(char const *s, char c)
{
	size_t count;
	size_t words;

	count = 0;
	words = 0;
	while (s[count] != '\0')
	{
		while (s[count] == c)
			count++;
		while (s[count] != c && s[count] != '\0')
		{
			if (s[count + 1] == c || s[count + 1] == '\0')
				words++;
			count++;
		}
	}
	return (words);
}

static	size_t	ft_len(char const *s, char c)
{
	size_t count;

	count = 0;
	while (s[count] != c && s[count] != '\0')
		count++;
	return (count);
}

static	void	ft_free(char **s, size_t i)
{
	while (i)
		free(s[i--]);
	free(s[i]);
	free(s);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	k;

	i = 0;
	if (!s)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char *) * ft_mas_size(s, c) + 1)))
		return (NULL);
	while (ft_mas_size(s, c) > 0)
	{
		k = 0;
		while (*s == c)
			s++;
		if (!(split[i] = (char *)malloc(sizeof(char) * ft_len(s, c) + 1)))
		{
			ft_free(split, i);
			return (NULL);
		}
		while (*s != '\0' && *s != c)
			split[i][k++] = *s++;
		split[i++][k] = '\0';
	}
	split[i] = NULL;
	return (split);
}
