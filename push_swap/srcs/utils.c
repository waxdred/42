/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:23:13 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/16 19:23:13 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ft_count_prefix(t_swap *env, int coef)
{
	int	i;
	int	prefix;

	i = 0;
	while (i < env->len)
	{
		prefix = ft_get_prefix(env->input[i], coef);
		env->prefix[prefix] += 1;
		i++;
	}
	i = 1;
	while (i < env->len || i < 10)
	{
		env->prefix[i] += env->prefix[i - 1];
		i++;
	}
}

void	ft_sort_prefix(t_swap *env, int coef)
{
	int	i;
	int	prefix;

	i = env->len - 1;
	while (i >= 0)
	{
		prefix = ft_get_prefix(env->input[i], coef);
		env->prefix[prefix] -= 1;
		env->output[env->prefix[prefix]] = env->input[i];
		i--;
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

void	ft_transfere(t_swap *env)
{
	int	i;

	i = 0;
	while (i < env->len)
	{
		env->input[i] = env->output[i];
		env->output[i] = 0;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		env->prefix[i] = 0;
		i++;
	}
}

