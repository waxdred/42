
#include "../includes/cube.h"

int	ft_escape(t_cube *cube, int key)
{
	if (key == ESC)
	{
		mlx_destroy_image(cube->p_mlx, cube->img);
		mlx_destroy_image(cube->p_mlx, cube->bg->b_img);
		mlx_destroy_window(cube->p_mlx, cube->p_win);
		ft_track_free_all(&cube->track);
		exit (0);
	}
	return (0);
}

int	ft_move(t_cube *cube, int key)
{
	if (key == Q)
	{
		cube->player->pa -= 0.1;
		if (cube->player->pa < 0)
			cube->player->pa += 2 * PI;
		cube->player->dp_x = cos(cube->player->pa) * 5;
		cube->player->dp_y = sin(cube->player->pa) * 5;

	}
	else if (key == D)
	{
		cube->player->pa += 0.1;
		if (cube->player->pa > 2 * PI)
			cube->player->pa -= 2 * PI;
		cube->player->dp_x = cos(cube->player->pa) * 5;
		cube->player->dp_y = sin(cube->player->pa) * 5;
	}
	else if (key == Z)
	{
		cube->player->pos_x += cube->player->dp_x * cube->player->speed;
		cube->player->pos_y += cube->player->dp_y * cube->player->speed;
	}
	else if (key == S)
	{
		cube->player->pos_x -= cube->player->dp_x * cube->player->speed;
		cube->player->pos_y -= cube->player->dp_y * cube->player->speed;
	}
	else
		return (1);
	ft_reaload(cube);
	return (0);
}

int	deal_key(int key, t_cube *cube)
{
	if (key == ESC)
		ft_escape(cube, key);
	if (key == Z || key == S || key == Q || key == D)
		ft_move(cube, key);
	return (0);
}
