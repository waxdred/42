/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:17:54 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/18 01:17:54 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_size_value(int max, int min)
{
	int	i;

	i = 0;
	if (max < 0)
		max *= -1;
	if (min < 0)
		min *= -1;
	if (max < min)
		max = min;
	while (max > 0)
	{
		max /= 10;
		i++;
	}
	return (i);
}

void	ft_get_env(t_pile **stack, t_swap *env)
{
	t_pile	*elem;

	elem = *stack;
	env->min = (*stack)->data;
	env->max = 0;
	while (elem->next != NULL)
	{
		if (env->max < elem->data)
			env->max = elem->data;
		if (env->min > elem->data)
			env->min = elem->data;
		elem = elem->next;
	}
	if (env->max < elem->data)
		env->max = elem->data;
	if (env->min > elem->data)
		env->min = elem->data;
	env->coef = ft_get_size_value(env->max, env->min);
}
