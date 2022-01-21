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

void	ft_add_index(t_pile **stack, t_swap *env)
{
	t_pile	*elem;
	int		i;
	int		tmp;

	elem = *stack;
	env->binary_len = ft_binary_len(env->len - 1);
	while (elem->next != NULL)
	{
		i = 0;
		tmp = elem->data;
		while (env->input[i] != tmp)
			i++;
		elem->index = i;
		elem->binary = ft_track(ft_dec_to_bin(i, env->binary_len), env->t);
		elem = elem->next;
	}
	i = 0;
	tmp = elem->data;
	while (env->input[i] != tmp)
		i++;
	elem->index = i;
	elem->binary = ft_track(ft_dec_to_bin(i, env->binary_len), env->t);
	ft_track_free(env->t, env->input);
	ft_track_free(env->t, env->output);
}

void	ft_sort_list(t_swap *env)
{
	int	i;

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

t_pile	*ft_push_param(int ac, char **av, t_swap *env, int check)
{
	t_pile	*stack;
	int		i;
	int		data;

	stack = NULL;
	if (check == 0)
		i = 1;
	else
		i = 0;
	if (ac)
	{
		while (i < ac)
		{
			if (ft_error(av[i], env) == -1)
				return (NULL);
			data = ft_atoi(av[i]);
			if (ft_check_doublon(stack, data, env) == -1)
				return (NULL);
			ft_add_back(&stack, ft_track(
					ft_create_elem(ft_atoi(av[i])), env->t));
			i++;
		}
	}
	return (stack);
}
