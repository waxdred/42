/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackA.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:17:54 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/18 01:17:54 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pusha(t_pile **pilea, t_pile **pileb)
{
	t_pile	*tmp;

	tmp = *pilea;
	*pilea = *pileb;
	*pileb = (*pileb)->next;
	if (tmp)
		(*pilea)->next = tmp;
	else
		(*pilea)->next = NULL;
	write (1, "pa\n", 3);
}

void	ft_swaptopa(t_pile **stack)
{
	int	tmp;
	int	itmp;

	tmp = (*stack)->index;
	itmp = (*stack)->data;
	(*stack)->index = (*stack)->next->index;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->index = tmp;
	(*stack)->next->data = itmp;
	write (1, "sa\n", 3);
}

void	ft_rotatepilea(t_pile **pile)
{
	t_pile	*tmp;

	tmp = *pile;
	*pile = (*pile)->next;
	tmp->next = NULL;
	ft_add_back(pile, tmp);
	write (1, "ra\n", 3);
	return ;
}

void	ft_rotaterevpilea(t_pile **pile)
{
	t_pile	*tmp;
	t_pile	*var;

	tmp = ft_last(*pile);
	ft_add_front(pile, tmp);
	var = *pile;
	while (var->next != tmp)
	{
		var = var->next;
	}
	var->next = NULL;
	write (1, "rra\n", 4);
	return ;
}
