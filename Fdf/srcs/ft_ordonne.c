


#include "../includes/fdf.h"

void	ft_draw_tab(t_env *fdf, int i, int j)
{
	j = 0;
	while (j < fdf->map.nbcol - 1)
	{
		i = 0;
		while (i < fdf->map.nblin - 2)
		{
			fdf->p.x1 = fdf->map.Ox[i][j];
			fdf->p.y1 = fdf->map.Oy[i][j];
			fdf->p.x2 = fdf->map.Ox[i + 1][j];
			fdf->p.y2 = fdf->map.Oy[i + 1][j];
			ft_bresenham(fdf);
			i++;
		}
		j++;
	}
}

void	ft_add_ord(t_env *fdf, int i, int j)
{
	if (j == 0)
	{
		fdf->map.Ox[i][j] = fdf->mov.s_x + (fdf->p.spc * i);
		fdf->map.Oy[i][j] = fdf->mov.s_y + ((fdf->p.spc * i) / 2);
	}
	else
	{
		fdf->map.Ox[i][j] = fdf->p.x1;
		fdf->map.Oy[i][j] = fdf->p.y1;
	}
}

int	ft_init_ord(t_env *fdf)
{
	fdf->map.Ox = ft_tabnew_two(fdf->map.nbcol, fdf->map.nblin);
	fdf->map.Oy = ft_tabnew_two(fdf->map.nbcol, fdf->map.nblin);
	if (!fdf->map.Ox || !fdf->map.Oy)
		return (-1);
	return (0);
}
