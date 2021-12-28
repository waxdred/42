/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:32:15 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/28 00:32:15 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_count_min_max(t_swap *env)
{
	int	i;

	i = 0;
	env->t_min = 0;
	env->t_max = 0;
	while (i < env->len)
	{
		if (env->input[i] >= 0)
			env->t_max++;
		else
			env->t_min++;
		i++;
	}
}

int	ft_gen_tmp(t_swap *env)
{
	env->tmp_max = (int *)ft_memalloc(sizeof(int) * env->t_max);
	env->tmp_min = (int *)ft_memalloc(sizeof(int) * env->t_min);
	if (!env->tmp_max || ! env->tmp_min)
		return (-1);
	return (0);
}

void	ft_complet_tmp(t_swap *env, int i, int j)
{
	i = env->len - 1;
	while (i >= 0)
	{
		if (env->input[i] < 0)
		{
			env->tmp_min[j] = env->input[i];
			j++;
		}
		i--;
	}
	j = 0;
	i = 0;
	while (i < env->len)
	{
		if (env->input[i] >= 0)
		{
			env->tmp_max[j] = env->input[i];
			j++;
		}
		i++;
	}
}
