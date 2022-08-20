/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:57:51 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/09 05:38:53 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_init_draw(t_draw *draw, t_line *line, int type)
{
	draw->i = 0;
	draw->ex = abs(line->x1 - line->x0);
	draw->ey = abs(line->y1 - line->y0);
	draw->dx = 2 * draw->ex;
	draw->dy = 2 * draw->ey;
	draw->d_x = draw->ex;
	draw->d_y = draw->ey;
	draw->x_incr = 1;
	draw->y_incr = 1;
	if (line->x0 > line->x1)
		draw->x_incr = -1;
	if (line->y0 > line->y1)
		draw->y_incr = -1;
	if (type == RECT)
	{
		draw->x_rect = abs(line->x1 - line->x0);
		draw->y_rect = abs(line->y1 - line->y0);
	}
}

int	ft_start_draw(t_line *line, int x0, int y0, int color)
{
	line->x0 = x0;
	line->y0 = y0;
	line->color = color;
	return (1);
}

int	ft_end_draw(t_line *line, int x0, int y0)
{
	line->x1 = x0;
	line->y1 = y0;
	return (1);
}
