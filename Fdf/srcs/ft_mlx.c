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

int	ft_mlx(t_env *fdf, char *argv)
{
	P_MLX = mlx_init();
	ft_window(fdf);
	ft_init(fdf);
	fdf->win_ptr = mlx_new_window(P_MLX, fdf->win_length,
			fdf->win_width, "fdf");
	ft_draw_mlx(fdf);
	ft_put_str_mlx(fdf, argv);
	mlx_key_hook(fdf->win_ptr, deal_key, fdf);
	mlx_loop(P_MLX);
	return (0);
}
