
#include "../includes/cube.h"

static void	ft_position_player(t_cube *cube, t_player *player)
{
	int	j;

	j = 0;
	while (j < cube->i_map->mapY * cube->i_map->mapX)
	{
		if (cube->map[j] == 2)
		{
			player->pos_x = j % cube->i_map->mapX; 
			player->pos_y = j / cube->i_map->mapX;
			player->pos_x *= (int)(SQUARES); 
			player->pos_y *= (int)(SQUARES);
			player->pos_x += (int)(SQUARES / 2); 
			player->pos_y += (int)(SQUARES / 2);
		}
		j++;
	}
}

void	ft_init_player(t_cube *cube)
{
	cube->player = ft_track(ft_memalloc(sizeof(t_player)), &cube->track);
	ft_position_player(cube, cube->player);
	cube->player->pa = 0;
	cube->player->dp_x = cos(cube->player->pa) * 5;
	cube->player->dp_y = sin(cube->player->pa) * 5;
	cube->player->scale = 10;
	cube->player->speed = 1;
}

void	ft_player(t_cube *cube, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (i < player->scale)
	{
		j = 0;
		while (j < player->scale)
		{
			mlx_pixel_put(cube->mlx->mlx, cube->mlx->win, (i + player->pos_x
					- (player->scale / 2)) * SCALE,
					(j + player->pos_y - (player->scale / 2)) * SCALE, 0x66ffff);
			j++;
		}
		i++;
	}
	ft_bresenham(cube, player->pos_x * SCALE, player->pos_y *SCALE,
			(player->pos_x + player->dp_x * 5) * SCALE,
			   (player->pos_y + player->dp_y * 5) * SCALE, 0x000000);
}
