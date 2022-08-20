/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:19:20 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/10 17:26:43 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int8_t	ft_fill_img(t_cub *cub, t_texture *text)
{
	text->img = mlx_xpm_file_to_image(cub->p_mlx, text->file, &(text->x_xpm),
			&(text->y_xpm));
	if (!(text->img))
	{
		ft_putstr_fd("Error\nmlx to xpm error\n", 2);
		return (1);
	}
	if (text->y_xpm < 2 || text->x_xpm < 2)
	{
		ft_putstr_fd("Error\nSize xpm\n", 2);
		return (1);
	}
	text->map = (t_color *)mlx_get_data_addr(text->img, &(text->bpp),
			&(text->size_line), &(text->endian));
	if (!(text->map))
	{
		mlx_destroy_image(cub->p_mlx, text->img);
		text->img = NULL;
		return (1);
	}
	return (0);
}

static void	ft_destroy_texture(t_cub *cub, t_texture *text)
{
	if (text->img)
		mlx_destroy_image(cub->p_mlx, text->img);
	text->img = NULL;
	text->map = NULL;
	if (text->file)
		ft_track_free(&(cub->track), text->file);
	if (text->tab)
		ft_track_free(&(cub->track), text->tab);
	text->tab = NULL;
	text->file = NULL;
}

static int8_t	ft_get_img_win(t_cub *cub)
{
	cub->display.x_xpm = X_WIN;
	cub->display.y_xpm = Y_WIN;
	cub->player_mini_map.x_xpm = (int)(SQUARES * cub->x_map * cub->scale);
	cub->player_mini_map.y_xpm = (int)(SQUARES * cub->y_map * cub->scale);
	cub->bg.img = mlx_new_image(cub->p_mlx, X_WIN, Y_WIN);
	cub->display.img = mlx_new_image(cub->p_mlx, X_WIN, Y_WIN);
	cub->player_mini_map.img = mlx_new_image(cub->p_mlx,
			cub->player_mini_map.x_xpm,
			cub->player_mini_map.y_xpm);
	cub->mini_map.img = mlx_new_image(cub->p_mlx,
			cub->player_mini_map.x_xpm,
			cub->player_mini_map.y_xpm);
	if (!(cub->bg.img) || !(cub->display.img) || !(cub->player_mini_map.img)
		|| !(cub->mini_map.img))
		return (1);
	cub->display.map = (t_color *) mlx_get_data_addr(cub->display.img,
			&(cub->display.bpp), &(cub->display.size_line),
			&(cub->display.endian));
	cub->player_mini_map.map
		= (t_color *) mlx_get_data_addr(cub->player_mini_map.img,
			&(cub->player_mini_map.bpp), &(cub->player_mini_map.size_line),
			&(cub->player_mini_map.endian));
	return (0);
}

void	ft_destroy_all_textures(t_cub *cub)
{
	ft_destroy_texture(cub, &(cub->surface.ea));
	ft_destroy_texture(cub, &(cub->surface.no));
	ft_destroy_texture(cub, &(cub->surface.so));
	ft_destroy_texture(cub, &(cub->surface.we));
	ft_destroy_texture(cub, &(cub->surface.door));
	ft_destroy_texture(cub, &(cub->mini_map));
	ft_destroy_texture(cub, &(cub->player_mini_map));
	ft_destroy_texture(cub, &(cub->bg));
	ft_destroy_texture(cub, &(cub->display));
}

int8_t	ft_get_textures(t_cub *cub)
{
	if (ft_fill_img(cub, &(cub->surface.ea))
		|| ft_fill_img(cub, &(cub->surface.no))
		|| ft_fill_img(cub, &(cub->surface.so))
		|| ft_fill_img(cub, &(cub->surface.we))
		|| ((cub->surface.door.file) && ft_fill_img(cub, &(cub->surface.door)))
		|| ft_get_img_win(cub)
		|| ft_img_opti_tab(cub))
	{
		ft_destroy_all_textures(cub);
		return (1);
	}
	return (0);
}
