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

void	ft_count_while(t_swap *env)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		env->csum += env->sum[i];
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
