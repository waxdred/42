/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:03:35 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/05 18:06:23 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_space(t_env *fdf)
{
	if (fdf->map.nbcol <= 20)
		fdf->p.spc = 20;
	else if (fdf->map.nbcol >= 20 && fdf->map.nbcol <= 50)
		fdf->p.spc = 15;
	else if (fdf->map.nbcol >= 50 && fdf->map.nbcol <= 100)
		fdf->p.spc = 10;
	else if (fdf->map.nbcol >= 100 && fdf->map.nbcol <= 200)
		fdf->p.spc = 5;
	else
		fdf->p.spc = 2;
	fdf->p.zoom = fdf->p.spc;
}

void	ft_window(t_env *fdf)
{
	if (fdf->map.nbcol <= 10)
		fdf->win_length = fdf->map.nbcol * 100;
	else if (fdf->map.nbcol <= 20)
		fdf->win_length = fdf->map.nbcol * 70;
	else if (fdf->map.nbcol >= 20 && fdf->map.nbcol <= 50)
		fdf->win_length = fdf->map.nbcol * 40;
	else if (fdf->map.nbcol >= 50 && fdf->map.nbcol <= 100)
		fdf->win_length = fdf->map.nbcol * 20;
	else if (fdf->map.nbcol >= 100 && fdf->map.nbcol <= 200)
		fdf->win_length = fdf->map.nbcol * 10;
	else
		fdf->win_length = fdf->map.nbcol * 5;
	if (fdf->map.nblin <= 20)
		fdf->win_width = fdf->map.nblin * 100;
	else if (fdf->map.nblin >= 20 && fdf->map.nblin <= 50)
		fdf->win_width = fdf->map.nblin * 40;
	else if (fdf->map.nblin >= 50 && fdf->map.nblin <= 100)
		fdf->win_width = fdf->map.nblin * 20;
	else if (fdf->map.nblin >= 100 && fdf->map.nblin <= 200)
		fdf->win_width = fdf->map.nblin * 10;
	else
		fdf->win_width = fdf->map.nblin * 5;
	if (fdf->map.max > 20)
		fdf->win_width *= 2;
}

void	ft_init(t_env *fdf)
{
	ft_space(fdf);
	fdf->proj = 0;
	fdf->mov.up = 1;
	fdf->mov.angle = 0.6;
	if (fdf->p.spc == 2)
		fdf->mov.s_y = (fdf->win_width / 10);
	else
	{
		fdf->mov.s_y = (fdf->win_width / 6)
			+ (fdf->map.high * fdf->p.zoom / 2);
	}
	fdf->mov.s_x = fdf->win_length / 2;
}
