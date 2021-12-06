/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:05:26 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/05 17:46:12 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_projection(t_env *fdf, int key)
{
	if (key == ISO)
	{
		fdf->proj = 1;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	if (key == PROJECT)
	{
		if (PROJECT == 0)
			return (0);
		fdf->proj = 0;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	ft_reload(fdf);
	return (0);
}

int	ft_zoom(t_env *fdf, int key)
{
	if (key == UNZOOM)
	{
		fdf->p.spc -= 1;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	if (key == ZOOM)
	{
		fdf->p.spc += 1;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	ft_reload(fdf);
	return (0);
}

int	ft_escape(t_env *fdf, int key)
{
	if (key == ESC)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		ft_free_map(fdf);
		free(*(fdf->map.map));
		free(fdf->name);
		ft_putstr("exit programme\n");
		exit (0);
	}
	return (0);
}

int	ft_color_on(t_env *fdf, int key)
{
	if (key == C)
	{
		if (fdf->color_on == 0)
			fdf->color_on = 1;
		else if (fdf->color_on == 1)
			fdf->color_on = 0;
	}
	ft_reload(fdf);
	return (0);
}

void	ft_move_view(t_env *fdf, int key)
{	
	if (key == LEFT)
	{
		fdf->mov.s_x -= 5;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	if (key == RIGHT)
	{
		fdf->mov.s_x += 5;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	if (key == UP)
	{
		fdf->mov.s_y -= 5;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	if (key == DOWN)
	{
		fdf->mov.s_y += 5;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	ft_reload(fdf);
}
