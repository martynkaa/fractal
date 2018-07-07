/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:53:29 by mpopovyc          #+#    #+#             */
/*   Updated: 2017/11/11 19:27:37 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	size_t	slen;
	char	*cps;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i != slen)
		while (s[slen - 1] == ' ' || s[slen - 1] == '\n' || s[slen - 1] == '\t')
			slen--;
	cps = (char *)malloc(sizeof(char) * (slen - i + 1));
	if (!cps)
		return (NULL);
	while (i < slen)
		cps[len++] = s[i++];
	cps[len] = '\0';
	return (cps);
}
