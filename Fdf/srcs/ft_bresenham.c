/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:37:48 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/05 18:24:23 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_set(t_env *fdf)
{
	fdf->p.b_x = (fdf->p.b_x * (float)fdf->p.spc);
	fdf->p.b_y = (fdf->p.b_y * (float)fdf->p.spc);
	fdf->p.b_x1 = (fdf->p.b_x1 * (float)fdf->p.spc);
	fdf->p.b_y1 = (fdf->p.b_y1 * (float)fdf->p.spc);
}

void	ft_put_pixel(t_env *fdf)
{
	if (fdf->color_on == 1)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->p.b_x,
			fdf->p.b_y, fdf->color);
	}
	else
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->p.b_x,
			fdf->p.b_y, 0xFFFAFA);
}

void	ft_move(t_env *fdf)
{
	fdf->p.b_x += fdf->mov.s_x;
	fdf->p.b_y += fdf->mov.s_y;
	fdf->p.b_x1 += fdf->mov.s_x;
	fdf->p.b_y1 += fdf->mov.s_y;
}

void	ft_bresenham(t_env *fdf, float x1, float y1)
{
	fdf->p.b_x1 = x1;
	fdf->p.b_y1 = y1;
	fdf->p.z = fdf->map.map[(int)fdf->p.b_y][(int)fdf->p.b_x];
	fdf->p.z1 = fdf->map.map[(int)y1][(int)x1];
	ft_set(fdf);
	if (fdf->proj == 0)
	{
		ft_iso(fdf, &fdf->p.b_x, &fdf->p.b_y, fdf->p.z);
		ft_iso(fdf, &fdf->p.b_x1, &fdf->p.b_y1, fdf->p.z1);
	}
	ft_move(fdf);
	fdf->p.x_step = fdf->p.b_x1 - fdf->p.b_x;
	fdf->p.y_step = fdf->p.b_y1 - fdf->p.b_y;
	fdf->p.max = max(mod(fdf->p.x_step), mod(fdf->p.y_step));
	fdf->p.x_step /= fdf->p.max;
	fdf->p.y_step /= fdf->p.max;
	while ((int)(fdf->p.b_x - fdf->p.b_x1) || (int)(fdf->p.b_y - fdf->p.b_y1))
	{
		ft_set_gradiant(fdf);
		ft_put_pixel(fdf);
		fdf->p.b_x += fdf->p.x_step;
		fdf->p.b_y += fdf->p.y_step;
	}
}
