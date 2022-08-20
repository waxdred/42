/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:32:14 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/09 04:32:19 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

double	deg_rad(int a)
{
	return (a * M_PI / 180.0);
}

double	fix_angle(float a)
{
	if (a < 0)
		a += 2 * PI;
	if (a > 2 * PI)
		a -= 2 * PI;
	return (a);
}

double	distance(float ax, float ay, float bx, float by)
{
	return (sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay))));
}

double	ft_angle_from_vectors(t_pos *v1, t_pos *v2)
{
	double	dot;

	dot = v1->x * v2->x + v1->y * v2->y;
	if (v1->x * v2->y > v2->x * v1->y)
		return (acos(dot / (sqrt(v1->x * v1->x + v1->y * v1->y)
					* sqrt(v2->x * v2->x + v2->y * v2->y))));
	return (-1. * acos(dot / (sqrt(v1->x * v1->x + v1->y * v1->y)
				* sqrt(v2->x * v2->x + v2->y * v2->y))));
}

size_t	ft_get_dist_max(t_cub *c)
{
	if (c->x_map > c->y_map)
		return (c->x_map);
	return (c->y_map);
}
