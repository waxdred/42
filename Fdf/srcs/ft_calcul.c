/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:13:19 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/05 21:13:19 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_iso(t_env *fdf, float *x, float *y, int z)
{
	float	u;
	float	w;

	u = (*x - *y) * cos(fdf->mov.angle);
	w = (*x + *y) * sin(fdf->mov.angle) - (z * (fdf->mov.up + fdf->p.spc / 2));
	*x = u;
	*y = w;
}

float	mod(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}
