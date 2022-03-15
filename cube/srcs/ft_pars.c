
#include "../includes/cube.h"
#include <sys/fcntl.h>

void	ft_get_option(t_texture *t, t_track *tr, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (ft_isa_white_space(line[i]))
			i++;
		if (line[i] && line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
			t->no = ft_track(ft_strndup(line + 1 + 1, ft_strichr(line, '\n')), &tr); 
		else if (line[i] && line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
			t->so = ft_track(ft_strndup(line + 1 + 1, ft_strichr(line, '\n')), &tr); 
		else if (line[i] && line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
			t->we = ft_track(ft_strndup(line + 1 + 1, ft_strichr(line, '\n')), &tr); 
		else if (line[i] && line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
			t->ea = ft_track(ft_strndup(line + 1 + 1, ft_strichr(line, '\n')), &tr); 
		else if (line[i] && line[i] == 'F' && line[i + 1] == ' ')
			t->f = ft_track(ft_strndup(line + 1 + 1, ft_strichr(line, '\n')), &tr); 
		else if (line[i] && line[i] == 'C' && line[i + 1] == ' ')
			t->c = ft_track(ft_strndup(line + 1 + 1, ft_strichr(line, '\n')), &tr); 
		free(line);
		line = get_next_line(fd);
	}
}

int	ft_add_color(t_cube *cube, t_texture *text, t_track *t)
{
	char	**tmp;

	if (text->c)
	{
		cube->color->sky = ft_track(ft_memalloc(sizeof(t_rgb)), &t);
		tmp = ft_strsplit(text->c, ',');
		ft_track_tab((void **)tmp, &t);
		if (!ft_add_color_rgb(tmp, cube->color->sky))
			return (0);
	}
	if (text->f)
	{
		cube->color->ground = ft_track(ft_memalloc(sizeof(t_rgb)), &t);
		tmp = ft_split(text->f, ',');	
		ft_track_tab((void **)tmp, &t);
		if (!ft_add_color_rgb(tmp, cube->color->ground))
			return (0);
	}
	return (1);
}

int	ft_len_y_map(int fd)
{
	char	*line;
	int		ret;

	ret = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (check_map_line(line))
			ret++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (ret);
}

int	ft_add_map(t_cube *cube, int fd, char *dir)
{
	char	*line;
	int		i;

	i = 0;
	cube->map = (char **)ft_memalloc(sizeof(char *) * (ft_len_y_map(fd) + 1));
	if (!cube->map)
		return (0);
	close(fd);
	fd = open(dir,O_RDONLY);
	line = get_next_line(fd);
	printf("test\n");
	while (line)
	{
		if (check_map_line(line) && !ft_get_map_line(cube, line, &i))
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	ft_track_tab((void **)cube->map, &cube->track);
	close(fd);
	return (1);
}

int	ft_pars_map(t_cube *cube, char *path)
{
	int			fd;

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
	cube->text = ft_track(ft_memalloc(sizeof(t_texture)), &(cube->track));
	ft_get_option(cube->text, cube->track, fd);
	if (!ft_add_color(cube, cube->text, cube->track)   /*|| !ft_check_dir_t(cube->text)*/)
		return (0);
	close(fd);
	fd = open(path, O_RDONLY);
	if (!ft_add_map(cube, fd, path))
	{
		ft_track_free_all(&cube->track);
		return (0);
	}
	return (1);	
}

