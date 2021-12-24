/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:36:42 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/23 20:36:42 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stack_sort(t_pile **pa, t_pile **pb, t_swap *env)
{

}

int	ft_unit(t_pile **stack, t_swap *env, int unit)
{
	t_pile	*elem;
	int	i;

	i = 0;
	elem = *stack;
	while (elem->next != NULL)
	{
		if (elem->binary[unit] == 0)
			i++;
		elem = elem->next;
	}
	if (elem->binary[unit] == 0)
		i++;
	return (i);
}
