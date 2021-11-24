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
	printf("%d", fdf->p.pos);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->p.pos, fdf->p.spc, 0xABCDEF, "Fdf :");
	fdf->p.spc += 30;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->p.pos, fdf->p.spc, 0xABCDEF, "Map :");
	fdf->p.pos += 60;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->p.pos, fdf->p.spc, 0xABCDEF, argv);
	fdf->p.pos -= 60;
	fdf->p.spc += 30;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->p.pos, fdf->p.spc, 0xABCDEF, "Press <ESC> for quit");
}
