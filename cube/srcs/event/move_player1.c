/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:44:12 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/20 22:58:49 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_init_collision(t_col *col, t_cub *cube)
{
	col->xo = 0;
	col->yo = 0;
	col->ipx = cube->player.pos.x / 64;
	col->ipy = cube->player.pos.y / 64;
	if (cube->player.dp_x < 0)
		col->xo = -HIT_BOX;
	else
		col->xo = HIT_BOX;
	if (cube->player.dp_y < 0)
		col->yo = -HIT_BOX;
	else
		col->yo = HIT_BOX;
	col->ipx_add_xo = (cube->player.pos.x + col->xo) / SQUARES;
	col->ipy_add_yo = (cube->player.pos.y + col->yo) / SQUARES;
	col->ipx_sub_xo = (cube->player.pos.x - col->xo) / SQUARES;
	col->ipy_sub_yo = (cube->player.pos.y - col->yo) / SQUARES;
	col->r_col = col->ipy_add_yo * cube->x_map + col->ipx;
	col->l_col = col->ipy_sub_yo * cube->x_map + col->ipx;
	col->u_col = col->ipy * cube->x_map + col->ipx_add_xo;
	col->d_col = col->ipy * cube->x_map + col->ipx_sub_xo;
}

void	ft_init_collision_door(t_col *col, t_cub *cube)
{
	col->xo = 0;
	col->yo = 0;
	col->ipx = cube->player.pos.x / 64;
	col->ipy = cube->player.pos.y / 64;
	if (cube->player.dp_x < 0)
		col->xo = -(HIT_BOX * 2);
	else
		col->xo = HIT_BOX * 2;
	if (cube->player.dp_y < 0)
		col->yo = -(HIT_BOX * 2);
	else
		col->yo = (HIT_BOX * 2);
	col->ipx_add_xo = (cube->player.pos.x + col->xo) / SQUARES;
	col->ipy_add_yo = (cube->player.pos.y + col->yo) / SQUARES;
	col->ipx_sub_xo = (cube->player.pos.x - col->xo) / SQUARES;
	col->ipy_sub_yo = (cube->player.pos.y - col->yo) / SQUARES;
}

int8_t	ft_ft(t_cub *c, t_col col, int8_t ret)
{
	if ((!ret && (ft_strchr("12", c->s_map[col.l_col])
				&& ft_strchr("12", c->s_map[col.u_col])))
		|| (ft_strchr("12", c->s_map[col.r_col])
			&& ft_strchr("12", c->s_map[col.d_col])))
		return (1);
	if ((!ret && (ft_strchr("12", c->s_map[col.l_col])
				&& ft_strchr("12", c->s_map[col.r_col])))
		|| (ft_strchr("12", c->s_map[col.d_col])
			&& ft_strchr("12", c->s_map[col.u_col])))
		return (1);
	if ((!ret && (ft_strchr("12", c->s_map[col.l_col])
				&& ft_strchr("12", c->s_map[col.d_col])))
		|| (ft_strchr("12", c->s_map[col.r_col])
			&& ft_strchr("12", c->s_map[col.u_col])))
		return (1);
	return (0);
}

int	ft_open_door(t_cub *cube)
{
	t_col	col;

	ft_init_collision_door(&col, cube);
	if (cube->s_map[col.ipy * cube->x_map + col.ipx_add_xo] == '2')
		cube->s_map[col.ipy * cube->x_map + col.ipx_add_xo] = '3';
	if (cube->s_map[col.ipy_add_yo * cube->x_map + col.ipx] == '2')
		cube->s_map[col.ipy_add_yo * cube->x_map + col.ipx] = '3';
	ft_reload(cube);
	return (0);
}

int	ft_close_door(t_cub *cube)
{
	t_col	col;
	long	x;
	long	y;

	x = cube->player.pos.x / 64;
	y = cube->player.pos.y / 64;
	ft_init_collision_door(&col, cube);
	if (cube->s_map[col.ipy * cube->x_map + col.ipx_add_xo] == '3'
		&& cube->map[y][x] != 3)
		cube->s_map[col.ipy * cube->x_map + col.ipx_add_xo] = '2';
	if (cube->s_map[col.ipy_add_yo * cube->x_map + col.ipx] == '3'
		&& cube->map[y][x] != 3)
		cube->s_map[col.ipy_add_yo * cube->x_map + col.ipx] = '2';
	ft_reload(cube);
	return (0);
}
