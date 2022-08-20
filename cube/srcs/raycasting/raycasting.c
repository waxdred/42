/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <x@student.42lyon.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:37:26 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/20 19:38:44 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_distance(t_ray *ray)
{
	if (ray->dis_h < 0)
		ray->dis_hn = ray->dis_h * -1.;
	else
		ray->dis_hn = ray->dis_h;
	if (ray->dis_v < 0)
		ray->dis_vn = ray->dis_v * -1.;
	else
		ray->dis_vn = ray->dis_v;
}

void	v_distance(t_ray *ray, int color)
{
	if (color < 0)
		return ;
	if (ray->dis_vn < ray->dis_hn)
	{
		ray->rx = ray->vx;
		ray->ry = ray->vy;
		ray->dis_t = ray->dis_v;
		ray->mp = ray->vmp;
		ray->door = ray->v_door;
		if (ray->left)
		{
			ray->m_pos = (long)(ray->ry) % 64L;
			ray->m_pos = 63L - ray->m_pos;
			color = 0x800080;
		}
		if (ray->right)
		{
			ray->m_pos = (long)(ray->ry) % 64L;
			color = 0x008000;
		}
	}
}

void	h_distance(t_ray *ray, int color, t_player *p)
{
	if (color < 0)
		return ;
	if (ray->dis_hn < ray->dis_vn)
	{
		ray->rx = ray->hx;
		ray->ry = ray->hy;
		ray->dis_t = ray->dis_h;
		ray->mp = ray->hmp;
		ray->door = ray->h_door;
		if (ray->up)
		{
			ray->m_pos = (long)(ray->rx) % 64L;
			color = 0xFFFF000;
		}
		if (ray->down)
		{
			ray->m_pos = (long)(ray->rx) % 64L;
			ray->m_pos = 63 - ray->m_pos;
			color = 0xFF0000;
		}
	}
	ray->ca = fix_angle(p->pa - ray->ra);
}

void	init_pos_wall(t_ray *ray, t_player *p, int8_t b, int *color)
{
	static const double	half_angle = RAD * (DOF >> 1);

	if (!b)
	{
		ray->up = 0;
		ray->down = 0;
		ray->left = 0;
		ray->right = 0;
	}
	else if (b)
	{
		ray->ra = fix_angle(p->pa - half_angle);
		ray->ra_base.x = cos(ray->ra) * SQUARES;
		ray->ra_base.y = sin(ray->ra) * SQUARES;
		ray->last_dir = -1L;
		*color = 0x00FFFF;
	}
}

void	draw_ray_3d(t_cub *cube, t_player *p)
{
	t_ray	ray;
	int		color;

	ft_bzero(&ray, sizeof(t_ray));
	init_pos_wall(&ray, p, 1, &color);
	while (ray.r < DOF)
	{
		ft_exec_raycast(cube, &ray, &color);
		ft_start_draw(&(cube->line), p->pos.x * cube->scale, p->pos.y
			* cube->scale, 0xFF0000);
		ft_end_draw(&(cube->line), ray.rx * cube->scale, ray.ry * cube->scale);
		ft_draw_line_img(&(cube->line), LINE, &(cube->player_mini_map));
		ray.r++;
		if (ray.r < DOF)
			ray.ra = fix_angle(ray.ra + RAD);
	}
	ft_correc_extern_wall(cube, &ray, p);
}
