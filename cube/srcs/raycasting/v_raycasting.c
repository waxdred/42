/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_raycasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:35:12 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/09 05:42:26 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	v_get_pos_tan(t_cub *cube, t_player *p, t_ray *ray)
{
	if (ray->ra > P2 && ray->ra < P3)
	{
		ray->rx = (((long)p->pos.x >> 6) << 6) - 0.0001;
		ray->ry = (p->pos.x - ray->rx) * ray->tans + p->pos.y;
		ray->xo = -SQUARES;
		ray->yo = -ray->xo * ray->tans;
		ray->left = 1;
	}
	if (ray->ra < P2 || ray->ra > P3)
	{
		ray->rx = (((long)p->pos.x >> 6) << 6) + SQUARES;
		ray->ry = (p->pos.x - ray->rx) * ray->tans + p->pos.y;
		ray->xo = SQUARES;
		ray->yo = -ray->xo * ray->tans;
		ray->right = 1;
	}
	if (ray->ra == 0 || ray->ra == PI)
	{
		ray->rx = p->pos.x;
		ray->ry = p->pos.y;
		ray->dof = cube->r_dist;
	}
}

void	v_init_horizontal(t_cub *cube, t_player *p, t_ray *ray)
{
	ray->v_door = 0;
	ray->dof = 0;
	ray->dis_v = 100000;
	ray->vx = p->pos.x;
	ray->vy = p->pos.y;
	ray->tans = -tan(ray->ra);
	v_get_pos_tan(cube, p, ray);
}

void	ray_vertical(t_cub *cube, t_player *p, t_ray *ray)
{
	v_init_horizontal(cube, p, ray);
	while (ray->dof < (long)cube->r_dist)
	{
		ray->mx = (long)(ray->rx) >> 6;
		ray->my = (long)(ray->ry) >> 6;
		ray->vmp = (long)ray->my * cube->x_map + ray->mx;
		if (ray->vmp > 0 && ray->vmp < (long)(cube->x_map * cube->y_map)
				&& ft_strchr("12", cube->s_map[ray->vmp]))
		{
			if (cube->s_map[ray->vmp] == '2')
				ray->v_door = 1;
			ray->vx = ray->rx;
			ray->vy = ray->ry;
			ray->dis_v = distance(p->pos.x, p->pos.y, ray->vx, ray->vy);
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
