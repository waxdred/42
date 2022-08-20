/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start_walls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:12:26 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/18 23:28:52 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	ft_init_part(t_wall *w)
{
	if (w->r_dist > w->next->l_dist && w->next->origin.x - w->origin.x > 0)
		w->end = (size_t)(w->next->origin.x - w->origin.x) + 1;
	else if (w->r_dist < w->next->l_dist
		&& ((w->origin.x + w->width_img) - w->next->origin.x) > 1.)
		w->next->start = (size_t)((w->origin.x + w->width_img)
				- w->next->origin.x) - 1;
}

void	ft_init_start_walls(t_wall *w)
{
	if (w)
		w->start = 0;
	while (w)
	{
		w->end = w->width_img + 1;
		if (w->origin.x < 0. && w->start < (size_t)(-1. * w->origin.x))
			w->start = (size_t)(-1. * w->origin.x);
		if (w->origin.x + w->width_img > X_WIN)
			w->end = X_WIN - w->origin.x + 1;
		if (w->origin.x > X_WIN)
			w->end = 0;
		if (w->next)
		{
			w->next->start = 0;
			if (w->origin.x + w->width_img > w->next->origin.x)
				ft_init_part(w);
		}
		w = w->next;
	}
}
