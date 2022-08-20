/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_raycasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:36:10 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/09 05:42:40 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	h_get_pos_tan(t_cub *cube, t_player *p, t_ray *ray)
{
	if (ray->ra > PI)
	{
		ray->ry = (((long)p->pos.y >> 6) << 6) - 0.0001;
		ray->rx = (p->pos.y - ray->ry) * ray->tans + p->pos.x;
		ray->yo = -SQUARES;
		ray->xo = -ray->yo * ray->tans;
		ray->up = 1;
	}
	if (ray->ra < PI)
	{
		ray->ry = (((long)p->pos.y >> 6) << 6) + SQUARES;
		ray->rx = (p->pos.y - ray->ry) * ray->tans + p->pos.x;
		ray->yo = SQUARES;
		ray->xo = -ray->yo * ray->tans;
		ray->down = 1;
	}
	if (ray->ra == 0 || ray->ra == PI)
	{
		ray->rx = p->pos.x;
		ray->ry = p->pos.y;
		ray->dof = cube->r_dist;
	}
}

void	h_init_horizontal(t_cub *cube, t_player *p, t_ray *ray)
{
	ray->h_door = 0;
	ray->dof = 0;
	ray->dis_h = 100000;
	ray->hx = p->pos.x;
	ray->hy = p->pos.y;
	ray->tans = -1. / tan(ray->ra);
	h_get_pos_tan(cube, p, ray);
}

void	ray_horizontal(t_cub *cube, t_player *p, t_ray *ray)
{
	h_init_horizontal(cube, p, ray);
	while (ray->dof < (long)cube->r_dist)
	{
		ray->mx = (long)(ray->rx) >> 6;
		ray->my = (long)(ray->ry) >> 6;
		ray->hmp = (long)ray->my * cube->x_map + ray->mx;
		if (ray->hmp > 0 && ray->hmp < (long)(cube->x_map * cube->y_map)
				&& ft_strchr("12", cube->s_map[ray->hmp]))
		{
			if (cube->s_map[ray->hmp] == '2')
				ray->h_door = 1;
			ray->hx = ray->rx;
			ray->hy = ray->ry;
			ray->dis_h = distance(p->pos.x, p->pos.y, ray->hx, ray->hy);
			ray->dof = cube->r_dist;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof += 1;
		}
	}
}
