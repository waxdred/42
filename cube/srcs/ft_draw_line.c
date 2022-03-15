
#include "../includes/cube.h"

static void	ft_init_draw(t_draw *draw, t_line *line)
{
	draw->i = 0;
	draw->ex = abs(line->x1 - line->x0);
	draw->ey = abs(line->y1 - line->y0);
	draw->dx = 2 * draw->ex;
	draw->dy = 2 * draw->ey;
	draw->Dx = draw->ex;
	draw->Dy = draw->ey;
	draw->Xincr = 1;
	draw->Yincr = 1;
	if (line->x0 > line->x1)
		draw->Xincr = -1;
	if (line->y0 > line->y1)
		draw->Yincr = -1;
}

static void	ft_draw_dx(t_cube *cube, t_draw *draw, t_line *line)
{
	while (draw->i <= draw->Dx)
	{
		mlx_pixel_put(cube->p_mlx, cube->p_win, line->x0, line->y0, line->color);
		draw->i++;
		line->x0 += draw->Xincr;
		draw->ex -= draw->dy;
		if (draw->ex < 0)
		{
			line->y0 += draw->Yincr;
			draw->ex += draw->dx;
		}
	}

}

static void	ft_draw_dy(t_cube *cube, t_draw *draw, t_line *line)
{
	while (draw->i <= draw->Dy)
	{
		mlx_pixel_put(cube->p_mlx, cube->p_win, line->x0, line->y0, line->color);
		draw->i++;
		line->y0 += draw->Yincr;
		draw->ey -= draw->dx;
		if (draw->ey < 0)
		{
			line->x0 += draw->Xincr;
			draw->ey += draw->dy;
		}
	}
}

int	ft_start_draw(t_line *line, int x0, int y0, int	color)
{
	line->x0 = x0;
	line->y0 = y0;
	line->color = color;
	return (1);
}

int	ft_end_draw(t_line *line, int x0, int y0)
{
	line->x1 = x0;
	line->y1 = y0;
	return (1);
}

void	ft_draw_line(t_cube *cube, t_line *line, int type)
{
	t_draw	draw;

	ft_init_draw(&draw, line);
	if (type == LINE && draw.Dx > draw.Dy)
		ft_draw_dx(cube, &draw, line);
	if (type == LINE && draw.Dx < draw.Dy)
		ft_draw_dy(cube, &draw, line);
}

void	ft_bresenham(t_cube *cube, int x0, int y0, int x1, int y1, int color)
{
	t_draw	draw;

	cube->line->x0 = x0;
	cube->line->x1 = x1;
	cube->line->y0 = x0;
	cube->line->y1 = y1;
	ft_init_draw(&draw, cube->line);
	if (draw.Dx > draw.Dy)
	{
		while (draw.i <= draw.Dx)
		{
			mlx_pixel_put(cube->p_mlx, cube->p_win, x0, y0, color);
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
			mlx_pixel_put(cube->p_mlx, cube->p_win, x0, y0, color);
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

