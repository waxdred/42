/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:59:28 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/24 00:41:24 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static float	ft_radiant(float angle)
{
	float	res;

	res = angle * M_PI / 180;
	return (res);
}

static void	ft_fill(t_env *fdf, int n, int a, int j)
{
	if (j == 0)
		j = 1;
	fdf->p.x2 = fdf->p.x1;
	fdf->p.y2 = fdf->p.y1;
	if (n == a)
	{
		fdf->p.x2 += fdf->p.spc;
		fdf->p.y2 -= fdf->p.spc / 2;
		ft_bresenham(fdf);
		fdf->p.x1--;
	}
	else if (n < a)
	{
		fdf->p.x2 += fdf->p.spc;
		fdf->p.y2 -= (fdf->p.spc / 2) * (a - n);
		ft_bresenham(fdf);
	}
	else if (n > a)
	{
		fdf->p.x2 = fdf->p.x3 + (fdf->p.spc * (j + 1));
		fdf->p.y2 = fdf->p.y3 - ((fdf->p.spc) * (j + 1));
		ft_bresenham(fdf);
	}
}

void	ft_draw_mlx_print(t_env *fdf, int i, int j)
{
	while (i < fdf->map.nblin - 1)
	{
		j = 0;
		fdf->p.x1 = fdf->mov.s_x;
		fdf->p.y1 = fdf->mov.s_y;
		fdf->p.x3 = fdf->mov.s_x;
		fdf->p.y3 = fdf->mov.s_y;
		if (i > 0)
		{
			fdf->p.x1 += fdf->p.spc * i;
			fdf->p.y1 += (fdf->p.spc / 2) * i;
			fdf->p.x3 += fdf->p.spc * i;
			fdf->p.y3 += (fdf->p.spc * i);
		}		
		while (j < fdf->map.nbcol)
		{
			ft_fill(fdf, fdf->map.map[i][j], fdf->map.map[i][j + 1], j);
			ft_add_ord(fdf, i, j);
			j++;
		}
		i++;
	}
	ft_draw_tab(fdf, 0, 0);
}
