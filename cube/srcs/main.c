/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:23:20 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/19 23:28:57 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_reload(t_cub *cub)
{
	t_wall	*tmp;

	mlx_clear_window(cub->p_mlx, cub->p_win);
	ft_reinit_display(cub);
	ft_reinit_minimap(cub);
	ft_player(cub, &cub->player);
	draw_ray_3d(cub, &cub->player);
	ft_init_start_walls(cub->walls);
	tmp = cub->walls;
	while (tmp)
	{
		ft_get_wall_img(cub, tmp);
		ft_debeug_draw(cub, tmp);
		tmp = tmp->next;
		ft_track_free(&(cub->track), cub->walls);
		cub->walls = tmp;
	}
	mlx_put_image_to_window(cub->p_mlx, cub->p_win, cub->display.img, 0, 0);
	ft_show_map(cub);
}

int	ft_init_cub3d(t_cub *cub, const char *file)
{
	if (ft_parsing(cub, file) || !ft_init_scale(cub))
		return (1);
	if (!ft_check_pos_player(&cub->player) || !ft_map_in_string(cub))
	{
		ft_track_free_all(&(cub->track));
		return (1);
	}
	cub->p_mlx = mlx_init();
	if (ft_get_textures(cub))
	{
		ft_destroy_all_textures(cub);
		ft_track_free_all(&(cub->track));
		return (1);
	}
	cub->p_win = mlx_new_window(cub->p_mlx, X_WIN, Y_WIN, "cub3D");
	if (!(cub->p_win))
	{
		ft_destroy_all_textures(cub);
		mlx_destroy_window(cub->p_mlx, cub->p_win);
		ft_track_free_all(&(cub->track));
		return (1);
	}
	return (0);
}

void	ft_hooks(t_cub *cub)
{
	mlx_hook(cub->p_win, KEY_PRESS, KEY_PRESSMASK, ft_key_hit, cub);
	mlx_hook(cub->p_win, KEY_RELEASE, KEY_RELEASEMASK, ft_key_release, cub);
	mlx_hook(cub->p_win, MOUSE_PRESS, 1L >> 6, ft_mouse_hit, cub);
	mlx_hook(cub->p_win, MOUSE_RELEASE, 1L >> 7, ft_mouse_release, cub);
	mlx_hook(cub->p_win, 17, 1L << 2, &ft_escape, cub);
	mlx_loop_hook(cub->p_mlx, deal_key, cub);
	mlx_loop(cub->p_mlx);
}

int	main(int argc, char const *argv[])
{
	t_cub	cub;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./cub3D map.cub\n", 2);
		return (EXIT_FAILURE);
	}
	errno = 0;
	ft_bzero(&cub, sizeof(t_cub));
	cub.track = ft_memalloc(sizeof(t_track));
	if (!(cub.track) || ft_init_cub3d(&cub, argv[1]))
		exit(EXIT_FAILURE);
	ft_init_player(&cub);
	cub.r_dist = ft_get_dist_max(&cub);
	ft_draw_background(&cub, &(cub.bg));
	ft_draw_minimap(&cub);
	ft_reload(&cub);
	ft_hooks(&cub);
	ft_destroy_all_textures(&cub);
	mlx_destroy_window(cub.p_mlx, cub.p_win);
	ft_track_free_all(&(cub.track));
	exit(EXIT_SUCCESS);
}
