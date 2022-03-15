
#include "../includes/cube.h"

static void	put_pixel_mini_map(t_cube *cube, int x, int y, int color)
{
	int	i;

	i = (int)(SCALE * cube->mlx->wd_width) * y + x;
	cube->data[i] = color;
}

static void	put_pixel_bg(t_cube *cube, int x, int y, int color)
{
	int	i;

	i = cube->mlx->wd_width * y + x;
	cube->bg->data[i] = color;
}
void	fill_squares(t_cube *cube, int x, int y, int color)
{
	int i;
	int j;

	j = 0;
	while (j < (int)(SCALE * SQUARES) - 1)
	{
		i = 0;
		while (i < (int)(SCALE * SQUARES) - 1)
		{
			put_pixel_mini_map(cube, x + i, y + j, color);
			i++;
		}
		j++;
	}
	j = x;
}

void	ft_draw_minimap(t_cube *cube)
{
	int	x;
	int	y;
	int	k;

	cube->data = (int *)mlx_get_data_addr(cube->img, &(cube->bpp),
			&(cube->line_size), &(cube->endian));
	y = 0;
	k = 0;
	while (y < cube->mlx->wd_height * SCALE)
	{
		x = 0;
		while (x < cube->mlx->wd_width * SCALE)
		{
			if (cube->map[k] == 1)
				fill_squares(cube, (int)(SCALE * SQUARES * x),
					(int)(SCALE * SQUARES * y), 0xFFFFFF);
			else
				fill_squares(cube, (int)(SCALE * SQUARES * x),
					(int)(SCALE * SQUARES * y), 0x808080);
			x++;
			k++;
		}
		y++;

	}
}

void	ft_draw_background(t_mlx *mlx, t_cube *cube, t_color *color, t_bg *bg)
{
	t_rgb	grey;
	t_rgb	*b_color;
	int	x;
	int	y;

	grey.r = 228;
	grey.g = 228;
	grey.b = 228;
	bg->data = (int *)mlx_get_data_addr(bg->b_img, &(bg->bpp),
			&(bg->line_size), &(bg->endian));
	y = 0;
	float i = 0;
	while (y < cube->mlx->wd_height)
	{
		x = 0;
		while (x < cube->mlx->wd_width)
		{
			if (y <= mlx->wd_height / 2)
				put_pixel_bg(cube, x, y, color->sky);
			else if (y > mlx->wd_height / 2)
			{
				b_color = ft_change_bright_color(&grey, i);
				put_pixel_bg(cube, x, y, createRGB(b_color));
				free(b_color);
			}
			x++;
		}
		i += 0.015;
		y++;
	}
}

