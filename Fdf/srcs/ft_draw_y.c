/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:59:28 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/24 00:41:24 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static float	ft_radiant(float angle)
{
	float	res;

	res = angle * M_PI / 180;
	return (res);
}


void	ft_draw_mlx_print(t_env *fdf)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < fdf->map.nblin - 1)
	{
		j = 0;
		k = 0;
		while (j < fdf->map.nbcol)
		{
			ft_add_ord(fdf, i, j);
			j++;
		}
		i++;
	}
	ft_draw_tab(fdf);
}
