/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bg_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:43:58 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/09 04:44:00 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	put_pixel_bg(t_cub *cube, int x, int y, int color)
{
	int	i;

	i = X_WIN * y + x;
	cube->bg.map[i].i = (unsigned int)color;
}

int	ft_create_rgb(t_color *u)
{
	return (((u->str[3] & 0xff) << 16) + ((u->str[2] & 0xff) << 8)
		+ (u->str[1] & 0xff));
}

t_color	*ft_change_bright_color(t_color *rgb, float corr)
{
	t_rgb	c;

	c.rgb_bright = ft_memalloc(sizeof(t_color));
	c.r = (float)rgb->str[3];
	c.g = (float)rgb->str[2];
	c.b = (float)rgb->str[1];
	if (corr < 0)
	{
		corr += 1;
		c.r *= corr;
		c.g *= corr;
		c.b *= corr;
	}
	else
	{
		c.r = (255 - c.r) * corr + c.r;
		c.g = (255 - c.g) * corr + c.g;
		c.b = (255 - c.b) * corr + c.b;
	}
	c.rgb_bright->str[3] = (unsigned char)c.r;
	c.rgb_bright->str[2] = (unsigned char)c.g;
	c.rgb_bright->str[1] = (unsigned char)c.b;
	return (c.rgb_bright);
}

static void	set_backgroud_draw(t_cub *cube, t_pos p, int i)
{
	t_color	*rgb;

	if ((int)p.y <= Y_WIN / 2)
		put_pixel_bg(cube, (int)p.x, (int)p.y,
			ft_create_rgb(&cube->surface.ceiling));
	else if ((int)p.y > Y_WIN / 2)
	{
		rgb = ft_change_bright_color(&cube->surface.floor, i);
		put_pixel_bg(cube, (int)p.x, (int)p.y, ft_create_rgb(rgb));
		free(rgb);
	}
}

void	ft_draw_background(t_cub *cube, t_texture *bg)
{
	t_pos	p;
	float	i;

	bg->map = (t_color *)mlx_get_data_addr(bg->img, &(bg->bpp),
			&(bg->size_line), &(bg->endian));
	p.y = 0;
	i = -1;
	while ((int)p.y < Y_WIN)
	{
		p.x = 0;
		while ((int)p.x < X_WIN)
		{
			set_backgroud_draw(cube, p, i);
			p.x++;
		}
		i += (float)Y_WIN / 1000000;
		p.y++;
	}
}
