/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:44:12 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/20 23:02:50 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_rotate(t_cub *cube)
{
	if (cube->inter.key[AL])
	{
		cube->player.pa -= 0.05;
		if (cube->player.pa < 0)
			cube->player.pa += 2 * PI;
		cube->player.dp_x = cos(cube->player.pa) * 5;
		cube->player.dp_y = sin(cube->player.pa) * 5;
	}
	else if (cube->inter.key[AR])
	{
		cube->player.pa += 0.05;
		if (cube->player.pa > 2 * PI)
			cube->player.pa -= 2 * PI;
		cube->player.dp_x = cos(cube->player.pa) * 5;
		cube->player.dp_y = sin(cube->player.pa) * 5;
	}
	else
		return (1);
	ft_reload(cube);
	return (0);
}

int8_t	ft_move_z(t_cub *cube, t_col c)
{
	if (ft_strchr("12", cube->s_map[c.ipy_add_yo * cube->x_map + c.ipx_add_xo])
		&& !ft_strchr("12", cube->s_map[c.ipy * cube->x_map + c.ipx_add_xo])
		&& !ft_strchr("12", cube->s_map[c.ipy_add_yo * cube->x_map + c.ipx]))
		return (1);
	if (!ft_strchr("12", cube->s_map[c.ipy * cube->x_map + c.ipx_add_xo]))
		cube->player.pos.x += cube->player.dp_x * cube->player.speed;
	if (!ft_strchr("12", cube->s_map[c.ipy_add_yo * cube->x_map + c.ipx]))
		cube->player.pos.y += cube->player.dp_y * cube->player.speed;
	return (0);
}

int8_t	ft_move_s(t_cub *cube, t_col c)
{
	if (ft_strchr("12", cube->s_map[c.ipy_sub_yo * cube->x_map + c.ipx_sub_xo])
		&& !ft_strchr("12", cube->s_map[c.ipy * cube->x_map + c.ipx_sub_xo])
		&& !ft_strchr("12", cube->s_map[c.ipy_sub_yo * cube->x_map + c.ipx]))
		return (1);
	if (!ft_strchr("12", cube->s_map[c.ipy * cube->x_map + c.ipx_sub_xo]))
		cube->player.pos.x -= cube->player.dp_x * cube->player.speed;
	if (!ft_strchr("12", cube->s_map[c.ipy_sub_yo * cube->x_map + c.ipx]))
		cube->player.pos.y -= cube->player.dp_y * cube->player.speed;
	return (0);
}

int	ft_move(t_cub *cube)
{
	t_col	c;

	ft_init_collision(&c, cube);
	if (cube->inter.key[Z] || cube->inter.key[AU])
	{
		if (ft_move_z(cube, c))
			return (0);
	}
	else if (cube->inter.key[S] || cube->inter.key[AD])
	{
		if (ft_move_s(cube, c))
			return (0);
	}
	else
		return (1);
	ft_reload(cube);
	return (0);
}
