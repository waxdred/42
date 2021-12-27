/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:17:54 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/18 01:17:54 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_end_sort(t_pile **stack, t_swap *env)
{
	t_pile	*elem;
	int		i;

	i = 0;
	elem = *stack;
	while (elem->next != NULL)
	{
		if (elem->index < elem->next->index)
			i++;
		elem = elem->next;
	}
	if (i == env->len - 1)
		return (1);
	return (0);
}

int	ft_end_index(t_pile **stack)
{
	t_pile	*elem;

	elem = *stack;
	while (elem->next != NULL)
		elem = elem->next;
	return (elem->index);
}

int	ft_countunit(t_pile **stack, int unit)
{
	t_pile	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->binary[unit] == 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_saveindex(t_pile *tmp, int unit)
{
	while (tmp->binary[unit] != 1)
		tmp = tmp->next;
	return (tmp->index);
}

int	ft_get_prefix(int data, int coef)
{
	if (data < 0)
		data *= -1;
	while (coef - 1 > 0)
	{
		data /= 10;
		coef--;
	}
	data = data % 10;
	return (data);
}
