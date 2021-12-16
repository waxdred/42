/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:52:29 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/05 17:07:57 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_setmax(t_env *fdf)
{
	fdf->map.max = ft_max(fdf->map.map[fdf->map.posy], fdf->map.nblin);
	if (fdf->map.max > fdf->map.pad)
		fdf->map.pad = fdf->map.max;
}

static void	ft_split_line(t_env *fdf, char **split_line)
{
	fdf->map.map[fdf->map.posy][fdf->map.posx]
		= ft_atoi(split_line[fdf->map.posx]);
	free(split_line[fdf->map.posx]);
	fdf->map.posx++;
}

int	ft_complet_map(int fd, t_env *fdf)
{
	char	*line;
	char	**split_line;

	fdf->map.map = ft_tabnew_two(fdf->map.nbcol, fdf->map.nblin);
	if (!fdf->map.map)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	while (line)
	{
		fdf->map.posx = 0;
		split_line = ft_split(line, ' ');
		while (split_line[fdf->map.posx] != NULL)
			ft_split_line(fdf, split_line);
		ft_setmax(fdf);
		free(split_line);
		free(line);
		line = get_next_line(fd);
		fdf->map.posy++;
	}
	return (0);
}

int	ft_create_map(char *argv, t_env *fdf)
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
