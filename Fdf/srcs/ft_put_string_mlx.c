/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_string_mlx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:38:23 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/22 21:38:23 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_backgroud(t_env *fdf, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, j, i,
				0x2D3535);
			j++;
		}
		i++;
	}
}

void	ft_put_string_mlx(t_env *fdf)
{
	if (fdf->menu == 0)
	{
		ft_backgroud(fdf, 55, 125);
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, 25, 0x00FFFF,
			"Memu Press M");
	}
	else if (fdf->menu == 1)
		ft_menu(fdf);
}

void	ft_menu(t_env *fdf)
{
	int	y;

	y = 0;
	ft_backgroud(fdf, 200, 200);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, y += 25, 0x00FFFF,
		"Esc for quit:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, y += 20, 0x00FFFF,
		"Fdf Project :");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, y += 25, 0x00FFFF,
		"Zoom : + / - ");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, y += 25, 0x00FFFF,
		"Move : use arrow");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, y += 25, 0x00FFFF,
		"Change hight : w / s ");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, y += 25, 0x00FFFF,
		"Rotation  : a / d");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, y += 25, 0x00FFFF,
		"Vue iso : i");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, y += 25, 0x00FFFF,
		"Vue projection : p");
}
