/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackB.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:17:54 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/18 01:17:54 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pushb(t_pile **pilea, t_pile **pileb)
{
	t_pile	*tmp;

	tmp = *pileb;
	*pileb = *pilea;
	*pilea = (*pilea)->next;
	if (tmp)
		(*pileb)->next = tmp;
	else
		(*pileb)->next = NULL;
	write (1, "pb\n", 3);
}

void	ft_swaptopb(t_pile **alst, t_pile *new)
{
	if (*alst)
		(*alst)->next = new;
	else if (!*alst && new)
		*alst = new;
	else
		*alst = NULL;
	write (1, "sb\n", 3);
}

void	ft_rotatepileb(t_pile **pile)
{
	t_pile	*tmp;

	tmp = *pile;
	*pile = (*pile)->next;
	tmp->next = NULL;
	ft_add_back(pile, tmp);
	write (1, "rb\n", 3);
	return ;
}

void	ft_rotaterevpileb(t_pile **pile)
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
	write (1, "rrb\n", 4);
	return ;
}
