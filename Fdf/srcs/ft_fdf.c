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

int	ft_fdf(char *argv)
{
	t_env	fdf;

	ft_bzero(&fdf, sizeof(t_env));
	ft_create_map(argv, &fdf);
	ft_mlx(&fdf, argv);
	ft_free_map(&fdf);
	free(*(fdf.map.map));
	ft_bzero(&fdf, sizeof(t_env));
	return (0);
}
