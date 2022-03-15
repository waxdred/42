
#include "../includes/cube.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 940536
#endif

char	*ft_get_line(char **s_buf, char **line)
{
	char	*tmp;
	int	index;

	tmp = *s_buf;
	index = ft_strichr(*s_buf, '\n');
	if (index > -1)
	{
		*line = ft_strndup(*s_buf, index + 1);
		*s_buf = ft_strndup(*s_buf + index + 1, ft_strlen(*s_buf) - index);
	}
	else
	{
		*line = ft_strndup(*s_buf, ft_strlen(*s_buf));
		*s_buf = NULL;
	}
	free(tmp);
	return (*line);
}

int	ft_read(int fd, char **s_buf, char **buf, char **line)
{
	char	*tmp;
	int	ret;

	ret = 1;
	while (ft_strichr(*s_buf, '\n') < 0 && ret)
	{
		ret = read(fd, *buf, BUFFER_SIZE);
		(*buf)[ret] = '\0';
		tmp = *s_buf;
		*s_buf = ft_strjoin(*s_buf, *buf);
		free(tmp);
	}
	free(*buf);
	ft_get_line(s_buf, line);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*s_buf = NULL;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
		return (NULL);
	if (read(fd, buf, 0) < 0)
	{
		free(buf);
		return (NULL);
	}
	if (!s_buf)
		s_buf = ft_strndup("", 0);
	if (ft_read(fd, &s_buf, &buf, &line) == 0 && *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
