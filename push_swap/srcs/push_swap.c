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

void	ft_print_tabi(t_swap *env)
{
	int 	i;

	i = 0;
	printf("\n\ninput ===========\n\n");
	while (i < env->len)
	{
		printf("[%d] \n", env->input[i]);
		i++;
	}
}

void	ft_sort_neg(t_swap *env)
{
	int	*tmp_max;
	int	*tmp_min;
	int	i;
	int	j;
	int	min;
	int	max;

	i = 0;
	j = 0;
	min = 0;
	max = 0;
	while (i < env->len)
	{
		if (env->input[i] >= 0)
			max++;
		else
			min++;
		i++;
	}
	tmp_max = (int *)ft_memalloc(sizeof(int) * max);
	if (!tmp_max)
		exit (1);
	tmp_min = (int *)ft_memalloc(sizeof(int) * min);
	if (!tmp_min)
		exit (1);
	i = env->len - 1;
	while (i >= 0)
	{
		if (env->input[i] < 0)
		{
			tmp_min[j] = env->input[i];
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
			tmp_max[j] = env->input[i];
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < min)
	{
		env->input[i] = tmp_min[i];
		i++;
	}
	while (j < max)
	{
		env->input[i] = tmp_max[j];
		i++;
		j++;
	}
	free(tmp_max);
	free(tmp_min);
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
		ft_print_tabi(env);
		i++;
	}
	if (env->min < 0)
		ft_sort_neg(env);
}

void	ft_push_swap(t_pile **pa, t_swap *env)
{
	t_pile	*pb;

	pb = NULL;
	ft_count_prefix(env, 1);
}
