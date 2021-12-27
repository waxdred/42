/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools                                          :+:      :+:    :+:   */
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

t_pile	*ft_create_elem(int data)
{
	t_pile	*stack;

	stack = (t_pile*)malloc(sizeof(*stack));
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

void	ft_add_front(t_pile **alst, t_pile *ne)
{
	if (ne == NULL || alst == NULL)
		return ;
	ne->next = *alst;
	*alst = ne;
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
