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
	tab = (int **)malloc(sizeof(tab) * y);
	if (!tab)
		return (NULL);
	tab2 = (int *)malloc(sizeof(tab2) * (x * y));
	if (!tab2)
		return (NULL);
	while (i < y)
	{
		tab[i] = &tab2[i * x];
		tab[0][0] = 1000;
		i++;
	}
	return (tab);
}
