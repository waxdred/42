/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:14:33 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/05 17:13:34 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("Usage : ./fdf <filename> \n");
		exit(EXIT_FAILURE);
	}
	else
		ft_fdf(argv[1]);
	return (0);
}
