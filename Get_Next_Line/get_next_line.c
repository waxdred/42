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

#include "get_next_line.h"

void	*ft_start_line(char **line, char *s_buf)
{
	int	len;
	int	i;
	char	*dest;

	len = ft_strlen(s_buf) + 1;
	dest = (char *)ft_memalloc(len);
	if (!dest)
		return (NULL);
	free(*line);
	dest = (char *)ft_memmove(dest, s_buf, len);
	free(s_buf);
	return (dest);
}

void    *ft_complet_line_end(char **line, char *s_buf, char *buf)
{
}

void	*ft_complet_line(char **line, char *s_buf, char *buf)
{
	int	index;
	int 	size;
	int	i;
	char	*dest;

	index = ft_strichr(buf, '\n');
	if (index == -1)
	{
		size = ft_strlen(*line) + BUFFER_SIZE + 1;
		dest = (char *)ft_memalloc(size);
		if (!dest)
			return (NULL);
		dest = (char *)ft_memmove(dest, *line, ft_strlen(*line));
		i = 0;
		while (dest[i])
			i++;
		while (*buf)
		{
			dest[i++] = *buf++;
		}
		free(*line);
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*s_buf;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	int		ret;

	if ( fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)ft_memalloc(1);
	if (!line)
		return (NULL);
	if (s_buf)
		line = ft_start_line(&line, s_buf);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = 0;
		line = ft_complet_line(&line, s_buf, buf);
		if (ft_strichr(buf, '\n') != -1)
		{
			line = ft_complet_line_end(&line, s_buf, buf);
			return (line);
		}
	}
	return (NULL);
}
