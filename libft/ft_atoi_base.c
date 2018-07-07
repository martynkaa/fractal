/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:12:02 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/04/15 12:22:39 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

int		ft_number(char a)
{
	int ret;

	ret = 0;
	if (a >= '0' && a <= '9')
		ret = a - '0';
	else if (a == 'a' || a == 'A')
		ret = 10;
	else if (a == 'b' || a == 'B')
		ret = 11;
	else if (a == 'c' || a == 'C')
		ret = 12;
	else if (a == 'd' || a == 'D')
		ret = 13;
	else if (a == 'e' || a == 'E')
		ret = 14;
	else if (a == 'f' || a == 'F')
		ret = 15;
	else
		ret = -1;
	return (ret);
}

int		ft_check(const char *str, int str_base)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (ft_number(str[i]) >= str_base || ft_number(str[i]) == -1)
		{
			i--;
			break ;
		}
		i++;
	}
	str[i] == '\0' ? i -= 1 : 0;
	return (i);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	flag;
	int	res;
	int	mem;

	i = 0;
	res = 0;
	flag = 1;
	if (!str)
		return (0);
	mem = ft_check(str, str_base);
	if (str[0] == '-')
		flag = -1;
	while (mem >= 0 && str[mem] != '-')
	{
		res += ft_pow(str_base, i) * ft_number(str[mem]);
		i++;
		mem--;
	}
	flag == -1 ? res = res * flag : 0;
	return (res);
}
