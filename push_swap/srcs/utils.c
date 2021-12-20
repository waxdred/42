/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:23:13 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/16 19:23:13 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stack_len(t_pile *stack, t_swap *env)
{
	env->len = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		env->len++;
	}
	env->halflen = env->len / 2 ;
	return (env->len);
}

int	ft_end_data(t_pile *stack, t_swap *env)
{
	while (stack->next != NULL)
		stack = stack->next;
	env->end = stack->data;
	return (env->end);
}

int	ft_last_data(t_pile *stack, t_swap *env)
{
	while (stack->next != NULL)
		stack = stack->next;
	env->last = stack->data;
	return (env->last);
}

void	ft_get_env_a(t_pile *stack, t_swap *env)
{
	t_pile	*elem;

	elem = stack;
	env->min_a = stack->data;
	env->max_a = stack->data;
	while (elem->next != NULL)
	{
		if (elem->data < env->min_a)
			env->min_a = elem->data;
		if (elem->data > env->max_a)
			env->max_a = elem->data;
		elem = elem->next;
	}
	if (elem->data < env->min_a)
		env->min_a = elem->data;
	if (elem->data > env->max_a)
		env->max_a = elem->data;
	elem = stack;
	env->half_a = 0;
	while (elem->next != NULL)
	{
		env->half_a += elem->data;
		elem = elem->next;
	}
		env->half_a += elem->data;
		env->half_a /= env->len;

}

void	ft_get_env_b(t_pile *stack, t_swap *env)
{
	env->min_b = stack->data;
	env->max_b = stack->data;
	while (stack->next != NULL)
	{
		if (stack->data < env->min_b)
			env->min_b = stack->data;
		else if (stack->data > env->max_b)
			env->max_b = stack->data;
		stack = stack->next;
	}
	if (stack->data < env->min_b)
		env->min_b = stack->data;
	else if (stack->data > env->max_b)
		env->max_b = stack->data;
}

int	ft_get_last(t_pile **stack, int data)
{
	t_pile	*elem;

	elem = *stack;
	while (elem->next != NULL)
		elem = elem->next;
	if (elem->data < data)
		return (1);
	return (0);
}

int	ft_check_last(t_pile **stack, int data)
{
	t_pile	*elem;

	elem = *stack;
	while (elem->next != NULL)
	{
		if (elem->data < data)
			return (1);
		elem = elem->next;
	}
	if (elem->data < data)
		return (1);
	return (0);
}

int	ft_check_sort(t_pile **stack)
{
	t_pile	*elem;

	elem = *stack;
	while (elem->next != NULL)
	{
		if (elem->data < elem->next->data)
			return (0);
		elem = elem->next;
	}
	return (1);
}
