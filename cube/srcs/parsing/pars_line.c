/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:22:15 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/14 05:25:39 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int8_t	ft_pars_meta2(t_cub *cub, char *line)
{
	if (ft_str_start_with(line, "SO"))
	{
		cub->check_parsing |= 0b10000;
		return (ft_add_texture(cub, &(cub->surface.so), line, "SO"));
	}
	else if (ft_str_start_with(line, "NO"))
	{
		cub->check_parsing |= 0b100000;
		return (ft_add_texture(cub, &(cub->surface.no), line, "NO"));
	}
	else if (ft_str_start_with(line, "D"))
		return (ft_add_texture(cub, &(cub->surface.door), line, "D"));
	if (cub->check_parsing != 0b111111)
	{
		ft_putstr_fd("Error\nParsing: meta data missing\n", 2);
		return (1);
	}
	cub->check_parsing |= 0b1000000;
	return (ft_add_map(cub, line));
}

static int8_t	ft_pars_meta(t_cub *cub, char *line)
{
	if (ft_str_start_with(line, "C"))
	{
		cub->check_parsing |= 0b1;
		return (ft_add_color(&(cub->surface.ceiling), line, "C"));
	}
	else if (ft_str_start_with(line, "F"))
	{
		cub->check_parsing |= 0b10;
		return (ft_add_color(&(cub->surface.floor), line, "F"));
	}
	else if (ft_str_start_with(line, "EA"))
	{
		cub->check_parsing |= 0b100;
		return (ft_add_texture(cub, &(cub->surface.ea), line, "EA"));
	}
	else if (ft_str_start_with(line, "WE"))
	{
		cub->check_parsing |= 0b1000;
		return (ft_add_texture(cub, &(cub->surface.we), line, "WE"));
	}
	return (ft_pars_meta2(cub, line));
}

int8_t	ft_pars_line(t_cub *cub, char *line)
{
	if (ft_first_elem(line) == NULL)
	{
		if (cub->map)
		{
			ft_putstr_fd("Error\nParsing: Empty line after or in the map\n", 2);
			return (1);
		}
		return (0);
	}
	if (cub->map)
		return (ft_add_map(cub, line));
	return (ft_pars_meta(cub, line));
}
