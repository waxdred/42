/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:17:54 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/18 01:17:54 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_list(t_pile *pa, t_swap *env);

void	ft_sort_tree(t_swap *env)
{
	t_pile	*tmp;
	int	end;

	end = ft_end_index(&env->pa);
	if (env->pa->index > env->pa->next->index)
		ft_swaptopa(&env->pa);
	if (end > env->pa->index)
		ft_rotatepilea(&env->pa);
	if (env->pa->index < env->pa->next->index)
		ft_swaptopa(&env->pa);
	ft_print_list(env->pa, env);
}

void	ft_quick_swap(t_pile *pa, t_swap *env)
{

}

void	ft_radix_sort(t_swap *env)
{
	t_pile	*tmp;
	int		i;
	int		count;
	int		index;

	i = env->binary_len - 1;
	while (i + 1 > 0)
	{
		tmp = env->pa;
		index = ft_saveindex(tmp, i);
		count = ft_countunit(&env->pa, i);
			while (count > 0)
			{
				if (env->pa->binary[i] == 0)
				{
					ft_pushb(&env->pa, &env->pb);
					count--;
				}
				else
					ft_rotatepilea(&env->pa);
			}
		while (env->pa->index != index)
			ft_rotatepilea(&env->pa);
		while (env->pb)
			ft_pusha(&env->pa, &env->pb);
		i--;
	}
}
