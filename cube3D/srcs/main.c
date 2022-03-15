#include "../includes/cube.h"

void ft_init_size(t_mlx *mlx, t_cube *cube)
{
	/* mlx->wd_width = (int)(cube->i_map->mapX * SQUARES); */
	/* mlx->wd_height = (int)(cube->i_map->mapY * SQUARES); */
	mlx->wd_width = 1090;
	mlx->wd_height = 600;
	cube->mlx = mlx;
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_cube	cube;

	if (ac != 2)
	{
		ft_putstr_fd("Error arguments", 2);
		return (1);
	}
	cube.track = ft_memalloc(sizeof(t_track));
	cube.i_map = ft_track(ft_memalloc(sizeof(t_map)), &cube.track);
	if (!cube.i_map || !cube.track)
	{
		ft_track_free_all(&cube.track);
		return (1);
	}
	if (!ft_pars_map(&cube, av[1]))
	{
		ft_putstr_fd("Error map:/n", 2);
		ft_track_free_all(&cube.track);
		return (1);
	}
	ft_init_size(&mlx, &cube);
	ft_mlx(&cube, &mlx);
	return(0);
}
