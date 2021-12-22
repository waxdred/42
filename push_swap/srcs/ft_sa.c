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
int	fswap(t_pile **stack, int check)
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
	if (check == 0)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
	return (0);
}

//function Ra Rb
t_pile	*top_to_bottom(t_pile **stack, int check)
{
	if (*stack == NULL)
		return (NULL);
	ft_push_back(&(*stack), (*stack)->data);
	*stack = ft_clear_lst(&(*stack));
	if (check == 0)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
	return (*stack);
}

//function Rra Rrb
int	swap_top_bottom(t_pile **stack,int check)
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
	if (check == 0)
		write(1, "rra\n", 3);
	else
		write(1, "rrb\n", 3);
	return (0);
}

//function Pa pb
t_pile	*push_top(t_pile **stack, t_pile **dstack, int check)
{
	t_pile	*elem;

	if (*stack == NULL)
		return (NULL);
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
	*stack = ft_clear_lst(&(*stack));
	if (check == 0)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	return (*stack);
}
