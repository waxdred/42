/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:45:26 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/07 18:46:30 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

static char	*ft_complet_line(char *line, char *buf, char **s_buf)
{
	int	index;
	int	len;

	index = ft_strichr(buf, '\n');
	if (index == -1)
		line = ft_strldup(buf, BUFFER_SIZE + 1);
	else
	{
		line = ft_strldup(buf, index + 1);
		*s_buf = ft_stredup(buf, index + 1);
	}
	return (line);
}

char	*get_next_line(int *fd)
{
	static	char	*s_buf;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	static int	ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (s_buf)
		line = ft_strdup(s_buf);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[BUFFER_SIZE] = 0;
		tmp = ft_complet_line(line, buf, &s_buf);
		line = ft_strjoin(line, tmp);
		ft_free(tmp);
		if (ft_strichr((char *)line, '\n') >= 0)
			return (line);
	}
	free(s_buf);
	return (line);
}
