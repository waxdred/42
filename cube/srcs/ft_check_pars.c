
#include "../includes/cube.h"
#include <sys/fcntl.h>

int	ft_get_map_line(t_cube *cube, char *line, int *index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	cube->map[*index] = (char *)ft_memalloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!cube->map[*index])
		return (0);
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'S'
				|| line[i] == 'N' || line[i] == 'W' || line[i] == 'E')
			cube->map[*index][j++] = line[i];
		i++;
	}
	cube->map[*index][j++] = '\0';
	*index += 1;
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

static int	check_dir(char *dir)
{
	int	fd;


	fd = open(dir, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	check_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '1' || line[i] == '0' || line [i] == ' '
				|| line[i] == 'S' || line[i] == 'N'
				|| line[i] == 'E' || line[i] == 'W')
			i++;
		else
		 	return (0);
	}
	return (1);
}

int	ft_check_dir_t(t_texture *t)
{
	if (t->no && !check_dir(t->no))
		return (0);
	if (t->so && !check_dir(t->so))
		return (0);
	if (t->we && !check_dir(t->we))
		return (0);
	if (t->ea && !check_dir(t->ea))
		return (0);
	return (1);
}
