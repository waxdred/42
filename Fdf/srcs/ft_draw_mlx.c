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

float	ft_radiant(int angle)
{
	float	res;

	res = angle * M_PI / 180;
	return (res);
}

void	ft_fill_print(t_env *fdf, int check)
{
	fdf->p.x2 = fdf->p.x1;
	fdf->p.y2 = fdf->p.y1;
	if (check == 0)
	{
		fdf->p.x2 += fdf->p.spc;
		fdf->p.y2 -= (int)((fdf->p.spc * ft_radiant(30)));
		printf("X1 == %d,Y1 ==== %d\n", fdf->p.x1, fdf->p.y1);
		printf("X2 == %d,Y2 ==== %d\n", fdf->p.x2, fdf->p.y2);
		ft_bresenham(fdf);
	}
}

void	ft_draw_mlx(t_env *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map.nblin)
	{
		fdf->p.x1 = fdf->mov.s_x;
		fdf->p.y1 = fdf->mov.s_y;
		j = 0;
		if (i > 0)
		{
			fdf->p.x1 += fdf->p.spc * i;
			fdf->p.y1 += (int)(ft_radiant(30) * i);
		}
		while (j < fdf->map.nbcol)
		{
			if (fdf->map.map[i][j] == fdf->map.map[i][j + 1])
				ft_fill_print(fdf, 0);
			j++;
		}
		i++;
	}
	ft_bresenham(fdf);
}
