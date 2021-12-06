/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:31:47 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/05 17:46:27 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_free_map(t_env *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->map.y - 1)
	{
		free(fdf->map.map[i]);
		i++;
	}
	return (0);
}
