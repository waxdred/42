/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:50:54 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/09 04:51:58 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_mouse_hit(int button, int x, int y, t_cub *cub)
{
	cub->inter.mouse.pos.x = x;
	cub->inter.mouse.pos.y = y;
	cub->inter.mouse.last_pos.x = x;
	cub->inter.mouse.last_pos.y = y;
	cub->inter.mouse.button[button] = 1;
	return (0);
}

int	ft_mouse_release(int button, int x, int y, t_cub *cub)
{
	cub->inter.mouse.pos.x = x;
	cub->inter.mouse.pos.y = y;
	cub->inter.mouse.last_pos.x = x;
	cub->inter.mouse.last_pos.y = y;
	cub->inter.mouse.button[button] = 0;
	return (0);
}

static void	rotate_mouse(t_cub *cube, t_mouse *m, double coef, int x)
{
	if (m->last_pos.x > x)
	{
		cube->player.pa -= coef;
		if (cube->player.pa < 0)
			cube->player.pa += 2 * PI;
		cube->player.dp_x = cos(cube->player.pa) * 5;
		cube->player.dp_y = sin(cube->player.pa) * 5;
	}
	else if (m->last_pos.x < x)
	{
		cube->player.pa += coef;
		if (cube->player.pa > 2 * PI)
			cube->player.pa -= 2 * PI;
		cube->player.dp_x = cos(cube->player.pa) * 5;
		cube->player.dp_y = sin(cube->player.pa) * 5;
	}
}

int	ft_rotate_mouse(t_cub *cube, t_mouse *m)
{
	int		x;
	int		y;
	double	coef;

	mlx_mouse_get_pos(cube->p_win, &x, &y);
	coef = fabs(x - m->last_pos.x) / 10000;
	if (coef > 0.10)
		coef = 0.10;
	if (m->button[L_CLICK])
	{
		if (m->last_pos.x < x + 20 && m->last_pos.x > x - 20)
			return (0);
		rotate_mouse(cube, m, coef, x);
	}
	ft_reload(cube);
	return (0);
}
