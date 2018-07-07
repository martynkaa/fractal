/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:38:46 by mpopovyc          #+#    #+#             */
/*   Updated: 2017/11/11 19:24:10 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	whitespaces(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
			c == '\v' || c == '\f' || c == '\r');
}

int			ft_atoi(const char *str)
{
	int					i;
	int					flag;
	unsigned long int	res;

	i = 0;
	res = 0;
	flag = 1;
	while (whitespaces(str[i]))
		i++;
	if (str[i] == '-')
		flag = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10 + (str[i] - '0');
		if (res >= 9223372036854775807 && flag == 1)
			return (-1);
		else if (res > 9223372036854775807 && flag == -1)
			return (0);
		i++;
	}
	return (res * flag);
}
