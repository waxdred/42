/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <x@student.42lyon.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:21:45 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/20 19:36:11 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief check if the character is a space
 * 
 * @param c the character
 * @return int8_t 1 if true, 0 else
 */
int8_t	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == ' '
		|| c == '\f');
}

/**
 * @brief say where the line start
 * 
 * @param line the line of the file
 * @return char* NULL if the line haven't any info, else a pointer on the first
 * element of the line
 */
char	*ft_first_elem(char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line))
			return (line);
		++line;
	}
	return (NULL);
}

/**
 * @brief check if a string start with the string that we want
 * 
 * @param str the string that will be check
 * @param to_find the string that we want at the start
 * @return int8_t 1 if str start with to_find, else 0
 */
int8_t	ft_str_start_with(char *str, char *to_find)
{
	size_t	j;

	j = 0;
	while (str[j] && to_find[j] && str[j] == to_find[j])
		++j;
	if (to_find[j] == 0)
		return (1);
	return (0);
}

size_t	ft_nb_size(char *line)
{
	size_t	i;

	i = 0;
	while (ft_isdigit(line[i]))
		++i;
	return (i);
}

int8_t	ft_check_texture(t_cub *cub)
{
	int	fd[5];

	fd[0] = open((cub->surface).ea.file, O_RDONLY);
	fd[1] = open((cub->surface).we.file, O_RDONLY);
	fd[2] = open((cub->surface).so.file, O_RDONLY);
	fd[3] = open((cub->surface).no.file, O_RDONLY);
	fd[4] = -1;
	if ((cub->surface).door.file)
		fd[4] = open((cub->surface).door.file, O_RDONLY);
	if (fd[0] < 0 || fd[1] < 0 || fd[2] < 0 || fd[3] < 0
		|| ((cub->surface).no.file && fd[4] < 0))
	{
		ft_putstr_fd("Error\nParsing texture: ", 2);
		perror(NULL);
		return (1);
	}
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	if ((cub->surface).door.file)
		close(fd[4]);
	return (0);
}
