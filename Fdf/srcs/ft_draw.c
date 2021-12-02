/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:59:28 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/24 00:41:24 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_mlx_print(t_env *fdf, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map.nblin - 1)
	{
		j = 0;
		x = 0;
		while (j < fdf->map.nbcol - 1)
		{
			fdf->p.B_x = x;
			fdf->p.B_y = y;
			if (i < fdf->map.nblin - 1)
				ft_bresenham(fdf, x + 1, y);
			fdf->p.B_x = x;
			fdf->p.B_y = y;
			if (j < fdf->map.nbcol - 1)
				ft_bresenham(fdf, x, y + 1);
			x++;
			j++;
		}
		y++;
		i++;
	}	
}
