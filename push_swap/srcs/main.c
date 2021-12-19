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

void	ft_print_list(t_pile *pa, t_swap *env)
{
	t_pile *tmp;

	tmp = pa;
	while (tmp->next)
	{
		printf("[%d] \n", tmp->data);
		tmp = tmp->next;
	}
	printf("[%d]\n", tmp->data);
	printf("len = %d\n\n", env->len);
	printf("aflen = %d\n\n", env->halflen);
}

int main(int argc, char **argv)
{
	t_swap *env;
	char	**tab;

	if (argc == 1)
		return (-1);	
	env = ft_memalloc(sizeof(t_swap));
	if (!env)
		return (-1);
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		printf("%s \n", tab[0]);
		env->pa = ft_push_param(ft_len_tab(tab), tab, 1);
		ft_freetab(tab);
	}
	else
		env->pa = ft_push_param(argc, argv, 0);
	if (env->pa == NULL)
	{
		ft_clear_stack(&env->pa);
		free(env);
		ft_putstr_fd("Error", 2);
		return (-1);
	}
	ft_stack_len(env->pa, env);
	printf("Entry val \n[A]\n\n");
	ft_print_list(env->pa, env);
	push_swap(&env->pa, env);
	ft_clear_stack(&env->pa);
	free(env);
	return (0);
}
