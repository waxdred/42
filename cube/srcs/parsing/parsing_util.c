/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:27:40 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/10 16:39:20 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	ft_get_pos_player(t_cub *cub, size_t x, size_t y)
{
	if (cub->map[y][x] == 'E')
		cub->player.pa = 0.;
	else if (cub->map[y][x] == 'N')
		cub->player.pa = P3;
	else if (cub->map[y][x] == 'W')
		cub->player.pa = PI;
	else if (cub->map[y][x] == 'S')
		cub->player.pa = P2;
	cub->map[y][x] = '0';
	cub->player.pos.x = (double)x;
	cub->player.pos.y = (double)y;
}

static int8_t	ft_check_component(t_cub *cub, char *component, size_t i,
	size_t j)
{
	if (!(*component))
		return (1);
	if (*component == ' ')
		*component = '1';
	if (ft_strchr(DIR_MAP, *component))
		ft_get_pos_player(cub, j, i);
	if (!ft_strchr(ALLOW_MAP, *component)
		|| ((!i || i == cub->y_map - 1) && *component != '1')
		|| ((!j || j == cub->x_map - 1) && *component != '1'))
		return (1);
	if (ft_strchr("23", *component) && !(cub->surface.door.file))
		return (1);
	return (0);
}

int8_t	ft_check_map(t_cub *cub)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < cub->y_map)
	{
		j = 0;
		while (j < cub->x_map)
		{
			if (ft_check_component(cub, &(cub->map[i][j]), i, j))
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}
