/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:43:54 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/20 00:43:54 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_printmap(t_env *fdf)
{
	int i;
	int j;

	i = 0;
	printf("Affichage de la map \n\n");
	while (i < fdf->map.y)
	{
		j = 0;
		while (j < fdf->map.x)
		{
			if (fdf->map.map[i][j] < 10)
				printf(" ");
			printf(" %d ", fdf->map.map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

int	ft_fdf(char *argv)
{
	t_env	fdf;

	ft_bzero(&fdf, sizeof(t_env));
	ft_create_map(argv, &fdf);
	ft_create_map_or(&fdf);
	ft_mlx(&fdf, argv);
	ft_free_map(&fdf);
	free(*(fdf.map.map));
	ft_bzero(&fdf, sizeof(t_env));
	return (0);
}
