
#include "../includes/cube.h"

void	ft_init(t_cube *cube, t_color *color)
{
	cube->wd_width = 600;
	cube->wd_height = 600;
	color->no = ft_track(ft_memalloc(sizeof(t_rgb)), &cube->track);
	ft_set_rgb(color->no, 150, 150, 255);
	color->so = ft_track(ft_memalloc(sizeof(t_rgb)), &cube->track);
	ft_set_rgb(color->so, 150, 150, 255);
	color->we = ft_track(ft_memalloc(sizeof(t_rgb)), &cube->track);
	ft_set_rgb(color->we, 150, 150, 255);
	color->ae = ft_track(ft_memalloc(sizeof(t_rgb)), &cube->track);
	ft_set_rgb(color->ae, 150, 150, 255);
	if (!cube->text->c)
	{
		color->sky = ft_track(ft_memalloc(sizeof(t_rgb)), &cube->track);
		ft_set_rgb(color->sky, 0, 255, 255);
	}
	if (!cube->text->f)
	{
		color->sky = ft_track(ft_memalloc(sizeof(t_rgb)), &cube->track);
		ft_set_rgb(color->sky, 128, 128, 128);
	}
}

void	ft_reaload(t_cube *cube)
{
	mlx_clear_window(cube->p_mlx, cube->p_win);
	mlx_put_image_to_window(cube->p_mlx, cube->p_win, cube->bg->b_img, 0, 0);
	draw_ray_3d(cube, cube->player);
	mlx_put_image_to_window(cube->p_mlx, cube->p_win, cube->img, 0, 0);
	ft_player(cube, cube->player);
}

void	ft_mlx(t_cube *cube)
{
	ft_init_player(cube);
	cube->bg = ft_track(ft_memalloc(sizeof(t_bg)), &(cube)->track);
	cube->line = ft_track(ft_memalloc(sizeof(t_line)), &(cube)->track);
	cube->p_mlx = mlx_init();
	cube->p_win = mlx_new_window(cube->p_mlx, cube->wd_width, cube->wd_height, "cube");
	cube->img = mlx_new_image(cube->p_mlx, (int)(cube->wd_width * SCALE), (int)(cube->wd_height * SCALE));
	cube->bg->b_img = mlx_new_image(cube->p_mlx, (int)(cube->wd_width), (int)(cube->wd_height));
	ft_draw_background(cube, cube->bg);
	ft_draw_minimap(cube);
	mlx_put_image_to_window(cube->p_mlx, cube->p_win, cube->bg->b_img, 0, 0);
	draw_ray_3d(cube, cube->player);
	mlx_put_image_to_window(cube->p_mlx, cube->p_win, cube->img, 0, 0);
	ft_player(cube, cube->player);
	mlx_do_key_autorepeatoff(cube->p_mlx);
	mlx_key_hook(cube->p_win, deal_key, cube);
	mlx_loop(cube->p_mlx);
}
