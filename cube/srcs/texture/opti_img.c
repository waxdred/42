/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:39:25 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/10 17:39:26 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int8_t	ft_get_img_tab(t_cub *cub, t_texture *text, size_t x, size_t y)
{
	size_t	i;

	text->tab = ft_track(malloc(y * sizeof(t_color *)), &(cub->track));
	if (!(text->tab))
		return (1);
	i = 0;
	while (i < y)
	{
		text->tab[i] = &(text->map[i * x]);
		++i;
	}
	return (0);
}

static	int8_t	ft_img_opti_tab_texture(t_cub *cub)
{
	t_texture	*tmp;

	tmp = &(cub->surface.ea);
	if (ft_get_img_tab(cub, tmp, tmp->x_xpm, tmp->y_xpm))
		return (1);
	tmp = &(cub->surface.no);
	if (ft_get_img_tab(cub, tmp, tmp->x_xpm, tmp->y_xpm))
		return (1);
	tmp = &(cub->surface.so);
	if (ft_get_img_tab(cub, tmp, tmp->x_xpm, tmp->y_xpm))
		return (1);
	tmp = &(cub->surface.we);
	if (ft_get_img_tab(cub, tmp, tmp->x_xpm, tmp->y_xpm))
		return (1);
	tmp = &(cub->surface.door);
	if (tmp->file)
	{
		if (ft_get_img_tab(cub, tmp, tmp->x_xpm, tmp->y_xpm))
			return (1);
	}
	return (0);
}

int8_t	ft_img_opti_tab(t_cub *cub)
{
	t_texture	*tmp;

	if (ft_img_opti_tab_texture(cub))
		return (1);
	tmp = &(cub->mini_map);
	if (ft_get_img_tab(cub, tmp, tmp->x_xpm, tmp->y_xpm))
		return (1);
	tmp = &(cub->player_mini_map);
	if (ft_get_img_tab(cub, tmp, tmp->x_xpm, tmp->y_xpm))
		return (1);
	if (ft_get_img_tab(cub, &(cub->display), X_WIN, Y_WIN))
		return (1);
	return (0);
}
