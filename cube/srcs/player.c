
#include "../includes/cube.h"

static void	ft_position_player(t_cube *cube, t_player *player)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (cube->map[j])
	{
		if (cube->map[j][i] == 'N')
		{
			player->pos_x = i; 
			player->pos_y = j;
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

void	ft_player(t_cube *cube, t_player *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->scale)
	{
		j = 0;
		while (j < p->scale)
		{
			mlx_pixel_put(cube->p_mlx, cube->p_win, (i + p->pos_x
					- (p->scale / 2)) * SCALE,
					(j + p->pos_y - (p->scale / 2)) * SCALE, 0x66ffff);
			j++;
		}
		i++;
	}
	ft_start_draw(cube->line, p->pos_x * SCALE, p->pos_y * SCALE, createRGB(cube->color->sky));
	ft_end_draw(cube->line, (p->pos_x + p->dp_x * 5) * SCALE, (p->pos_y + p->dp_y * 5) * SCALE);
	ft_draw_line(cube, cube->line, LINE);
	/* ft_bresenham(cube, p->pos_x * SCALE, p->pos_y *SCALE, */
	/* 		(p->pos_x + p->dp_x * 5) * SCALE, */
	/* 		   (p->pos_y + p->dp_y * 5) * SCALE, 0x000000); */
}
