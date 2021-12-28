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
# include <stdio.h>
# include <limits.h>

typedef struct s_pile
{
	int				data;
	int				index;
	int				*binary;
	struct s_pile	*next;
}		t_pile;

typedef struct s_swap
{
	t_pile	*pa;
	t_pile	*pb;
	int		*prefix;
	int		*sum;
	int		*input;
	int		*output;
	int		*tmp_max;
	int		*tmp_min;
	int		t_min;
	int		t_max;
	int		binary_len;
	int		csum;
	int		len;
	int		max;
	int		min;
	int		coef;
}		t_swap;

int		ft_check_doublon(t_pile *stack, int data);
int		ft_countunit(t_pile **stack, int unit);
int		ft_end_index(t_pile **stack);
int		ft_end_sort(t_pile **stack, t_swap *env);
int		ft_error(char *av);
int		ft_gen_tmp(t_swap *env);
int		ft_get_prefix(int data, int coef);
int		ft_num(char *av);
int		ft_saveindex(t_pile *tmp, int unit);
int		ft_stack_len(t_pile *stack, t_swap *env);
int		ft_stack_l(t_pile *stack);
int		ft_stack_max(ssize_t data);
t_pile	*ft_create_elem(int data);
t_pile	*ft_last(t_pile *lst);
t_pile	*ft_push_param(int ac, char **av, t_swap *env, int check);
void	ft_add_back(t_pile **alst, t_pile *ne);
void	ft_add_front(t_pile **alst, t_pile *ne);
void	ft_add_index(t_pile **stack, t_swap *env);
void	ft_clear_stack(t_pile **stack);
void	ft_complet_tmp(t_swap *env, int i, int j);
void	ft_sort_five(t_swap *env);
void	ft_count_min_max(t_swap *env);
void	ft_count_prefix(t_swap *env, int coef);
void	ft_creat_tab(t_pile **stack, t_swap *env);
void	ft_get_env(t_pile **stack, t_swap *env);
void	ft_get_full_env(t_pile **stack, t_swap *env);
void	ft_clear_binary(t_swap *env);
void	ft_pusha(t_pile **pilea, t_pile **pileb);
void	ft_pushb(t_pile **pilea, t_pile **pileb);
void	ft_radix_sort(t_swap *env, int i, int count, int index);
void	ft_rotatepilea(t_pile **pile);
void	ft_rotatepileb(t_pile **pile);
void	ft_rotaterevpilea(t_pile **pile);
void	ft_rotaterevpileb(t_pile **pile);
void	ft_sort_list(t_swap *env);
void	ft_sort_neg(t_swap *env);
void	ft_sort_prefix(t_swap *env, int coef);
void	ft_sort_tree(t_swap *env);
void	ft_swaptopa(t_pile **stack);
void	ft_swaptopb(t_pile **stack);
void	ft_transfere(t_swap *env);
#endif
