/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:17:54 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/18 01:17:54 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_count_min_max(t_swap *env)
{
	int	i;

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

void	ft_sort_neg(t_swap *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_count_min_max(env);
	if (ft_gen_tmp(env) == -1)
		exit (-1);
	ft_complet_tmp(env, 0, 0);
	while (i < env->t_min)
	{
		env->input[i] = env->tmp_min[i];
		i++;
	}
	while (j < env->t_max)
	{
		env->input[i] = env->tmp_max[j];
		i++;
		j++;
	}
	free(env->tmp_max);
	free(env->tmp_min);
}

void	ft_add_index(t_pile **stack, t_swap *env)
{
	t_pile *elem;
	int	i;
	int	tmp;

	elem = *stack;
	env->binary_len = ft_binary_len(env->len - 1);
	while (elem->next != NULL)
	{
		i = 0;
		tmp = elem->data;
		while (env->input[i] != tmp)
			i++;
		elem->index = i;
		elem->binary = ft_dec_to_bin(i, env->binary_len);
		elem = elem->next;
	}
	i = 0;
	tmp = elem->data;
	while (env->input[i] != tmp)
		i++;
	elem->index = i;
	elem->binary = ft_dec_to_bin(i, env->binary_len);
	free(env->input);
	free(env->output);
}

void	ft_sort_list(t_swap *env)
{
	int	i;
	int	coef;

	i = 1;
	while (i <= env->coef)
	{
		ft_count_prefix(env, i);
		ft_sort_prefix(env, i);
		ft_transfere(env);
		i++;
	}
	if (env->min < 0)
		ft_sort_neg(env);
	ft_add_index(&env->pa, env);
}
