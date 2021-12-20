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

t_pile	*sort_stack_a(t_pile **pa, t_pile *pb, t_swap *env)
{	
	t_pile	*tmp;
	int	i;

	i = 0;
	tmp = *pa;
	env->last = ft_last_data(*pa, env);
	env->len = ft_stack_len(*pa, env);
	ft_get_env_a(*pa, env);
	printf("%d            %d\n\n", env->max_a, env->half_a);
	while (i < env->len && env->last != tmp->data)
	{
		env->end = ft_end_data(*pa, env);
		if (tmp->data < env->half_a + 1)
			push_top(&(*pa), &pb);
		else if (env->end < env->half_a + 1)
			swap_top_bottom(&*pa);
		else if (tmp->data > env->half_a)
			top_to_bottom(&(*pa));
		tmp = tmp->next;
		i++;
	}
	tmp = *pa;
	return (pb);
}

void	push_swap(t_pile **pa, t_swap *env)
{
	t_pile	*pb;

	pb = NULL;
	pb = sort_stack_a(&(*pa), pb, env);
	printf("[A]\n\n");
	ft_print_list(*pa, env);
	printf("[B]\n\n");
	ft_print_list(pb, env);
}

