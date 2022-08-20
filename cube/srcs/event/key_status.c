/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <x@student.42lyon.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:46:55 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/20 19:44:03 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_key_hit(int key, t_cub *cub)
{
	if (key >= KEY)
		return (1);
	cub->inter.key[key] = 1;
	return (0);
}

int	ft_key_release(int key, t_cub *cub)
{
	if (key >= KEY)
		return (1);
	cub->inter.key[key] = 0;
	return (0);
}

int	ft_mini_map_key(t_cub *cube)
{
	cube->inter.activ_map.press = 1;
	return (0);
}

int	ft_door_key(t_cub *cube)
{
	cube->inter.activ_door.press = 1;
	return (0);
}

int	ft_debeug_key(t_cub *cube)
{
	cube->inter.activ_debeug.press = 1;
	return (0);
}
