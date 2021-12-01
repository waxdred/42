/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:38:25 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/22 20:38:25 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	deal_key(int key, t_env *fdf)
{
	if (key == ESC)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		printf("exit programme\n");
		free(*(fdf->map.map));
		free(*(fdf->map.Ox));
		free(*(fdf->map.Oy));
		exit (0);
	}
	if (key == R)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		ft_reload(fdf, "reload");
	}
	if (key == LEFT)
	{
		fdf->mov.s_x -= 5;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		ft_reload(fdf, "reload");
	}
	if (key == RIGHT)
	{
		fdf->mov.s_x += 5;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		ft_reload(fdf, "reload");
	}
	if (key == UP)
	{
		fdf->mov.s_y -= 5;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		ft_reload(fdf, "reload");
	}
	if (key == DOWN)
	{
		fdf->mov.s_y += 5;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		ft_reload(fdf, "reload");
	}
	if (key == UNZOOM)
	{
		fdf->p.spc -= 1;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		ft_reload(fdf, "reload");
	}
	if (key == ZOOM)
	{
		fdf->p.spc += 1;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		ft_reload(fdf, "reload");
	}
	return (0);
}
