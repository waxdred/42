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

int	ft_hight(t_env *fdf, int key)
{
	if (key == W)
		fdf->mov.up += 5;
	else if (key == S)
		fdf->mov.up -= 5;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_reload(fdf);
	return (0);
}

int	ft_open_menu(t_env *fdf, int key)
{
	if (fdf->menu == 0)
		fdf->menu = 1;
	else if (fdf->menu == 1)
		fdf->menu = 0;
	ft_reload(fdf);
	return (0);
}

int	ft_rotate(t_env *fdf, int key)
{
	if (key == A)
		fdf->mov.angle -= 0.1;
	else if (key == D)
		fdf->mov.angle += 0.1;
	ft_reload(fdf);
	return (0);
}

int	deal_key(int key, t_env *fdf)
{
	if (key == ESC)
		ft_escape(fdf, key);
	else if (key == UNZOOM || key == ZOOM)
		ft_zoom(fdf, key);
	else if (key == ISO || key == PROJECT)
		ft_projection(fdf, key);
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
	{
		if (fdf->proj == 0)
			ft_move_proj(fdf, key);
		else
			ft_move_iso(fdf, key);
	}
	else if (key == W || key == S)
		ft_hight(fdf, key);
	else if (key == M)
		ft_open_menu(fdf, key);
	else if (key == A || key == D)
		ft_rotate(fdf, key);
	return (0);
}
