/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:57:48 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/04/15 12:25:46 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(char *str, char c)
{
	size_t len;
	size_t i;

	len = 1;
	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			if (str[i++] == c)
				return (len);
			len++;
		}
	}
	return (0);
}

int		ft_check_len(char *buff, char **line, t_list *run)
{
	void	*ptr;
	char	*tmp;
	size_t	i;

	i = 0;
	ptr = run->content;
	if ((ft_strclen(buff, '\n')) == 0)
	{
		run->content = ft_strjoin(run->content, buff);
		free(ptr);
		return (0);
	}
	else
	{
		while (buff[i] != '\n' && buff[i] != '\0')
			i++;
		tmp = ft_strsub(buff, 0, i);
		*line = ft_strjoin((char*)run->content, tmp);
		run->content = (void*)ft_strdup(buff + i + 1);
		free(ptr);
		free(tmp);
		return (1);
	}
}

int		ft_check_content(char **line, t_list *run)
{
	char		*ptr;
	size_t		len;
	size_t		n;

	if (!run->content)
		return (0);
	if ((len = ft_strclen(run->content, '\n')) == 0)
		return (0);
	else
	{
		ptr = (char*)run->content;
		*line = ft_strsub(run->content, 0, len - 1);
		n = ft_strlen(run->content);
		run->content = ft_strsub(run->content, len, n - len);
		free(ptr);
		return (1);
	}
}

int		ft_read_and_check(char **line, t_list *run, int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;

	if (run)
	{
		while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			if ((ft_check_len(buff, line, run)) == 1)
				return (1);
			ft_bzero(buff, BUFF_SIZE);
		}
		if (ret < 0)
			return (-1);
		if (run->content && *(char *)run->content != '\0')
		{
			*line = ft_strdup(run->content);
			free(run->content);
			run->content = NULL;
			return (1);
		}
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*ptr;
	t_list			*run;

	run = ptr;
	if (fd < 0 || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	while (run != NULL && (size_t)fd != run->content_size)
		run = run->next;
	if (run == NULL)
	{
		run = ft_lstnew("", 1);
		run->content_size = (size_t)fd;
		ft_lstadd(&ptr, run);
	}
	if ((ft_check_content(line, run)) == 1)
		return (1);
	if (ft_read_and_check(line, run, fd) == 1)
		return (1);
	else if (ft_read_and_check(line, run, fd) == -1)
		return (-1);
	return (0);
}
