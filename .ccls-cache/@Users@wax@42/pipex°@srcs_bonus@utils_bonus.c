/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:45:26 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/14 14:50:39 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

void	ft_free(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s_buff = NULL;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	if (read(fd, buf, 0) < 0)
	{
		free(buf);
		return (NULL);
	}
	if (!s_buff)
		s_buff = ft_strdup("");
	if (ft_read(fd, &buf, &s_buff, &line) == 0 && *line == '\0')
	{
		ft_free(line);
		return (NULL);
	}
	return (line);
}

int	ft_read(int fd, char **buf, char **s_buff, char **line)
{
	int		ret;
	char	*temp;

	ret = 1;
	while (!ft_strchr(*s_buff, '\n') && ret)
	{
		ret = read(fd, *buf, BUFFER_SIZE);
		(*buf)[ret] = '\0';
		temp = *s_buff;
		*s_buff = ft_strjoin(*s_buff, *buf);
		ft_free(temp);
	}
	ft_free(*buf);
	ft_get_line(line, s_buff);
	return (ret);
}

char	*ft_get_line(char **line, char **s_buff)
{
	char	*tmp;
	int		ret;

	ret = 0;
	tmp = *s_buff;
	while ((*s_buff)[ret] != '\n' && (*s_buff)[ret] != '\0')
		ret++;
	if (ft_strchr(*s_buff, '\n'))
	{
		*line = ft_substr(*s_buff, 0, ret + 1);
		*s_buff = ft_strdup(*s_buff + ret + 1);
	}
	else
	{
		*line = ft_strdup(tmp);
		*s_buff = NULL;
	}
	ft_free(tmp);
	return (*line);
}
