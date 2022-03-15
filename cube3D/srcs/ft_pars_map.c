
#include "../includes/cube.h"
#include <sys/fcntl.h>

int	ft_init_i_map(t_map *map, int fd)
{
	char	*line;
	line = get_next_line(fd);
	if (line)
		map->mapX = ft_strlen(line) - 1;
	while (line)
	{
		map->mapY++;
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	ft_check_extension(char *path)
{
	int	i;

	i = ft_strlen(path);
	while (i >= 0)
	{
		if (path[i] == '.' && !ft_strcmp(path + i, ".cub"))
			return (1);
		i--;
	}
	return (0);
}

int	ft_add_map(t_cube *cube, int fd)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	cube->map = (int *)ft_memalloc(sizeof(int) * ((cube->i_map->mapY * cube->i_map->mapX) + 1));
	if (!cube->map)
		return (0);
	ft_track(cube->map, &(cube)->track);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (ft_isdigit(line[i]))
			{
				cube->map[j] = line[i] - '0';
				j++;
			}
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	ft_pars_map(t_cube *cube, char *path)
{
	int	fd;

	if (!ft_check_extension(path))
	{
		ft_putstr_fd("Error extension files:\n", 2);
		return (0);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error files not found:\n", 2);
		return (0);
	}
	if (!ft_init_i_map(cube->i_map, fd))
		return (0);
	close(fd);
	fd = open(path, O_RDONLY);
	if (!ft_add_map(cube, fd))
	{
		ft_track_free_all(&cube->track);
		return (0);
	}
	return (1);	
}
