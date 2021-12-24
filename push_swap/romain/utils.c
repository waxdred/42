/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 03:12:51 by rcuminal          #+#    #+#             */
/*   Updated: 2021/12/23 21:10:06 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstplus(t_list *lst)
{
	lst = lst->next;
	return (lst);
}

int	ft_lstpluscheck(t_list *lst, int val)
{
	lst = lst->next;
	if (*(int *)(lst)->content == val)
		return (1);
	return (0);
}

void	ft_lstprint(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		dprintf(1, "%d   ", lst->index);
		dprintf(1, "%d\n", *((int *)(lst)->content));
		lst = lst->next;
	}
	dprintf(1, "\n");
	return ;
}

static int	countsize(long long int o)
{
	int	i;

	i = 1;
	if (o < 0)
	{
		i++;
		o *= -1;
	}
	while (o >= 10)
	{
		o = o / 10;
		i++;
	}
	return (i);
}

void    ft_parsargv(char **argv, t_list **pilea, int argc)
{
	int					i;
	int					*tmpi;
	int long long		j;
	t_list				*tmp;
	int					ref;

	i = 1;
	ref = 0;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == countsize(ft_atoi(argv[i], &ref)))
		{
			ref = 0;
			j = ft_atoi(argv[i], &ref);
			tmpi = malloc(sizeof(int));
			*tmpi = j;
			tmp = ft_lstnew(tmpi);
			ft_lstadd_back(pilea, tmp);
			ref = 0;
		}
		if (ft_strlen(argv[i]) != countsize(ft_atoi(argv[i], &ref)))
		{
			ref = 0;
			j = ft_atoi(argv[i], &ref);
			tmpi = malloc(sizeof(int));
			*tmpi = j;
			tmp = ft_lstnew(tmpi);
			ft_lstadd_back(pilea, tmp);
			while (j != 922337203685477580 && ref < ft_strlen(argv[i]))
			{
				j = ft_atoi(argv[i], &ref);
				if (j != 922337203685477580)
				{
					tmpi = malloc(sizeof(int));
					*tmpi = j;
					tmp = ft_lstnew(tmpi);
					ft_lstadd_back(pilea, tmp);
				}
			}
		}
		
		i++;
	}

	return ;
}
