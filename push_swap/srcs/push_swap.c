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
	printf("len = %d  middle value = %d \n\n",env->len, env->half_a);
	while (i < env->len)
	{
		env->end = ft_end_data(*pa, env);
		if (ft_check_last(&(*pa), env->half_a + 1) == 0)
			break;
		if (tmp->data < env->half_a + 1)
			*pa = push_top(&(*pa), &pb);
		else if (ft_get_last(&(*pa), env->half_a + 1) == 1)
			swap_top_bottom(&*pa);
		else if (tmp->data > env->half_a)
			*pa = top_to_bottom(&(*pa));
		tmp = tmp->next;
		i++;
	}
	return (pb);
}

t_pile	*sort_stack_b(t_pile **pa, t_pile *pb, t_swap *env)
{	
	t_pile	*tmp;
	int	i;

	i = 0;
	tmp = *pa;
	env->last = ft_last_data(*pa, env);
	env->len = ft_stack_len(*pa, env);
	ft_get_env_a(*pa, env);
	printf("len = %d  middle value = %d \n\n",env->len, env->half_a);
	while (i < env->len)
	{
		env->end = ft_end_data(*pa, env);
		if (ft_check_last(&(*pa), env->half_a + 1) == 0)
			break;
		if (tmp->data > env->half_a + 1)
			*pa = push_top(&(*pa), &pb);
		else if (ft_get_last(&(*pa), env->half_a + 1) == 1)
			swap_top_bottom(&*pa);
		else if (tmp->data < env->half_a)
			*pa = top_to_bottom(&(*pa));
		tmp = tmp->next;
		i++;
	}
	return (pb);
}
void	push_swap(t_pile **pa, t_swap *env)
{
	t_pile	*pb;

	pb = NULL;
	while (env->len > 2)
	{
		pb = sort_stack_a(&(*pa), pb, env);
		printf("[A]\n\n");
		ft_print_list(*pa, env);
		printf("[B]\n\n");
		ft_print_list(pb, env);
		ft_stack_len(*pa, env);
	}
	*pa = sort_stack_b(&pb, (*pa), env);
	printf("[A]\n\n");
	ft_print_list(*pa, env);
	printf("[B]\n\n");
	ft_print_list(pb, env);
	ft_clear_stack(&pb);
}

