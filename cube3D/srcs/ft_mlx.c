
#include "../includes/cube.h"

void	ft_reaload(t_cube *cube)
{
	mlx_clear_window(cube->mlx->mlx, cube->mlx->win);
	mlx_put_image_to_window(cube->mlx->mlx, cube->mlx->win, cube->bg->b_img, 0, 0);
	draw_ray_3d(cube, cube->player);
	mlx_put_image_to_window(cube->mlx->mlx, cube->mlx->win, cube->img, 0, 0);
	ft_player(cube, cube->player);
}
void	ft_mlx(t_cube *cube, t_mlx *mlx)
{
	cube->bg = ft_track(ft_memalloc(sizeof(t_bg)), &(cube)->track);
	cube->key = ft_track(ft_memalloc(sizeof(t_key)), &(cube)->track);
	ft_init_player(cube);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, cube->mlx->wd_width, cube->mlx->wd_height, "cube");
	cube->img = mlx_new_image(mlx->mlx, (int)(mlx->wd_width * SCALE), (int)(mlx->wd_height * SCALE));
	cube->bg->b_img = mlx_new_image(mlx->mlx, (int)(mlx->wd_width), (int)(mlx->wd_height));
	cube->color->sky = 0x00FFFF;
	cube->color->ground = 0x808080;
	printf("screen:\n\twidth %d\n\theight %d", cube->mlx->wd_width, cube->mlx->wd_height);
	ft_draw_background(mlx, cube, cube->color, cube->bg);
	ft_draw_minimap(cube);
	mlx_put_image_to_window(mlx->mlx, mlx->win, cube->bg->b_img, 0, 0);
	draw_ray_3d(cube, cube->player);
	mlx_put_image_to_window(mlx->mlx, mlx->win, cube->img, 0, 0);
	ft_player(cube, cube->player);
	mlx_key_hook(mlx->win, deal_key, cube);
	mlx_loop(mlx->mlx);
}
