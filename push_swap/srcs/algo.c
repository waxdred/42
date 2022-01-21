/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:17:54 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/18 01:17:54 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_tree(t_swap *env)
{
	int	end;
	int	middle;

	end = ft_end_index(&env->pa);
	middle = env->pa->next->index;
	if (env->pa->index < middle && env->pa->index > end)
		ft_rotaterevpilea(&env->pa);
	else if (env->pa->index > middle && env->pa->index > end && middle < end)
		ft_rotatepilea(&env->pa);
	else if (env->pa->index > middle && env->pa->index < end && middle < end)
		ft_swaptopa(&env->pa);
	else if (env->pa->index < middle && env->pa->index < end && middle > end)
	{
		ft_swaptopa(&env->pa);
		ft_rotatepilea(&env->pa);
	}
	else if (env->pa->index > middle && env->pa->index > end && middle > end)
	{
		ft_rotatepilea(&env->pa);
		ft_swaptopa(&env->pa);
	}
}

void	ft_sort_five(t_swap *env)
{
	int	count;

	count = 0;
	while (count < 2)
	{
		if (env->pa->index == 0 || env->pa->index == 1)
		{
			ft_pushb(&env->pa, &env->pb);
			count++;
		}
		else
			ft_rotatepilea(&env->pa);
	}
	ft_sort_tree(env);
	if (env->pb->index < env->pb->next->index)
		ft_rotatepileb(&env->pb);
	ft_pusha(&env->pa, &env->pb);
	ft_pusha(&env->pa, &env->pb);
}

void	ft_radix_sort(t_swap *env, int i, int count, int index)
{
	t_pile	*tmp;

	i = env->binary_len - 1;
	while (i + 1 > 0)
	{
		tmp = env->pa;
		index = ft_saveindex(tmp, i);
		count = ft_countunit(&env->pa, i);
		while (count > 0)
		{
			if (env->pa->binary[i] == 0)
			{
				ft_pushb(&env->pa, &env->pb);
				count--;
			}
			else
				ft_rotatepilea(&env->pa);
		}
		while (env->pa->index != index)
			ft_rotatepilea(&env->pa);
		while (env->pb)
			ft_pusha(&env->pa, &env->pb);
		i--;
	}
}

int	ft_sorted(t_swap *env)
{
	t_pile	*elem;
	int		i;

	i = 1;
	elem = env->pa;
	while (elem->next != NULL)
	{
		if (elem->data < elem->next->data)
			i++;
		elem = elem->next;
	}
	if (i == env->len)
		return (1);
	return (0);
}
