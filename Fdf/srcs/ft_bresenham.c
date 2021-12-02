/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:37:48 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/24 00:37:48 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_iso(t_env *fdf, float *x, float *y, int z)
{
	float	u;
	float	w;

	u = (*x - *y) * cos(fdf->mov.angle);
	w = (*x + *y) * sin(fdf->mov.angle) - (z * (fdf->p.spc + fdf->mov.up));
	*x = u;
	*y = w;
}

void	ft_set(t_env *fdf)
{
	fdf->p.B_x = (fdf->p.B_x * (float)fdf->p.spc) + (float)fdf->mov.s_x;
	fdf->p.B_y = (fdf->p.B_y * (float)fdf->p.spc) + (float)fdf->mov.s_y;
	fdf->p.B_x1 = (fdf->p.B_x1 * (float)fdf->p.spc) + (float)fdf->mov.s_x;
	fdf->p.B_y1 = (fdf->p.B_y1 * (float)fdf->p.spc) + (float)fdf->mov.s_y;
}

void	ft_set_color(t_env *fdf)
{
	if (fdf->p.z >= 0 && fdf->p.z <= 5)
		fdf->color = 0x10879D;
	else if (fdf->p.z >= 6 && fdf->p.z <= 10)
		fdf->color = 0x82370f;
	else if (fdf->p.z >= 11 && fdf->p.z <= 15)
		fdf->color = 0x1e2e4d;
	else if (fdf->p.z >= 16 && fdf->p.z <= 20)
		fdf->color = 46221;
	else if (fdf->p.z >= -1 && fdf->p.z <= -5)
		fdf->color = 39935;
	else if (fdf->p.z >= -6 && fdf->p.z <= -10)
		fdf->color = 16737617;
	else if (fdf->p.z >= -11 && fdf->p.z <= -15)
		fdf->color = 11180288;
	else if (fdf->p.z >= -16 && fdf->p.z <= -20)
		fdf->color = 46500;
}

void	ft_bresenham(t_env *fdf, float x1, float y1)
{
	fdf->p.B_x1 = x1;
	fdf->p.B_y1 = y1;
	fdf->p.z = fdf->map.map[(int)fdf->p.B_y][(int)fdf->p.B_x];
	fdf->p.z1 = fdf->map.map[(int)y1][(int)x1];
	ft_set_color(fdf);
	ft_set(fdf);
	if (fdf->proj == 0)
	{
		ft_iso(fdf, &fdf->p.B_x, &fdf->p.B_y, fdf->p.z);
		ft_iso(fdf, &fdf->p.B_x1, &fdf->p.B_y1, fdf->p.z1);
	}
	fdf->p.x_step = fdf->p.B_x1 - fdf->p.B_x;
	fdf->p.y_step = fdf->p.B_y1 - fdf->p.B_y;
	fdf->p.max = MAX(MOD(fdf->p.x_step), MOD(fdf->p.y_step));
	fdf->p.x_step /= fdf->p.max;
	fdf->p.y_step /= fdf->p.max;
	while ((int)(fdf->p.B_x - fdf->p.B_x1) || (int)(fdf->p.B_y - fdf->p.B_y1))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->p.B_x,
			fdf->p.B_y, fdf->color);
		fdf->p.B_x += fdf->p.x_step;
		fdf->p.B_y += fdf->p.y_step;
	}
}
