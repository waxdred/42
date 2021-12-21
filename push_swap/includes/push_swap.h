/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:23:20 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/16 19:23:20 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/include/libft.h"
#include <stdio.h>
#include <limits.h>

typedef struct	s_pile
{
	int	data;
	struct s_pile	*next;
	struct s_pile	*prev;
}		t_pile;

typedef struct	s_swap
{
	t_pile	*pa;
	t_pile	*pb;
	int	*prefix;
	int	*sum;
	int	len;
	int	max;
	int	min;
	int	coef;
}		t_swap;

void	ft_get_env(t_pile **stack, t_swap *env);
void	ft_count_prefix(t_pile **stack, t_swap *env, int radix);
int	ft_get_prefix(int data, int coef);
int	ft_check_doublon(t_pile *stack, int data);
int	ft_check_sort(t_pile **stack);
int	ft_get_last(t_pile **stack, int data);
int	ft_error(char *av);
int	ft_stack_len(t_pile *stack, t_swap *env);
int	ft_swap(t_pile **stack);
int	ft_check_last(t_pile **stack, int data);
t_pile	*push_top(t_pile **stack, t_pile **dstack);
int	swap_top_bottom(t_pile **stack);
t_pile	*top_to_bottom(t_pile **stack);
t_pile	*ft_create_elem(int data);
t_pile	*ft_push_param(int ac, char **av, int check);
t_pile	*ft_clear_lst(t_pile **stack);
void	ft_clear_stack(t_pile **list);
void	ft_print_list(t_pile *pa, t_swap *env);
void	ft_push_back(t_pile **stack, int data);
void	push_swap(t_pile **pa, t_swap *env);
int	ft_end_data(t_pile *stack, t_swap *env);
int	ft_last_data(t_pile *stack, t_swap *env);
void	ft_get_env_a(t_pile *stack, t_swap *env);
void	ft_get_env_b(t_pile *stack, t_swap *env);
#endif
