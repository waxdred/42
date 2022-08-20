/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:32:53 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/20 22:53:39 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_init_scale(t_cub *cub)
{
	size_t	max;

	if (cub->x_map > cub->y_map)
		max = cub->x_map;
	else
		max = cub->y_map;
	if (max <= 40 && max >= 2)
		cub->scale = 0.25;
	else if (max <= 80 && max >= 41)
		cub->scale = 0.25;
	else if (max <= 120 && max >= 81)
		cub->scale = 0.125;
	else
		cub->scale = 0.0625;
	return (1);
}

static void	put_pixel_mini_map(t_cub *cub, int x, int y, int color)
{
	int	i;

	i = (cub->x_map * SQUARES * cub->scale) * y + x;
	cub->mini_map.map[i].i = (unsigned int)color;
}

static void	fill_squares(t_cub *cube, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < (SQUARES * cube->scale) - 1)
	{
		i = 0;
		while (i < (SQUARES * cube->scale) - 1)
		{
			put_pixel_mini_map(cube, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

static void	ft_get_adress_img(t_cub *cub, int8_t b, size_t *d)
{
	if (b)
	{
		cub->mini_map.map = (t_color *)mlx_get_data_addr(cub->mini_map.img,
				&cub->mini_map.bpp, &cub->mini_map.size_line,
				&cub->mini_map.endian);
	}
	else if (!b)
	{
		if (cub->map[d[1]][d[0]] == '1')
			fill_squares(cub, d[0] * SQUARES * cub->scale, d[1]
				* SQUARES * cub->scale, 0xFFFFFF);
		else if (cub->map[d[1]][d[0]] == '2' || cub->map[d[1]][d[0]] == '3')
			fill_squares(cub, d[0] * SQUARES * cub->scale, d[1]
				* SQUARES * cub->scale, 0x820DB2);
		else
			fill_squares(cub, d[0] * SQUARES * cub->scale, d[1]
				* SQUARES * cub->scale, 0x808080);
	}
}

void	ft_draw_minimap(t_cub *cub)
{
	size_t	d[3];

	ft_bzero(d, sizeof(size_t) * 3);
	ft_get_adress_img(cub, 1, d);
	while (d[1] < cub->y_map)
	{
		d[0] = 0;
		while (d[0] < cub->x_map)
		{
			ft_get_adress_img(cub, 0, d);
			d[0]++;
			d[2]++;
		}
		d[1]++;
	}
}
