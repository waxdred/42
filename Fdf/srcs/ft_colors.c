/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:39:09 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/02 18:39:09 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_set_gradiant(t_env *fdf)
{
	fdf->colors.start = 1536486;
	fdf->colors.end = 1153648;
	fdf->colors.coef = fdf->colors.start - fdf->colors.end;
	if (fdf->p.z > 0)
	{
		fdf->colors.coef /= (fdf->map.high - fdf->mov.up);
		fdf->color = fdf->colors.start * ((int)fdf->colors.coef * fdf->p.z);
	}
	else
		fdf->color = fdf->colors.start;
}
