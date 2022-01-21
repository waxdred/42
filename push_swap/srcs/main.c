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
	ft_stack_len(env->pa, env);
	ft_get_env(&env->pa, env);
	ft_track(env->prefix = (int *)ft_memalloc(sizeof(int) * 10), env->t);
	ft_track(env->sum = (int *)ft_memalloc(sizeof(int) * 10), env->t);
	ft_creat_tab(&(*stack), env);
}

void	ft_sorting(t_swap *env)
{
	ft_get_full_env(&env->pa, env);
	if (env->len == 1 || ft_sorted(env) == 1)
		return ;
	ft_sort_list(env);
	if (env->len < 2)
		ft_sort_two(env);
	else if (env->len < 4)
		ft_sort_tree(env);
	else if (env->len == 5)
		ft_sort_five(env);
	else
		ft_radix_sort(env, 0, 0, 0);
}

int	main(int ac, char **av)
{
	t_swap	*env;
	char	**tab;

	if (ac < 2)
		return (0);
	env = ft_memalloc(sizeof(t_swap));
	env->t = ft_memalloc(sizeof(t_track));
	if (!env || !env->t)
		return (-1);
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		ft_track_tab((void **)tab, env->t);
		env->pa = ft_push_param(ft_len_tab(tab), tab, env, 1);
	}
	else
		env->pa = ft_push_param(ac, av, env, 0);
	if (env->pa != NULL)
		ft_sorting(env);
	else
		ft_putstr_fd("Error\n", 2);
	ft_track_free_all(env->t);
	free(env);
	return (0);
}
