/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:06:57 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/19 23:25:04 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_init_player(t_cub *cube)
{
	cube->player.pos.x *= SQUARES;
	cube->player.pos.y *= SQUARES;
	cube->player.pos.x += (double)SQUARES / 2;
	cube->player.pos.y += (double)SQUARES / 2;
	cube->player.dp_x = cos(cube->player.pa) * 5;
	cube->player.dp_y = sin(cube->player.pa) * 5;
	cube->player.scale = 10;
	cube->player.speed = SPEED;
}

static void	condition_player_draw(t_cub *cube, t_player *p, int i, int j)
{
	if ((i + p->pos.x - (p->scale / 2)) * cube->scale
		< cube->player_mini_map.x_xpm
		&& (j + p->pos.y - (p->scale / 2)) * cube->scale
		< cube->player_mini_map.y_xpm
		&& (i + p->pos.x - (p->scale / 2)) * cube->scale >= 0
		&& (j + p->pos.y - (p->scale / 2)) * cube->scale >= 0)
		cube->player_mini_map.map[
			(int)((i + p->pos.x - (p->scale / 2)) * cube->scale)
			+ (int)((j + p->pos.y - (p->scale / 2)) * cube->scale)
			*cube->player_mini_map.x_xpm].i = 0x66ffff;
}

void	ft_player(t_cub *cube, t_player *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->scale)
	{
		j = 0;
		while (j < p->scale)
		{
			condition_player_draw(cube, p, i, j);
			j++;
		}
		i++;
	}
	ft_start_draw(&(cube->line), p->pos.x * cube->scale, p->pos.y
		* cube->scale, 0x80FFFF);
	ft_end_draw(&(cube->line), (p->pos.x + p->dp_x * 5) * cube->scale,
		(p->pos.y + p->dp_y * 5) * cube->scale);
	ft_draw_line_img(&(cube->line), LINE, &(cube->player_mini_map));
}
