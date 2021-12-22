/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:22:40 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/16 19:22:40 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*ft_create_elem(int data)
{
	t_pile	*stack;

	stack = (t_pile*)malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->data = data;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

void	ft_push_back(t_pile **stack, int data)
{
	if (*stack)
	{
		if ((*stack)->next)
			ft_push_back(&(*stack)->next, data);
		else
		{
			(*stack)->next = ft_create_elem(data);
			(*stack)->next->prev = (*stack);
		}
	}
	else
		*stack = ft_create_elem(data);
}

void	ft_creat_tab(t_pile **stack, t_swap *env)
{
	t_pile	*elem;
	int	i;

	i = 0;
	elem = *stack;
	env->input = (int *)ft_memalloc(sizeof(int) * env->len);
	if (!env->input)
		exit (1);
	env->output = (int *)ft_memalloc(sizeof(int) * env->len);
	if (!env->output)
		exit (1);
	while (elem->next != NULL)
	{
		env->input[i] = elem->data;
		elem = elem->next;
		i++;
	}
	env->input[i] = elem->data;
}

t_pile	*ft_push_param(int ac, char **av, t_swap *env, int check)
{
	int	i;
	int	data;
	t_pile	*stack;

	stack = NULL;
	if (check == 0)
		i = 1;
	else
		i = 0;
	if (ac)
	{
		while (i < ac)
		{
			if (ft_error(av[i]) == -1)
				return (NULL);
			data = ft_atoi(av[i]);
			if (ft_check_doublon(stack, data) == -1)
				return (NULL);
			ft_push_back(&stack, ft_atoi(av[i]));
			i++;
		}
	}
	return (stack);
}
