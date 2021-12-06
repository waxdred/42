/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:08:35 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/01 23:52:18 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_reload(t_env *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_do_key_autorepeaton(fdf->mlx_ptr);
	ft_draw_mlx_print(fdf, 0, 0);
	ft_put_string_mlx(fdf);
	mlx_key_hook(fdf->win_ptr, deal_key, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}

void	ft_get_name(t_env *fdf, char *argv)
{
	fdf->name = ft_memalloc((ft_strlen("fdf: ") + ft_strlen(argv)) + 1);
	ft_strcat(fdf->name, "fdf: ");
	ft_strcat(fdf->name, argv);
}

int	ft_mlx(t_env *fdf, char *argv)
{
	ft_get_name(fdf, argv);
	fdf->mlx_ptr = mlx_init();
	ft_window(fdf);
	ft_init(fdf);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_length,
			fdf->win_width, fdf->name);
	ft_reload(fdf);
	return (0);
}
