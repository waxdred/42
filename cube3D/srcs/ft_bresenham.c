
#include "../includes/cube.h"

void	ft_draw_wall(t_cube *cube, int x0, int y0, int y1, int color)
{
	int	n_x0;
	int	nb_pix;
	int	i;
	int	j;

	nb_pix = y0 - y1;
	n_x0 = x0 - 4;
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < nb_pix)
		{
			mlx_pixel_put(cube->mlx->mlx, cube->mlx->win, n_x0 + i, y0 + j, color);
			j++;
		}
		i++;
	}
}

static void	ft_init_draw(t_draw *draw, int x0, int x1, int y0, int y1)
{
	draw->i = 0;
	draw->ex = abs(x1 - x0);
	draw->ey = abs(y1 - y0);
	draw->dx = 2 * draw->ex;
	draw->dy = 2 * draw->ey;
	draw->Dx = draw->ex;
	draw->Dy = draw->ey;
	draw->Xincr = 1;
	draw->Yincr = 1;
	if (x0 > x1)
		draw->Xincr = -1;
	if (y0 > y1)
		draw->Yincr = -1;
}

void	ft_bresenham(t_cube *cube, int x0, int y0, int x1, int y1, int color)
{
	t_draw	draw;

	ft_init_draw(&draw, x0, x1, y0, y1);
	if (draw.Dx > draw.Dy)
	{
		while (draw.i <= draw.Dx)
		{
			mlx_pixel_put(cube->mlx->mlx, cube->mlx->win, x0, y0, color);
			draw.i++;
			x0 += draw.Xincr;
			draw.ex -= draw.dy;
			if (draw.ex < 0)
			{
				y0 += draw.Yincr;
				draw.ex += draw.dx;
			}
		}
	}
	if (draw.Dx < draw.Dy)
	{
		while (draw.i <= draw.Dy)
		{
			mlx_pixel_put(cube->mlx->mlx, cube->mlx->win, x0, y0, color);
			draw.i++;
			y0 += draw.Yincr;
			draw.ey -= draw.dx;
			if (draw.ey < 0)
			{
				x0 += draw.Xincr;
				draw.ey += draw.dy;
			}
		}
	}
}
