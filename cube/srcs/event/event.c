/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:52:14 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/19 23:24:45 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_escape(t_cub *cube)
{
	ft_destroy_all_textures(cube);
	mlx_destroy_window(cube->p_mlx, cube->p_win);
	ft_track_free_all(&cube->track);
	exit (0);
	return (0);
}

int	norminette_key(t_cub *c)
{
	if (c->inter.key[Z] || c->inter.key[S]
		|| c->inter.key[AU] || c->inter.key[AD])
		ft_move(c);
	return (0);
}

int	deal_key(t_cub *c)
{
	norminette_key(c);
	if (c->inter.key[AL] || c->inter.key[AR])
		ft_rotate(c);
	if (c->inter.key[Q] || c->inter.key[D])
		ft_translate(c);
	if (c->inter.key[ESC])
		ft_escape(c);
	if (c->inter.key[ESP] == 1)
		ft_door_key(c);
	if (!c->inter.key[ESP])
		ft_option_door(c);
	if (c->inter.key[M] == 1)
		ft_mini_map_key(c);
	if (!c->inter.key[M])
		ft_option_map(c);
	if (c->inter.key[T] == 1)
		ft_debeug_key(c);
	if (!c->inter.key[T])
		ft_option_debeug(c);
	if (c->inter.mouse.button[L_CLICK])
		ft_rotate_mouse(c, &c->inter.mouse);
	return (1);
}

void	ft_debeug_draw(t_cub *cub, t_wall *tmp)
{
	int	i;

	i = -1;
	if (cub->inter.activ_debeug.active == 1)
	{
		while (++i < 10)
		{
			ft_start_draw(&(cub->line), (int)(tmp->origin.x), i, 0xFF00);
			ft_end_draw(&(cub->line), (int)(tmp->origin.x + tmp->width_img), i);
			ft_draw_line_img(&(cub->line), LINE, &(cub->display));
		}
		ft_start_draw(&(cub->line), (int)(tmp->origin.x),
			(int)(tmp->origin.y + tmp->l_heigth), 0xFF);
		ft_end_draw(&(cub->line), (int)(tmp->origin.x + tmp->width_img),
			(int)(tmp->origin.y + tmp->l_heigth));
		ft_draw_line_img(&(cub->line), LINE, &(cub->display));
		ft_start_draw(&(cub->line), (int)(tmp->origin.x + tmp->width_img / 2),
			15, 0xFF0000);
		ft_end_draw(&(cub->line), (int)(tmp->origin.x + tmp->width_img / 2),
			Y_WIN - 1);
		ft_draw_line_img(&(cub->line), LINE, &(cub->display));
	}
}

void	ft_show_map(t_cub *cub)
{
	if (cub->inter.activ_map.active == 1)
		mlx_put_image_to_window(cub->p_mlx, cub->p_win,
			cub->player_mini_map.img, 0, 0);
}
