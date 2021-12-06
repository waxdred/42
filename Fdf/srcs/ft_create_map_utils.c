/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:50:18 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/05 19:50:18 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_count(char *argv, t_env *fdf)
{
	char	*line;
	int		fd;

	fd = (open(argv, O_RDONLY));
	if (fd == -1)
	{
		perror("File not found\n");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	fdf->map.nblin++;
	fdf->map.nbcol = ft_count_words_sep(line, ' ');
	if (line)
		free(line);
	line = get_next_line(fd);
	while (line)
	{
		fdf->map.nblin++;
		free(line);
		line = get_next_line(fd);
	}
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

int	ft_count_sep(char *line, int c)
{
	int	i;
	int	len;
	int	check;

	i = 0;
	len = 0;
	check = 0;
	while (line[i])
	{
		if (line[i] == c)
			check = 1;
		if (check == 0)
		{
			len++;
			check = 1;
		}
		i++;
	}
	return (len);
}
