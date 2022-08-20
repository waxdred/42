/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:21:59 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/09 05:22:01 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int8_t	ft_check_file_syntax(t_cub *cub, t_texture *text, char *line)
{
	size_t	i;
	char	*file;

	line = ft_first_elem(line);
	if (!line)
		return (1);
	file = ft_track(ft_strtrim(line, SPACES), &(cub->track));
	if (!file)
		return (2);
	i = 0;
	while (file[i] && !ft_isspace(file[i]))
		++i;
	if (file[i] || !i)
		return (1);
	if (text->file)
		ft_track_free(&(cub->track), text->file);
	text->file = file;
	return (0);
}

int8_t	ft_add_texture(t_cub *cub, t_texture *text, char *line, const char *key)
{
	size_t	i;
	int8_t	ret;

	i = 0;
	while (key[i] && line[i] == key[i])
		++i;
	if (key[i] && !ft_isspace(line[i]))
	{
		ft_putstr_fd("Error\nParsing: Identification of the texture is \
			incorrect (space is important)\n", 2);
		return (1);
	}
	ret = ft_check_file_syntax(cub, text, line + i + 1);
	if (ret == 1)
	{
		ft_putstr_fd("Error\nParsing: Syntax of the texture is \
			incorrect (ID path)\n", 2);
		return (1);
	}
	else if (ret)
		return (1);
	return (0);
}
