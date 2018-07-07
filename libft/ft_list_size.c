/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:54:48 by mpopovyc          #+#    #+#             */
/*   Updated: 2017/11/13 18:09:07 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_list_size(t_list *begin_list)
{
	size_t len;

	len = 0;
	while (begin_list != NULL)
	{
		begin_list = begin_list->next;
		len++;
	}
	return (len);
}
