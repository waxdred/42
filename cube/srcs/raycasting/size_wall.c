/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <x@student.42lyon.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:52:35 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/20 19:38:56 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_dir	ft_dir_wall(t_ray *r)
{
	if (r->up && r->dis_hn < r->dis_vn)
		return (NO);
	if (r->down && r->dis_hn < r->dis_vn)
		return (SO);
	if (r->right && r->dis_vn < r->dis_hn)
		return (EA);
	if (r->left && r->dis_vn < r->dis_hn)
		return (WE);
	return (-1);
}

void	ft_correc_one_extern_wall(t_wall *w, t_wall *prec, t_ray *last_r,
	const double half_angle)
{
	double			ratio_side;

	if (w->l_angle < 0. && !prec)
	{
		w->r_heigth = SQUARES * HEIGHT / w->r_dist * Y_WIN;
		w->l_dist = w->inter_dist * cos(-half_angle);
		ratio_side = fabs(ft_get_origin(0., w->l_dist, half_angle)
				- w->origin.x) / w->width_img;
		w->l_heigth = SQUARES * HEIGHT / w->l_dist * Y_WIN;
		w->l_heigth = (w->l_heigth - w->r_heigth) * ratio_side
			/ (1. - ratio_side) + w->l_heigth;
	}
	else if (w->r_angle > RAD * DOF && !(w->next))
	{
		w->l_heigth = SQUARES * HEIGHT / w->l_dist * Y_WIN;
		w->r_dist = last_r->dis_t * cos(half_angle);
		ratio_side = fabs(w->width_img + w->origin.x
				- ft_get_origin(RAD * DOF, w->r_dist, half_angle))
			/ w->width_img;
		w->r_heigth = SQUARES * HEIGHT / w->r_dist * Y_WIN;
		w->r_heigth = (w->r_heigth - w->l_heigth) * ratio_side
			/ (1. - ratio_side) + w->r_heigth;
	}
}

static void	ft_correc_zoom_extern_wall(t_wall *w, t_ray *last_r,
	const double half_angle)
{
	double	ratio_side;

	w->l_dist = w->inter_dist * cos(-half_angle);
	w->l_heigth = SQUARES * HEIGHT / w->l_dist * Y_WIN;
	w->r_dist = last_r->dis_t * cos(half_angle);
	w->r_heigth = SQUARES * HEIGHT / w->r_dist * Y_WIN;
	ratio_side = fabs(w->l_angle) / (w->r_angle - w->l_angle);
	w->l_heigth = (w->l_heigth - w->r_heigth) * ratio_side
		/ (1. - ratio_side) + w->l_heigth;
	ratio_side = (w->r_angle - RAD * DOF) / (w->r_angle - w->l_angle);
	w->r_heigth = (w->r_heigth - w->l_heigth) * ratio_side
		/ (1. - ratio_side) + w->r_heigth;
}

void	ft_correc_extern_wall(t_cub *cub, t_ray *last_r, t_player *p)
{
	static const double	half_angle = RAD * (DOF >> 1);
	t_wall				*w;
	t_wall				*prec;

	w = cub->walls;
	prec = NULL;
	while (w)
	{
		if ((prec && w->next) || (w->l_angle >= 0. && w->r_angle <= RAD * DOF))
			ft_get_entire_wall(w, p, half_angle);
		else
		{
			ft_get_x_dims(w, p, last_r, half_angle);
			if (w->l_angle < 0. && w->r_angle > RAD * DOF && !(w->next)
				&& !prec)
				ft_correc_zoom_extern_wall(w, last_r, half_angle);
			else
				ft_correc_one_extern_wall(w, prec, last_r, half_angle);
			w->origin.y = (Y_WIN - fmax(w->l_heigth, w->r_heigth)) * 0.5;
		}
		prec = w;
		w = w->next;
	}
}

t_wall	*ft_get_wall_size(t_ray *ray, t_player *p)
{
	t_wall	*wall;

	wall = ft_memalloc(sizeof(t_wall));
	if (!wall)
		return (NULL);
	wall->door = ray->door;
	wall->dir = ft_dir_wall(ray);
	wall->inter_dist = ray->dis_t;
	wall->col1_x = ray->rx;
	wall->col1_y = ray->ry;
	ft_get_wall_extrem(wall, ray, wall->dir);
	ft_get_extrem_angles(wall, ray, p);
	return (wall);
}
