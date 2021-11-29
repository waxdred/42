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
	printf("value de key %d", key);
	if (key == ESC)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		printf("exit programme\n");
		free(*(fdf->map.map));
		free(*(fdf->map.Ox));
		free(*(fdf->map.Oy));
		exit (0);
	}
	return (0);
}
