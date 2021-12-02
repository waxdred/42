/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:05:26 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/02 01:05:26 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_projection(t_env *fdf, int key)
{
	if (key == ISO)
	{
		fdf->proj = 1;
		fdf->mov.s_y = 100;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	if (key == PROJECT)
	{
		if (PROJECT == 0)
			return (0);
		fdf->proj = 0;
		fdf->mov.s_y = -300;
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
		printf("exit programme\n");
		free(*(fdf->map.map));
		exit (0);
	}
	return (0);
}

void	ft_move_proj(t_env *fdf, int key)
{	
	if (key == LEFT)
	{
		fdf->mov.s_x -= 5;
		fdf->mov.s_y += 5;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	if (key == RIGHT)
	{
		fdf->mov.s_x += 5;
		fdf->mov.s_y -= 5;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	if (key == UP)
	{
		fdf->mov.s_x -= 5;
		fdf->mov.s_y -= 5;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	if (key == DOWN)
	{
		fdf->mov.s_x += 5;
		fdf->mov.s_y += 5;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	ft_reload(fdf);
}

void	ft_move_iso(t_env *fdf, int key)
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
