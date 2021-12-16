/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:02:07 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/21 19:02:07 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				max;

	if (len == 0)
		return (0);
	i = 1;
	max = *tab;
	while (i != len)
	{
		if (max < *(tab + i))
			max = *(tab + i);
		i++;
	}
	return (max);
}
