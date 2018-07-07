/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:07:32 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/03/27 17:23:19 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(uintmax_t value, int base)
{
	int			len;

	len = 0;
	if (value == 0)
		len++;
	while (value != 0)
	{
		value = value / base;
		len++;
	}
	return (len);
}

char			*ft_itoa_ubase(uintmax_t number, int base)
{
	char		*str;
	int			len;

	len = ft_len(number, base);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = "0123456789abcdef"[number % base];
		number /= base;
		len--;
	}
	return (str);
}
