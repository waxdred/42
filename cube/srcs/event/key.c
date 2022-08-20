/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:46:55 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/11 21:49:18 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_option_map(t_cub *cube)
{
	if (cube->inter.activ_map.press && !(cube->inter.activ_map.active))
	{
		cube->inter.activ_map.active = 1;
		cube->inter.key[M] = -1;
		mlx_put_image_to_window(cube->p_mlx, cube->p_win,
			cube->player_mini_map.img, 0, 0);
	}
	else if (cube->inter.activ_map.press && cube->inter.activ_map.active)
	{
		cube->inter.activ_map.active = 0;
		cube->inter.activ_map.press = 0;
		cube->inter.key[M] = -1;
		ft_reload(cube);
	}
	return (0);
}

int	ft_option_debeug(t_cub *cube)
{
	if (cube->inter.activ_debeug.press && !(cube->inter.activ_debeug.active))
	{
		cube->inter.activ_debeug.active = 1;
		cube->inter.key[T] = -1;
		ft_reload(cube);
	}
	else if (cube->inter.activ_debeug.press && cube->inter.activ_debeug.active)
	{
		cube->inter.activ_debeug.active = 0;
		cube->inter.activ_debeug.press = 0;
		cube->inter.key[T] = -1;
		ft_reload(cube);
	}
	return (0);
}

int	ft_option_door(t_cub *cube)
{
	if (cube->inter.activ_door.press && !(cube->inter.activ_door.active))
	{
		cube->inter.activ_door.active = 1;
		ft_open_door(cube);
		cube->inter.key[ESP] = -1;
		ft_reload(cube);
	}
	else if (cube->inter.activ_door.press && cube->inter.activ_door.active)
	{
		cube->inter.activ_door.active = 0;
		cube->inter.activ_door.press = 0;
		cube->inter.key[ESP] = -1;
		ft_close_door(cube);
		ft_reload(cube);
	}
	return (0);
}
