/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:22:06 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/09 05:22:08 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int8_t	ft_init_map(t_cub *cub, char *line)
{
	if (cub->map)
	{
		ft_putstr_fd("Error\nParsing: map: allready exist\n", 2);
		return (1);
	}
	cub->map = ft_track(ft_memalloc(2 * sizeof(char *)), &(cub->track));
	if (!(cub->map))
		return (ft_alloc_error());
	*(cub->map) = ft_track(ft_strdup(line), &(cub->track));
	if (!(*(cub->map)))
		return (ft_alloc_error());
	return (0);
}

static int8_t	ft_add_line_map(t_cub *cub, char *line)
{
	char	**tmp;
	size_t	i;

	if (!(cub->map))
	{
		ft_putstr_fd("Error\nParsing: map: not exist\n", 2);
		return (1);
	}
	tmp = ft_track(ft_memalloc((cub->y_map + 1) * sizeof(char *)),
			&(cub->track));
	if (!tmp)
		return (ft_alloc_error());
	i = 0;
	while (cub->map[i])
	{
		tmp[i] = cub->map[i];
		++i;
	}
	tmp[i] = ft_track(ft_strdup(line), &(cub->track));
	if (!(tmp[i]))
		return (ft_alloc_error());
	ft_track_free(&(cub->track), cub->map);
	cub->map = tmp;
	return (0);
}

int8_t	ft_add_map(t_cub *cub, char *line)
{
	size_t	x;

	++(cub->y_map);
	x = ft_strlen(line);
	if (line[x - 1] == '\n')
	{
		line[x - 1] = '\0';
		--x;
	}
	if (x < 3 || (cub->y_map > 1 && x != cub->x_map))
	{
		ft_putstr_fd("Error\nParsing: map: bad size of dimension x\n", 2);
		return (1);
	}
	if (cub->y_map == 1)
	{
		cub->x_map = x;
		return (ft_init_map(cub, line));
	}
	return (ft_add_line_map(cub, line));
}

int	ft_map_in_string(t_cub *cube)
{
	size_t	d[3];

	ft_bzero(d, sizeof(size_t) * 3);
	cube->s_map = (char *)ft_memalloc(sizeof(char)
			* (cube->y_map * cube->x_map + 1));
	if (!cube->s_map)
		return (0);
	while (d[0] < cube->y_map)
	{
		d[1] = 0;
		while (d[1] < cube->x_map)
		{
			cube->s_map[d[2]++] = cube->map[d[0]][d[1]];
			d[1]++;
		}
		d[0]++;
	}
	ft_track(cube->s_map, &(cube->track));
	return (1);
}

int8_t	ft_check_pos_player(t_player *p)
{
	if (!p->pos.x && !p->pos.y)
	{
		ft_putstr_fd("Add position of the player\n", 2);
		return (0);
	}
	return (1);
}
