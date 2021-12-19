/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:22:36 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/16 19:22:36 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
//function Sa Sb
int	ft_swap(t_pile **stack)
{
	int	tmp;

	if (*stack == NULL)
		return (-1);
	if ((*stack)->next != NULL)
	{
		tmp = (*stack)->data;
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data = tmp;
	}
	return (0);
}

//function Ra Rb
int	top_to_bottom(t_pile **stack)
{
	if (*stack == NULL)
		return (-1);
	ft_push_back(&(*stack), (*stack)->data);
	ft_clear_lst(&(*stack));
	return (0);
}

//function Rra Rrb
int	swap_top_bottom(t_pile **stack)
{
	t_pile	*elem;
	int	tmp;

	if (*stack == NULL)
		return (-1);
	elem = *stack;
	tmp = (*stack)->data;
	while (elem->next)
		elem = elem->next;
	(*stack)->data = elem->data;
	elem->data = tmp;
	return (0);
}

//function Pa pb
int	push_top(t_pile **stack, t_pile **dstack)
{
	t_pile	*elem;

	if (*stack == NULL)
		return (-1);
	elem = NULL;
	if (*dstack)
	{
		elem = ft_create_elem((*stack)->data);
		(*dstack)->prev = elem;
		elem->next = *dstack;
	}
	else
		elem = ft_create_elem((*stack)->data);
	*dstack = elem;
	ft_clear_lst(&(*stack));
	return (0);
}
