
#include "../includes/cube.h"
int	main(int ac, char **av)
{
	t_cube	cube;

	if (ac != 2)
	{
		ft_putstr_fd("Error arguments", 2);
		return (1);
	}
	cube.track = ft_memalloc(sizeof(t_track));
	cube.i_map = ft_track(ft_memalloc(sizeof(t_map)), &cube.track);
	cube.color = ft_track(ft_memalloc(sizeof(t_color)), &cube.track);
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
	ft_init(&cube, cube.color);
	ft_mlx(&cube);
	return(0);
}

