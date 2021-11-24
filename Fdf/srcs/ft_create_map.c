/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:52:29 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/20 00:52:29 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

int		ft_count(char *argv, t_env *fdf)
{
	char	*line;
	int		fd;

	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	fdf->map.nblin++;
	fdf->map.nbcol = ft_count_words_sep(line, ' ');
	if (line)
		free(line);
	while ((line = get_next_line(fd)))
	{
		fdf->map.nblin++;
		free(line);
	}
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

int		ft_complet_map(int fd, t_env *fdf)
{
	char	*line;
	char	**split_line;

	if (!(fdf->map.map = ft_tabnew_two(fdf->map.nbcol, fdf->map.nblin)))
		return (-1);
	while ((line = get_next_line(fd)))
	{
		fdf->map.posx = 0;
		split_line = ft_split(line, ' ');
		while (split_line[fdf->map.posx] != NULL)
		{
			fdf->map.map[fdf->map.posy][fdf->map.posx] = 
				ft_atoi(split_line[fdf->map.posx]);
			free(split_line[fdf->map.posx]);
			fdf->map.posx++;
		}
		fdf->map.max = ft_max(fdf->map.map[fdf->map.posy], fdf->map.nblin);
		if (fdf->map.max > fdf->map.pad)
			fdf->map.pad = fdf->map.max;
		free(split_line);
		free(line);
		fdf->map.posy++;
	}
	return (0);
}

int		ft_create_map(char *argv, t_env *fdf)
{
	int		fd;

	ft_count(argv, fdf);
	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	ft_complet_map(fd, fdf);
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}
