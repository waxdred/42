/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extremum_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:33:19 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/19 20:03:53 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	ft_get_wall_extrem_vertical(t_wall *w, t_ray *r, t_dir dir)
{
	w->l_extrem.y = (double)((long)r->ry);
	w->r_extrem.y = w->l_extrem.y;
	if (dir == NO)
	{
		w->l_extrem.x = (double)((long)(r->rx - r->m_pos));
		w->r_extrem.x = w->l_extrem.x + SQUARES;
	}
	else
	{
		w->l_extrem.x = (double)((long)(r->rx + r->m_pos));
		w->r_extrem.x = w->l_extrem.x - SQUARES;
	}
}

static void	ft_get_wall_extrem_horizontal(t_wall *w, t_ray *r, t_dir dir)
{
	w->l_extrem.x = (double)((long)r->rx);
	w->r_extrem.x = w->l_extrem.x;
	if (dir == EA)
	{
		w->l_extrem.y = (double)((long)(r->ry - r->m_pos));
		w->r_extrem.y = w->l_extrem.y + SQUARES;
	}
	else
	{
		w->l_extrem.y = (double)((long)(r->ry + r->m_pos));
		w->r_extrem.y = w->l_extrem.y - SQUARES;
	}
}

void	ft_get_wall_extrem(t_wall *w, t_ray *r, t_dir dir)
{
	if (dir == NO || dir == SO)
		ft_get_wall_extrem_vertical(w, r, dir);
	else
		ft_get_wall_extrem_horizontal(w, r, dir);
	if ((long)w->l_extrem.y % 2)
		w->l_extrem.y++;
	if ((long)w->l_extrem.x % 2)
		w->l_extrem.x++;
	if ((long)w->r_extrem.y % 2)
		w->r_extrem.y++;
	if ((long)w->r_extrem.x % 2)
		w->r_extrem.x++;
}

void	ft_get_extrem_angles(t_wall *w, t_ray *r, t_player *p)
{
	t_pos	left;
	t_pos	right;

	left.x = w->l_extrem.x - p->pos.x;
	left.y = w->l_extrem.y - p->pos.y;
	right.x = w->r_extrem.x - p->pos.x;
	right.y = w->r_extrem.y - p->pos.y;
	w->l_angle = ft_angle_from_vectors(&(r->ra_base), &(left));
	w->r_angle = ft_angle_from_vectors(&(r->ra_base), &(right));
}

void	ft_get_entire_wall(t_wall *w, t_player *p, const double half_angle)
{
	w->l_dist = distance(p->pos.x, p->pos.y, w->l_extrem.x, w->l_extrem.y)
		* cos(w->l_angle - half_angle);
	w->r_dist = distance(p->pos.x, p->pos.y, w->r_extrem.x, w->r_extrem.y)
		* cos(w->r_angle - half_angle);
	w->l_heigth = SQUARES * HEIGHT / w->l_dist * Y_WIN;
	w->r_heigth = SQUARES * HEIGHT / w->r_dist * Y_WIN;
	w->origin.y = (Y_WIN - fmax(w->l_heigth, w->r_heigth)) * 0.5;
	w->origin.x = ft_get_origin(w->l_angle, w->l_dist, half_angle);
	w->width_img = fabs(ft_get_origin(w->r_angle, w->r_dist, half_angle)
			- w->origin.x);
}
