/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:08:35 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/22 21:08:35 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_reload(t_env *fdf, char *argv)
{
	ft_draw_mlx_print(fdf, 0 , 0);
	ft_put_str_mlx(fdf, argv);
	mlx_key_hook(fdf->win_ptr, deal_key, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}

int	ft_mlx(t_env *fdf, char *argv)
{
	fdf->mlx_ptr = mlx_init();
	ft_window(fdf);
	ft_init(fdf);
	if (ft_init_ord(fdf))
		return (-1);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_length,
			fdf->win_width, "fdf");
	ft_reload(fdf, argv);
	return (0);
}

