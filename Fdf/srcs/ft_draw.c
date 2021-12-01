/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:59:28 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/24 00:41:24 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	ft_fill_p(t_env *fdf, int n, int a, int i, int j)
{
	if (n == a)
	{
		fdf->p.x2 += fdf->p.spc;
		fdf->p.y2 -= fdf->p.spc / 2;
	}
	else if (n < a)
	{
		fdf->p.x2 += fdf->p.spc;
		fdf->p.y2 += (fdf->p.spc / 2) * ((n - a) * 2);
	}
	else if (n > a)
	{
		fdf->p.x2 += fdf->p.spc;
		fdf->p.y2 -= (fdf->p.spc / 2) * ((a - n) * 2) + fdf->p.spc;
	}
}

static	void	ft_fill_n(t_env *fdf, int n, int a, int i, int j)
{
	if (n == a)
	{
		fdf->p.x2 += fdf->p.spc;
		fdf->p.y2 -= fdf->p.spc / 2;
	}
	else if (n < a)
	{
		fdf->p.x2 += fdf->p.spc;
		fdf->p.y2 -= (fdf->p.spc / 2) * ((a - n) * 2);
	}
	else if (n > a)
	{
		fdf->p.x2 += fdf->p.spc;
		fdf->p.y2 += (fdf->p.spc / 2) * ((n - a) * 2) + fdf->p.spc;
	}
}

static void	ft_fill(t_env *fdf, int n, int a, int i, int j)
{
	j++;
	fdf->p.x2 = fdf->p.x1;
	fdf->p.y2 = fdf->p.y1;
	ft_fill_p(fdf, n, a, i, j);
	ft_bresenham(fdf);
}

void	ft_draw_mlx_print(t_env *fdf, int i, int j)
{
	while (i < fdf->map.nblin - 1)
	{
		j = 0;
		fdf->p.x1 = fdf->mov.s_x;
		fdf->p.y1 = fdf->mov.s_y;
		if (i > 0)
		{
			fdf->p.x1 += fdf->p.spc * i;
			fdf->p.y1 += (fdf->p.spc / 2) * i;
		}		
		while (j < fdf->map.nbcol - 1)
		{
			ft_add_ord(fdf, i, j);
			ft_fill(fdf, fdf->map.map[i][j], 
				fdf->map.map[i][j + 1], i, j);
			j++;
		}
		i++;
	}	
	ft_draw_tab(fdf, 0, 0);
}
