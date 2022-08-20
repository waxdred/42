/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:37:26 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/09 05:44:15 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_exec_raycast(t_cub *cube, t_ray *ray, int *color)
{
	t_wall	*w;

	init_pos_wall(ray, &cube->player, 0, color);
	ray_horizontal(cube, &cube->player, ray);
	ray_vertical(cube, &cube->player, ray);
	init_distance(ray);
	v_distance(ray, *color);
	h_distance(ray, *color, &cube->player);
	ray->last_dir = (long)ft_dir_wall(ray);
	if (ray->last_mp != ray->mp || ray->last_dir != ray->new_dir)
	{
		w = cube->walls;
		while (w && w->next)
			w = w->next;
		if (w)
			w->next = ft_track(ft_get_wall_size(ray, &cube->player),
					&(cube->track));
		else
			cube->walls = ft_track(ft_get_wall_size(ray, &cube->player),
					&(cube->track));
		ray->last_mp = ray->mp;
		ray->new_dir = ray->last_dir;
	}
}
