/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:55:22 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/03/27 19:57:01 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		ft_len(long long int n)
{
	size_t			len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(long long int number)
{
	long long int	n;
	int				len;
	char			*str;

	n = number;
	len = ft_len(number);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (number < 0)
		number *= -1;
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = number % 10 + '0';
		number /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
