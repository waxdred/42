/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:23:34 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/16 19:23:34 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_doublon(t_pile *stack, int data)
{
	t_pile	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->data == data)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_stack_max(ssize_t data)
{
	if (data <= INT_MIN || data >= INT_MAX)
		return (-1);
	return (0);
}

int	ft_num(char *av)
{
	while (*av)
	{
		if (*av == '-' || *av == '+')
			av++;
		if (ft_isdigit(*av) == 0)
			return (-1);
		av++;
	}
	return (0);
}

int	ft_error(char *av)
{
	if (ft_num(av) || ft_stack_max(ft_atoi(av)) || ft_strlen(av) > 19)
		return (-1);
	return (0);
}
