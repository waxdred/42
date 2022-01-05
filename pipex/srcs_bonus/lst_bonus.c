/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:38:48 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/04 22:38:48 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

t_pile	*ft_create_elem(char **data)
{
	t_pile	*stack;

	stack = (t_pile *)malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->data = data;
	stack->next = NULL;
	return (stack);
}

void	ft_clear_stack(t_pile **stack)
{
	if (*stack != NULL)
	{
		ft_clear_stack(&((*stack)->next));
		free(*stack);
		*stack = NULL;
	}
}

t_pile	*ft_last(t_pile *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_add_back(t_pile **alst, t_pile *ne)
{
	t_pile	*elem;

	if (ne == NULL || alst == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = ne;
		return ;
	}
	elem = ft_last(*alst);
	elem->next = ne;
}


