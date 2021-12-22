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
	int	index;
	struct s_pile	*next;
	struct s_pile	*prev;
}		t_pile;

typedef struct	s_swap
{
	t_pile	*pa;
	t_pile	*pb;
	int	*prefix;
	int	*sum;
	int	*input;
	int	*output;
	int	csum;
	int	len;
	int	max;
	int	min;
	int	coef;
}		t_swap;


int	fswap(t_pile **stack, int check);
int	ft_check_doublon(t_pile *stack, int data);
int	ft_error(char *av);
int	ft_get_prefix(int data, int coef);
int	ft_get_size_value(int max, int min);
int	ft_num(char *av);
int	ft_stack_len(t_pile *stack, t_swap *env);
int	ft_stack_max(ssize_t data);
int	swap_top_bottom(t_pile **stack,int check);

t_pile	*ft_clear_lst(t_pile **stack);
t_pile	*ft_create_elem(int data);
t_pile	*ft_push_param(int ac, char **av, t_swap *env, int check);
t_pile	*push_top(t_pile **stack, t_pile **dstack, int check);
t_pile	*top_to_bottom(t_pile **stack, int check);

void	ft_clear_stack(t_pile **stack);
void	ft_sort_list(t_swap *env);
void	ft_clear_sum_pref(t_swap *env);
void	ft_creat_tab(t_pile **stack, t_swap *env);
void	ft_sort_prefix(t_swap *env, int coef);
void	ft_count_prefix(t_swap *env, int coef);
void	ft_count_while(t_swap *env);
void	ft_get_env(t_pile **stack, t_swap *env);
void	ft_push_back(t_pile **stack, int data);
void	ft_get_full_env(t_pile **stack, t_swap *env);
void	ft_transfere(t_swap *env);
#endif
