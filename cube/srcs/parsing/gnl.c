/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:22:34 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/09 05:22:38 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static ssize_t	ft_is_nl(char *buf, ssize_t len)
{
	ssize_t	i;

	i = 0;
	while (i < len)
	{
		if (buf[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

static char	*ft_get_line(char *buff)
{
	size_t	i;
	size_t	pos[2];
	char	*ret;

	i = 0;
	while (i < BUFFER_SIZE + 1 && buff[i] == 0)
		++i;
	pos[0] = i;
	while (i < BUFFER_SIZE + 1 && buff[i] != '\n' && buff[i] != 0)
		++i;
	pos[1] = i + 1;
	if (pos[1] > BUFFER_SIZE + 1)
		return (NULL);
	ret = malloc((pos[1] - pos[0] + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = pos[0];
	while (i < pos[1])
	{
		ret[i - pos[0]] = buff[i];
		buff[i] = 0;
		++i;
	}
	ret[i - pos[0]] = '\0';
	return (ret);
}

static size_t	ft_str_len(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_str_join_lines(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*ret;

	len_s1 = ft_str_len(s1);
	len_s2 = ft_str_len(s2);
	ret = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		ret[i] = s1[i];
		++i;
	}
	while (i < len_s1 + len_s2)
	{
		ret[i] = s2[i - len_s1];
		++i;
	}
	ret[i] = '\0';
	free(s1);
	free(s2);
	return (ret);
}

char	*ft_gnl(int fd)
{
	static char	buff[MAX_FD][BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	ssize_t		len_buff;
	int			eol;

	if ((fd < 3 && fd != 0) || BUFFER_SIZE < 1 || fd > MAX_FD - 1)
		return (NULL);
	eol = ft_is_nl(buff[fd], BUFFER_SIZE + 1);
	line = ft_get_line(buff[fd]);
	if (line && eol != -1)
		return (line);
	len_buff = read(fd, buff[fd], BUFFER_SIZE);
	if (len_buff == 0)
		return (line);
	while (len_buff > 0)
	{
		eol = ft_is_nl(buff[fd], len_buff + 1);
		tmp = ft_get_line(buff[fd]);
		line = ft_str_join_lines(line, tmp);
		if (eol != -1)
			return (line);
		len_buff = read(fd, buff[fd], BUFFER_SIZE);
	}
	return (line);
}
