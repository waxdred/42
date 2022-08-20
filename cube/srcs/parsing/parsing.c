/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <x@student.42lyon.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:22:24 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/14 06:33:37 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int8_t	ft_pars_file(t_cub *cub, int fd)
{
	char	*gnl;

	gnl = ft_gnl(fd);
	while (gnl)
	{
		if (ft_pars_line(cub, gnl))
		{
			free(gnl);
			return (1);
		}
		free(gnl);
		gnl = ft_gnl(fd);
	}
	return (0);
}

static int8_t	ft_check_meta(t_cub *cub)
{
	if (!(cub->map) || ft_check_map(cub))
	{
		ft_putstr_fd("Error\nParsing: map informations\n", 2);
		return (1);
	}
	if (cub->check_parsing != 0b1111111)
	{
		ft_putstr_fd("Error\nParsing: file informations (texture, color or map \
			missing)\n", 2);
		return (1);
	}
	return (0);
}

static int8_t	ft_check_file(t_cub *cub, const char *file, int fd)
{
	if (fd < 0)
	{
		ft_putstr_fd("Error\nParsing map: ", 2);
		perror(file);
		free(cub->track);
		return (1);
	}
	return (0);
}

int8_t	ft_parsing(t_cub *cub, const char *file)
{
	int		fd;
	size_t	len[2];

	len[0] = ft_strlen(EXT_MAP);
	len[1] = ft_strlen(file);
	if (len[1] < len[0] || !ft_str_start_with((char *)(file + len[1] - len[0]),
		EXT_MAP))
	{
		ft_putstr_fd("Error\nName of the file must have the .cub extension\n",
			2);
		ft_track_free_all(&(cub->track));
		return (1);
	}
	fd = open(file, O_RDONLY);
	if (ft_check_file(cub, file, fd))
		return (1);
	if (ft_pars_file(cub, fd) || ft_check_meta(cub) || ft_check_texture(cub))
	{
		close(fd);
		ft_track_free_all(&(cub->track));
		return (1);
	}
	close(fd);
	return (0);
}
