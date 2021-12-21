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
	return (env->len);
}

void	ft_count_prefix(t_pile **stack, t_swap *env, int radix)
{
	t_pile	*elem;
	int	prefix;
	int 	i;
	
	i = 1;
	elem = *stack;
	while (elem->next != NULL)
	{
		// prevoir modif du rad pour augmenter les 10eme
		prefix = ft_get_prefix(elem->data, radix);
		env->prefix[prefix] += 1;
		elem = elem->next;
	}
	prefix = ft_get_prefix(elem->data, radix);
	env->prefix[prefix] += 1;
	while (i < 10)
	{
		env->prefix[i] += env->prefix[i - 1];
		i++;
	}
}

