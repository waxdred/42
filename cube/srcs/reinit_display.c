/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:23:06 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/09 05:23:07 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_reinit_display(t_cub *cub)
{
	size_t	i;
	size_t	len;
	t_color	*bg;
	t_color	*display;

	len = X_WIN * Y_WIN;
	bg = cub->bg.map;
	display = cub->display.map;
	i = 0;
	while (i < len)
	{
		(*display).i = (*bg).i;
		++display;
		++bg;
		++i;
	}
}

void	ft_reinit_minimap(t_cub *cub)
{
	size_t	i;
	size_t	len;
	t_color	*bg;
	t_color	*display;

	bg = cub->mini_map.map;
	len = (size_t)(SQUARES * cub->x_map * cub->scale)
		* (size_t)(SQUARES * cub->y_map * cub->scale);
	display = cub->player_mini_map.map;
	i = 0;
	while (i < len)
	{
		(*display).i = (*bg).i;
		++display;
		++bg;
		++i;
	}
}
