/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:53:36 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/10 17:38:47 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	ft_draw_dx_img(t_draw *draw, t_line *line, t_texture *text)
{
	while (draw->i <= draw->d_x)
	{
		if (line->x0 >= 0 && line->y0 >= 0 && line->x0 < text->x_xpm
			&& line->y0 < text->y_xpm)
			text->tab[line->y0][line->x0].i = (unsigned int)line->color;
		draw->i++;
		line->x0 += draw->x_incr;
		draw->ex -= draw->dy;
		if (draw->ex < 0)
		{
			line->y0 += draw->y_incr;
			draw->ex += draw->dx;
		}
	}
}

static void	ft_draw_rect_img(t_draw *draw, t_line *line, t_texture *text)
{
	int	k;

	while (draw->i <= draw->ex)
	{
		k = 0;
		while (k <= draw->ey)
		{
			if (line->x0 + draw->i < text->x_xpm && line->y0 + k < text->y_xpm
				&& line->x0 + draw->i >= 0 && line->y0 + k >= 0)
				text->tab[draw->i + (line->y0 + k)][line->x0].i
					= (unsigned int)line->color;
			if (line->x0 + draw->i < text->x_xpm
				&& line->y0 + k + 1 < text->y_xpm
				&& line->x0 + draw->i >= 0 && line->y0 + k + 1 >= 0)
				text->tab[line->y0 + k + 1][line->x0 + draw->i].i
					= (unsigned int)line->color;
			k += 2;
		}
		draw->i++;
	}
}

static void	ft_draw_dy_img(t_draw *draw, t_line *line, t_texture *text)
{
	while (draw->i <= draw->d_y)
	{
		if (line->x0 < text->x_xpm && line->y0 < text->y_xpm
			&& line->x0 >= 0 && line->y0 >= 0)
			text->tab[line->y0][line->x0].i = (unsigned int)line->color;
		draw->i++;
		line->y0 += draw->y_incr;
		draw->ey -= draw->dx;
		if (draw->ey < 0)
		{
			line->x0 += draw->x_incr;
			draw->ey += draw->dy;
		}
	}
}

void	ft_draw_line_img(t_line *line, int type, t_texture *text)
{
	t_draw	draw;

	ft_init_draw(&draw, line, type);
	if (type == LINE && draw.d_x > draw.d_y)
		ft_draw_dx_img(&draw, line, text);
	if (type == LINE && draw.d_x < draw.d_y)
		ft_draw_dy_img(&draw, line, text);
	if (type == RECT)
		ft_draw_rect_img(&draw, line, text);
}
