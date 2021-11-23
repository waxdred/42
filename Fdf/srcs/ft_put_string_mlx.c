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
	printf("%d", POS);
	mlx_string_put(P_MLX, P_WIN, POS, SPC, 0xABCDEF, "Fdf :");
	SPC += 30;
	mlx_string_put(P_MLX, P_WIN, POS, SPC, 0xABCDEF, "Map :");
	POS += 60;
	mlx_string_put(P_MLX, P_WIN, POS, SPC, 0xABCDEF, argv);
	POS -= 60;
	SPC += 30;
	mlx_string_put(P_MLX, P_WIN, POS, SPC, 0xABCDEF, "Press <ESC> for quit");
}
