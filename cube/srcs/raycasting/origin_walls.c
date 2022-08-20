/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   origin_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:29:09 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/19 20:02:08 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

double	ft_get_origin(double angle, double dist, const double half_angle)
{
	double			width_1;
	double			width_2;
	double			dist_perpendicular;

	if (angle == half_angle)
		return (X_WIN >> 1);
	dist_perpendicular = cos(angle - half_angle) * dist;
	width_1 = sin(angle - half_angle) * dist;
	width_2 = tan(half_angle) * dist_perpendicular;
	if (angle - half_angle < -P2)
		return ((width_2 - width_1) / width_2 * (X_WIN >> 1));
	if (angle < half_angle)
		return ((width_2 + width_1) / width_2 * (X_WIN >> 1));
	return (width_1 / width_2 * (X_WIN >> 1) + (X_WIN >> 1));
}

static void	ft_get_x_inter(t_wall *w, t_ray *last_r)
{
	double	ratio;
	double	ratio_intern;

	if (w->dir == NO || w->dir == SO)
		ratio_intern = fabs(last_r->rx - w->col1_x) / SQUARES;
	else
		ratio_intern = fabs(last_r->ry - w->col1_y) / SQUARES;
	w->width_img = (double)X_WIN / ratio_intern;
	if (w->dir == NO || w->dir == SO)
		ratio = fabs(w->l_extrem.x - w->col1_x) / SQUARES;
	else
		ratio = fabs(w->l_extrem.y - w->col1_y) / SQUARES;
	w->origin.x = -1. * (w->width_img * ratio);
}

static void	ft_get_x_left(t_wall *w, t_player *p, const double half_angle)
{
	double	ratio;

	w->r_dist = distance(p->pos.x, p->pos.y, w->r_extrem.x, w->r_extrem.y)
		* cos(w->r_angle - half_angle);
	w->width_img = ft_get_origin(w->r_angle, w->r_dist, half_angle);
	if (w->dir == NO || w->dir == SO)
		ratio = fabs(w->col1_x - w->r_extrem.x) / SQUARES;
	else
		ratio = fabs(w->col1_y - w->r_extrem.y) / SQUARES;
	w->l_dist = distance(p->pos.x, p->pos.y, w->l_extrem.x, w->l_extrem.y)
		* cos(w->l_angle - half_angle);
	if (w->l_angle - half_angle > -P2 && w->l_dist > w->r_dist)
		w->origin.x = ft_get_origin(w->l_angle, w->l_dist, half_angle);
	else
		w->origin.x = -1. * (w->width_img * (1. - ratio) / ratio);
	w->width_img -= w->origin.x;
}

static void	ft_get_x_right(t_wall *w, t_player *p, t_ray *last_r,
	const double half_angle)
{
	double	ratio;

	w->l_dist = distance(p->pos.x, p->pos.y, w->l_extrem.x, w->l_extrem.y)
		* cos(w->l_angle - half_angle);
	w->origin.x = ft_get_origin(w->l_angle, w->l_dist, half_angle);
	if (w->dir == NO || w->dir == SO)
		ratio = fabs(w->l_extrem.x - last_r->rx) / SQUARES;
	else
		ratio = fabs(w->l_extrem.y - last_r->ry) / SQUARES;
	w->r_dist = distance(p->pos.x, p->pos.y, w->r_extrem.x, w->r_extrem.y)
		* cos(w->r_angle - half_angle);
	if (w->r_angle - half_angle < P2 && w->l_dist < w->r_dist)
		w->width_img = ft_get_origin(w->r_angle, w->r_dist, half_angle)
			- w->origin.x;
	else
	{
		w->width_img = (((double)X_WIN - w->origin.x) * (1. - ratio) / ratio);
		w->width_img += ((double)X_WIN - w->origin.x);
	}
}

void	ft_get_x_dims(t_wall *w, t_player *p, t_ray *last_r,
	const double half_angle)
{
	if (w->l_angle < 0. && w->r_angle > RAD * DOF)
		ft_get_x_inter(w, last_r);
	else if (w->l_angle < 0. && w->r_angle <= RAD * DOF)
		ft_get_x_left(w, p, half_angle);
	else if (w->l_angle >= 0. && w->r_angle > RAD * DOF)
		ft_get_x_right(w, p, last_r, half_angle);
}
