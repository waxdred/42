/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:59:28 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/22 21:59:28 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
void	ft_up_right(t_env *fdf)
{
	int pix;

	pix = CUBE / MULT;
	while (pix)
	{
		mlx_pixel_put(P_MLX, P_WIN, fdf->mov.y, fdf->mov.x,
		0xffff);
		fdf->mov.y++;
		mlx_pixel_put(P_MLX, P_WIN, fdf->mov.y, fdf->mov.x,
		0xffff);
		fdf->mov.y++;
		fdf->mov.x--;
		pix--;
	}
}

void	ft_down_left(t_env *fdf)
{
	int pix;

	pix = CUBE / MULT;
	while (pix)
	{
		mlx_pixel_put(P_MLX, P_WIN, fdf->mov.y, fdf->mov.x,
		0xffff);
		fdf->mov.y--;
		mlx_pixel_put(P_MLX, P_WIN, fdf->mov.y, fdf->mov.x,
		0xffff);
		fdf->mov.y--;
		fdf->mov.x++;
		pix--;
	}
}

void	ft_down_right(t_env *fdf)
{
	int pix;

	pix = CUBE / MULT;
	while (pix)
	{
		mlx_pixel_put(P_MLX, P_WIN, fdf->mov.y, fdf->mov.x,
		0xffff);
		fdf->mov.y++;
		mlx_pixel_put(P_MLX, P_WIN, fdf->mov.y, fdf->mov.x,
		0xffff);
		fdf->mov.y++;
		fdf->mov.x++;
		pix--;
	}
}

void	ft_up_left(t_env *fdf)
{
	int pix;

	pix = CUBE / MULT;
	while (pix)
	{
		mlx_pixel_put(P_MLX, P_WIN, fdf->mov.y, fdf->mov.x,
		0xffff);
		fdf->mov.y--;
		mlx_pixel_put(P_MLX, P_WIN, fdf->mov.y, fdf->mov.x,
		0xffff);
		fdf->mov.y--;
		fdf->mov.x--;
		pix--;
	}
}

void	ft_up_left_top(t_env *fdf)
{
	int pix;

	pix = CUBE / MULT;
	while (pix)
	{
		mlx_pixel_put(P_MLX, P_WIN, fdf->mov.y, fdf->mov.x,
		0xffff);
		fdf->mov.y--;
		mlx_pixel_put(P_MLX, P_WIN, fdf->mov.y, fdf->mov.x,
		0xffff);
		fdf->mov.y--;
		fdf->mov.x--;
		pix--;
	}
}

void	ft_draw_mlx(t_env *fdf)
{
	printf("map de x %d, map de y %d\n", MAPX, MAPY);
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < MAPY)
	{
		j = 0;
		fdf->mov.y = fdf->mov.s_y;
		fdf->mov.x = fdf->mov.s_x;
		while (j < MAPX)
		{
			fdf->mov.tmp_y = fdf->mov.y;
			fdf->mov.tmp_x = fdf->mov.x;
			if ((i + 1) < MAPY)
			{
				ft_down_right(fdf);
				if (j == 0)
				{
					fdf->mov.s_y = fdf->mov.y;
					fdf->mov.s_x = fdf->mov.x;
				}
			}
			printf("%d ", MAPMAP[i][j]);
			fdf->mov.y = fdf->mov.tmp_y;
			fdf->mov.x = fdf->mov.tmp_x;
			if ((j + 1) < MAPX)
				ft_up_right(fdf);
			j++;
		}
		printf("\n");
		i++;
	}
}
