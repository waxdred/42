/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:22:30 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/09 05:22:33 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int8_t	ft_check_color_syntax(char *line)
{
	size_t	len;
	char	i;

	i = 0;
	while (i < 3)
	{
		line = ft_first_elem(line);
		if (!line)
			return (1);
		if (i == 0 && !ft_isdigit(*line))
			return (1);
		if (i && *line != ',')
			return (1);
		if (i)
			++line;
		len = ft_nb_size(line);
		if (len > 3)
			return (1);
		line = line + len;
		++i;
	}
	if (ft_first_elem(line))
		return (1);
	return (0);
}

static int8_t	ft_get_color(t_color *color, char *line)
{
	size_t	len;
	int8_t	i;
	int		tmp;

	i = R_COL;
	while (i > 0)
	{
		line = ft_first_elem(line);
		if (i != R_COL)
			++line;
		tmp = ft_atoi(line);
		if (tmp > 255 || tmp < 0)
			return (1);
		(color->str)[i] = (unsigned char)tmp;
		len = ft_nb_size(line);
		line = line + len;
		--i;
	}
	return (0);
}

int8_t	ft_add_color(t_color *color, char *line, const char *key)
{
	size_t	i;

	i = 0;
	while (key[i] && line[i] == key[i])
		++i;
	if (key[i] && !ft_isspace(line[i]))
	{
		ft_putstr_fd("Error\nParsing: Identification of the color is \
			incorrect (order is important)\n", 2);
		return (1);
	}
	if (ft_check_color_syntax(line + i + 1))
	{
		ft_putstr_fd("Error\nParsing: Syntax of the color is \
			incorrect (R,G,B)\n", 2);
		return (1);
	}
	if (ft_get_color(color, line + i + 1))
	{
		ft_putstr_fd("Error\nParsing: (R,G,B) each color [0,255]\n", 2);
		return (1);
	}
	return (0);
}
