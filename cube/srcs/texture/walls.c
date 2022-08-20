/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:17:12 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/19 19:46:16 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int8_t	ft_fill_info_wall_sup(double *info[3], t_wall *wall,
										t_texture *text)
{
	size_t	i;
	double	ratio_y;

	if (wall->width_img < 1)
		return (1);
	ratio_y = (wall->l_heigth - wall->r_heigth) * 0.5 / wall->width_img;
	if (wall->end > wall->start)
	{
		i = 0;
		info[0][i] = ratio_y * (double)(i);
		info[1][i] = wall->l_heigth - info[0][i];
		info[2][i] = text->y_xpm / (info[1][i] - info[0][i]);
		while (i < wall->width_img)
		{
			++i;
			info[0][i] = info[0][i - 1] + ratio_y;
			info[1][i] = info[1][i - 1] - ratio_y;
			info[2][i] = text->y_xpm / (info[1][i] - info[0][i]);
		}
	}
	else
		return (1);
	return (0);
}

static int8_t	ft_fill_info_wall_inf(double *info[3], t_wall *wall,
										t_texture *text)
{
	size_t	i;
	double	ratio_y;

	if (wall->width_img < 1)
		return (1);
	ratio_y = (wall->r_heigth - wall->l_heigth) * 0.5 / wall->width_img;
	if (wall->end > wall->start)
	{
		i = wall->end;
		info[0][i] = (wall->width_img - 1 - i) * ratio_y;
		info[1][i] = wall->r_heigth - info[0][i];
		info[2][i] = (double)text->y_xpm / (info[1][i] - info[0][i]);
		while (i != 0)
		{
			--i;
			info[0][i] = info[0][i + 1] + ratio_y;
			info[1][i] = info[1][i + 1] - ratio_y;
			info[2][i] = (double)text->y_xpm / (info[1][i] - info[0][i]);
		}
	}
	else
		return (1);
	return (0);
}

static int8_t	ft_create_fill_info_wall(double *info[3], t_wall *wall,
											t_texture *text)
{
	info[0] = ft_memalloc(((size_t)(wall->width_img) + 2) * sizeof(double));
	info[1] = ft_memalloc(((size_t)(wall->width_img) + 2) * sizeof(double));
	info[2] = ft_memalloc(((size_t)(wall->width_img) + 2) * sizeof(double));
	if ((!(info[0]) || !(info[1]) || !(info[2]))
		|| (wall->l_heigth > wall->r_heigth
			&& ft_fill_info_wall_sup(info, wall, text))
		|| (wall->l_heigth <= wall->r_heigth
			&& ft_fill_info_wall_inf(info, wall, text)))
	{
		free(info[0]);
		free(info[1]);
		free(info[2]);
		return (1);
	}
	return (0);
}

static int8_t	ft_get_wall(t_cub *cub, t_wall *wall, t_texture *text)
{
	double	*info[3];

	if (!(text->img))
		return (1);
	if (ft_create_fill_info_wall(info, wall, text))
		return (1);
	wall->heigth_max = fmax(wall->l_heigth, wall->r_heigth);
	ft_fill_wall(cub, info, wall, text);
	free(info[0]);
	free(info[1]);
	free(info[2]);
	return (0);
}

int8_t	ft_get_wall_img(t_cub *cub, t_wall *wall)
{
	if (!cub->display.img)
		return (1);
	if (wall->door)
	{
		if (ft_get_wall(cub, wall, &(cub->surface.door)))
			return (1);
	}
	else if (wall->dir == EA && ft_get_wall(cub, wall, &(cub->surface.ea)))
		return (1);
	else if (wall->dir == NO && ft_get_wall(cub, wall, &(cub->surface.no)))
		return (1);
	else if (wall->dir == WE && ft_get_wall(cub, wall, &(cub->surface.we)))
		return (1);
	else if (wall->dir == SO && ft_get_wall(cub, wall, &(cub->surface.so)))
		return (1);
	return (0);
}
