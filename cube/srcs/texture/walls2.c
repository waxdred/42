/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <x@student.42lyon.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:16:57 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/20 19:38:14 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	ft_secure_on_x(t_draw_wall *dr, t_texture *text, size_t x,
	double *info[3])
{
	double	ratio_y;

	if (dr->wall->l_heigth < dr->wall->r_heigth)
	{
		ratio_y = (info[1][x] - info[0][x])
			/ fmax(dr->wall->l_heigth, dr->wall->r_heigth);
		dr->ratio[x] = (double)x * dr->ratio_x / ratio_y;
	}
	else
	{
		ratio_y = (info[1][(size_t)(dr->wall->width_img - (double)x - 1.)]
				- info[0][(size_t)(dr->wall->width_img - (double)x - 1.)])
			/ fmax(dr->wall->l_heigth, dr->wall->r_heigth);
		dr->ratio[x] = (double)x * dr->ratio_x * ratio_y;
	}
	if (dr->ratio[x] >= (double)text->x_xpm)
		dr->ratio[x] = (double)(text->x_xpm - 1);
	if (dr->ratio[x] < 0.)
		dr->ratio[x] = 0.;
}

static int	ft_get_ratio_x(t_draw_wall *dr, double *info[3], t_wall *wall,
	t_texture *text)
{
	size_t	x;

	dr->ratio = malloc(sizeof(double) * wall->end);
	if (!dr->ratio)
		return (1);
	dr->ratio_x = (double)text->x_xpm / wall->width_img;
	dr->wall = wall;
	x = wall->start;
	while (x < wall->end)
	{
		ft_secure_on_x(dr, text, x, info);
		++x;
	}
	return (0);
}

static void	ft_get_coordonate_wall(t_draw_wall *dr, t_wall *wall,
	double *info[3], t_texture *text)
{
	dr->x0 = (size_t)((double)dr->x + wall->origin.x);
	dr->y0 = (size_t)((double)dr->y + wall->origin.y);
	dr->x1 = (size_t)dr->ratio[dr->x];
	dr->y1 = (size_t)(((double)dr->y - info[0][dr->x]) * info[2][dr->x]);
	if ((double)dr->y > info[0][dr->x] && (double)dr->y < info[1][dr->x]
		&& dr->x0 < X_WIN && dr->y0 < Y_WIN && dr->y1 < (size_t)text->y_xpm
		&& dr->x1 < (size_t)text->x_xpm)
		dr->display[dr->y0][dr->x0].i = text->tab[dr->y1][dr->x1].i;
}

void	ft_fill_wall(t_cub *cub, double	*info[3], t_wall *wall, t_texture *text)
{
	t_draw_wall	dr;

	if (ft_get_ratio_x(&dr, info, wall, text))
		return ;
	dr.y = 0;
	dr.display = cub->display.tab;
	while (dr.y < (size_t)(wall->heigth_max))
	{
		if ((double)dr.y + wall->origin.y >= 0.
			|| (double)dr.y + wall->origin.y < Y_WIN)
		{
			dr.x = wall->start;
			while (dr.x < wall->end)
			{
				ft_get_coordonate_wall(&dr, wall, info, text);
				++(dr.x);
			}
		}
		++(dr.y);
	}
	free(dr.ratio);
}
