/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:03:35 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/22 19:03:35 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_space(t_env *fdf)
{
	if (fdf->map.nbcol <= 20)
		fdf->p.spc = 32;
	else if (fdf->map.nbcol >= 20 && fdf->map.nbcol <= 50)
		fdf->p.spc = 22;
	else if (fdf->map.nbcol >= 50 && fdf->map.nbcol <= 100)
		fdf->p.spc = 12;
	else if (fdf->map.nbcol >= 100 && fdf->map.nbcol <= 200)
		fdf->p.spc = 6;
	else
		fdf->p.spc = 2;
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
		fdf->win_length = fdf->map.nbcol * 10;
	if (fdf->map.nblin <= 20)
		fdf->win_width = fdf->map.nblin * 100;
	else if (fdf->map.nblin >= 20 && fdf->map.nblin <= 50)
		fdf->win_width = fdf->map.nblin * 40;
	else if (fdf->map.nblin >= 50 && fdf->map.nblin <= 100)
		fdf->win_width = fdf->map.nblin * 20;
	else if (fdf->map.nblin >= 100 && fdf->map.nblin <= 200)
		fdf->win_width = fdf->map.nblin * 10;
	else
		fdf->win_width = fdf->map.nblin * 10;
}

void	ft_init(t_env *fdf)
{
	ft_space(fdf);
	if (!fdf->color.color)
	{
		fdf->color.red = 255;
		fdf->color.green = 255;
		fdf->color.blue = 255;
	}
	fdf->mov.s_y = fdf->win_length / 2;
	fdf->mov.s_x = fdf->win_width / 4;
}
