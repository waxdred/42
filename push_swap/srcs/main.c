/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:22:53 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/16 19:23:08 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_get_full_env(t_pile **stack, t_swap *env)
{
	int	i;

	i = 0;
	ft_stack_len(env->pa, env);
	ft_get_env(&env->pa, env);
	env->prefix = (int *)ft_memalloc(sizeof(int) * 10);
	if (!env->prefix)
		exit (1);
	env->sum = (int *)ft_memalloc(sizeof(int) * 10);
	if (!env->sum)
		exit (1);
	ft_creat_tab(&(*stack), env);
}

void	ft_sorting(t_swap *env)
{
	if (env->pa == NULL)
	{
		ft_clear_stack(&env->pa);
		free(env);
		ft_putstr_fd("Error", 2);
		exit (-1);
	}
	ft_get_full_env(&env->pa, env);
	ft_sort_list(env);
	if (env->len < 4)
		ft_sort_tree(env);
	else
		ft_radix_sort(env, 0, 0, 0);
}

int	main(int argc, char **argv)
{
	t_swap	*env;
	char	**tab;

	if (argc == 1)
		return (-1);
	env = ft_memalloc(sizeof(t_swap));
	if (!env)
		return (-1);
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		env->pa = ft_push_param(ft_len_tab(tab), tab, env, 1);
		ft_freetab(tab);
	}
	else
		env->pa = ft_push_param(argc, argv, env, 0);
	ft_sorting(env);
	ft_clear_stack(&env->pa);
	free(env->prefix);
	free(env->sum);
	free(env);
	return (0);
}
