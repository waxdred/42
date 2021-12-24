/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:01:52 by rcuminal          #+#    #+#             */
/*   Updated: 2021/12/24 02:19:08 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_countunit(t_list **temp, int unit)
{
	t_list	*tmp;
	int	i;

	i= 0;
	tmp = *temp;
	while (tmp)
	{
		
		if (tmp->binary[unit] == 0)
		{
			
			i++;
		}
		tmp = tmp->next;
	}
	return (i);
}

int	ft_checkmin(t_list **pile)
{
	int	i;

	i = 2147483647;
	while (*pile)
	{
		if (*(int *)(*pile)->content < i)
			i = *(int *)(*pile)->content;
		*pile = (*pile)->next;
	}
	return (i);
}

int	ft_checkmax(t_list **pile)
{
	int	i;

	i = -2147483648;
	while (*pile)
	{
		if (*(int *)(*pile)->content > i)
			i = *(int *)(*pile)->content;
		*pile = (*pile)->next;
	}
	return (i);
}

int	ft_checknear(t_list **pile, int i)
{
	int	j;

	j = 0;
	while (*pile)
	{
		if (*(int *)(*pile)->content != i)
			j++;
		*pile = (*pile)->next;
	}
//	printf("checkmar   %d", j);
	return (j);
}

int	ft_checknearindex(t_list **pile, int i)
{
	int	j;

	j = 0;
	while (*pile)
	{
		if ((*pile)->index == i)
			return (j);
		*pile = (*pile)->next;
		j++;
	}
//	printf("checkmar   %d", j);
	return (j);
}

int	ft_checknearbinary(t_list **pile, int i)
{
	int	j;
	t_list	*tmp;
	
	j = 0;
	tmp = *pile;
	while (tmp)
	{
		if ((tmp)->binary[i] == 0)
			return (j);
		tmp = (tmp)->next;
		j++;
	}

	return (j);
}

int	ft_checkmoy(t_list **pile)
{
	int	i;
	int	j;

	j = ft_lstsize(*pile);
	i = 0;
	while (*pile)
	{
		
		i = i + *(int *)(*pile)->content;
		*pile = (*pile)->next;
	}
	return (i / j);
}

int	ft_checkorder(t_list **pile)
{
	t_list	*tmp;
	int		i;

	tmp = *pile;
	i = 0;
	while (tmp->next)
	{
		i = *(int *)tmp->content;
		if (*(int *)tmp->next->content > i)
			tmp = tmp->next;
		else
			return (1);
	}
	if (*(int *)tmp->content < i)
		return (1);
	return (0);
}

int	ft_checkdoublons(char **argv)
{
	int	i;
	int	j;
	int	d;
	int	n;

	d = 0;
	n = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[j])
		{
			if (ft_atoi(argv[i], &d) == ft_atoi(argv[j], &n) && j != i)
				return (0);
			d = 0;
			n = 0;
			j++;
		}
		i++;
	}
	return (1);
}



// int ft_checkdoublonsargstring(int val, char **argv)
// {
// 	int	i;
// 	int	j;
// 	int	d;
// 	int	n;

// 	d = 0;
// 	n = 0;
// 	i = 1;
// 	while (argv[i])
// 	{
// 		j = 0;
// 		while (argv[j])
// 		{
// 			if (ft_atoi(argv[i], &d) == ft_atoi(argv[j], &n) && j != i)
// 				return (0);
// 			d = 0;
// 			n = 0;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }


