/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:31:06 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/07 19:00:32 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/get_next_line.h"

int main(int argv, char **argc)
{
	int fd;

	if (argv < 1)
	{
		ft_putstr_fd("create function when no arg", 1);
	}
	if (argv >= 1)
	{
		ft_putstr_fd(argc[2], 1);
		ft_putchar_fd('\n', 1);
		fd = open(argc[1], O_RDONLY);
		ft_putnbr_fd(fd, 1);
	}
	return (0);
}
