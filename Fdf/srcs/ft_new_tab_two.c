/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_tab_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:13:50 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/20 01:13:50 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	**ft_tabnew_two(size_t x, size_t y)
{
	size_t	i;
	int		**tab;
	int		*tab2;

	i = 0;
	if (!(tab = (int**)malloc(sizeof(tab) * y)))
		return (NULL);
	if (!(tab2 = (int*)malloc(sizeof(tab2) * (x * y))))
		return (NULL);
	while (i < y)
	{
		tab[i] = &tab2[i * x];
		i++;
	}
	return (tab);
}
