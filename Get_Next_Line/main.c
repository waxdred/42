/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 22:56:14 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/14 22:56:32 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int main(int argv, char **argc)
{
	int fd;
	int i = 0;
	char *line;

	if (argv >= 1)
	{
		fd = open(argc[1], O_RDONLY);
		while (i++ < 10000)
		{
			line = get_next_line(fd);
			printf("%s", line);
			if (!line)
			{
				free(line);
				return(0);
			}
			free(line);
		}
	}
	return (0);
}
