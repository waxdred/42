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

void	ft_pixel(t_env *fdf, int x, int y, int color)
{
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, color);
}

void	ft_init_bre(t_env *fdf)
{
	fdf->p.errx = abs(fdf->p.x2 - fdf->p.x1);
	fdf->p.erry = abs(fdf->p.y2 - fdf->p.y1);
	fdf->p.dx = 2 * fdf->p.errx;
	fdf->p.dy = 2 * fdf->p.erry;
	fdf->p.Dx = fdf->p.errx;
	fdf->p.Dy = fdf->p.erry;
	fdf->p.i = 0;
	if (fdf->p.x1 > fdf->p.x2)
		fdf->p.Xincr = -1;
	else
		fdf->p.Xincr = 1;
	if (fdf->p.y1 > fdf->p.y2)
		fdf->p.Yincr = -1;
	else
		fdf->p.Yincr = 1;
}

void	ft_case_one(t_env *fdf)
{
	while (fdf->p.i <= fdf->p.Dx)
	{
		ft_pixel(fdf, fdf->p.x1, fdf->p.y1, 16776960);
		fdf->p.i++;
		fdf->p.x1 +=fdf->p.Xincr;
		fdf->p.errx -= fdf->p.dy;
		if (fdf->p.errx < 0 )
		{
			fdf->p.y1 += fdf->p.Yincr;
			fdf->p.errx += fdf->p.dx;
		}
	}
}

void	ft_case_two(t_env *fdf)
{
	while (fdf->p.i <= fdf->p.Dy)
	{
		ft_pixel(fdf, fdf->p.x1, fdf->p.y1, 16747776);
		fdf->p.i++;
		fdf->p.y1 += fdf->p.Yincr;
		fdf->p.erry -= fdf->p.dx;
		if (fdf->p.erry < 0 )
		{
			fdf->p.x1 += fdf->p.Xincr;
			fdf->p.erry += fdf->p.dy;
		}
	}
}
void	ft_bresenham(t_env *fdf)
{
	ft_init_bre(fdf);
	if (fdf->p.Dx > fdf->p.Dy)
		ft_case_one(fdf);
	if (fdf->p.Dx < fdf->p.Dy)
		ft_case_two(fdf);
}
