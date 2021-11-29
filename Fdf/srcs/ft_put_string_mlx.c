/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_string_mlx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:38:23 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/22 21:38:23 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_put_str_mlx(t_env *fdf, char *argv)
{
	int	y;

	y = 0;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, y += 20, 0xABCDEF, "Fdf :");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, y += 25, 0xABCDEF, "Press esc for quit");
}
