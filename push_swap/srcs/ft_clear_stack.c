/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:23:45 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/16 19:23:45 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_clear_stack(t_pile **stack)
{
	if (*stack != NULL)
	{
		ft_clear_stack(&((*stack)->next));
		free(*stack);
		*stack = NULL;
	}
}

void	ft_clear_lst(t_pile **stack)
{
	t_pile	*tmp;

	tmp = (*stack);
	if ((*stack)->next == NULL && (*stack)->prev != NULL)
		(*stack)->prev->next = NULL;
	else if ((*stack)->prev == NULL)
		(*stack)->next->prev = NULL;
	else
	{
		(*stack)->next->prev = (*stack)->prev;
		(*stack)->prev->next = (*stack)->next;
	}
	(*stack) = (*stack)->next;
	free(tmp);
}
