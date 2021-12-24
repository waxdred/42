/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrois.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:31:16 by rcuminal          #+#    #+#             */
/*   Updated: 2021/12/24 02:18:01 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*suite(t_list *pilea, t_list *tmp, t_val val)
{
	if (ft_lstpluscheck(pilea, val.max) == 1)
	{
		ft_rotatepilea(&pilea);
		ft_rotatepilea(&pilea);
	}
	else
		ft_callswap(&pilea, tmp);
	return (pilea);
}

t_list	*ft_castrois(t_list *pilea, t_list *tmp, t_val val)
{
	val = ft_minmax(pilea, tmp, val);
	if (*((int *)(pilea)->content) == val.max)
	{
		if (ft_lstpluscheck(pilea, val.min) == 1)
			ft_rotatepilea(&pilea);
		else
		{
			ft_rotatepilea(&pilea);
			ft_callswap(&pilea, tmp);
		}
	}
	if (*((int *)(pilea)->content) == val.min)
	{
		if (ft_lstpluscheck(pilea, val.max) == 1)
		{
			ft_callswap(&pilea, tmp);
			ft_rotatepilea(&pilea);
		}
	}
	else
	{
		pilea = suite(pilea, tmp, val);
	}
	return (pilea);
}

t_list	*ft_cascinq(t_list *pilea, t_list *pileb, t_list *tmp, t_val *val)
{
	*val = ft_minmax(pilea, tmp, *val);
	if (*((int *)(ft_lstlast(pilea))->content) == val->min)
		ft_rotaterevpilea(&pilea);
	if (pilea->next && *((int *)(pilea)->next->content) == val->min)
		ft_callswap(&pilea, tmp);
	while (*((int *)(pilea)->content) != val->min)
		ft_rotatepilea(&pilea);
	ft_pushb(&pilea, &pileb);
	if (pilea)
	{
	*val = ft_minmax(pilea, tmp, *val);
	while (*((int *)(pilea)->content) != val->min)
		ft_rotatepilea(&pilea);
	ft_pushb(&pilea, &pileb);
	
		*val = ft_minmax(pilea, tmp, *val);
		pilea = ft_castrois(pilea, tmp, *val);
	}
	if (*((int *)(pileb)->content) < *((int *)(pileb)->next->content))
		ft_rotatepileb(&pileb);
	ft_pusha(&pilea, &pileb);
	ft_pusha(&pilea, &pileb);
	return (pilea);
}

// t_val	*ft_casplus(t_val *val)
// {
// 	t_list	*tmp;

// 	ft_pushb(&(val->pilea), &(val->pileb));
// 	ft_pushb(&(val->pilea), &(val->pileb));
// 	tmp = NULL;
// 	*val = ft_minmax(val->pileb, tmp, *val);
// 	if (*((int *)(val->pileb)->content) < *((int *)(val->pileb)->next->content))
// 			ft_callswap(&val->pileb, tmp);
// 	while (val->pilea)
// 	{
// 		*val = ft_minmax(val->pileb, tmp, *val);
// 		if (*((int *)(val->pilea)->content) > val->max)
// 			ft_pushb(&(val->pilea), &(val->pileb));
// 		else if (*((int *)(val->pilea)->content) < val->min)
// 		{
// 			ft_pushb(&(val->pilea), &(val->pileb));
// 			ft_rotatepileb(&val->pileb);
// 		}
// 		else if (*((int *)(val->pilea)->content) < *((int *)(val->pileb)->content))
// 		{
			
// 			while (*((int *)(val->pilea)->content) <  *((int *)(val->pileb)->content))
// 				ft_rotatepileb(&val->pileb);
// 			ft_pushb(&(val->pilea), &(val->pileb));
// 		}
// 		else if (*((int *)(val->pilea)->content) > *((int *)(val->pileb)->content))
// 		{
// 			ft_pushb(&(val->pilea), &(val->pileb));
// 		}
// 		*val = ft_minmax(val->pileb, tmp, *val);
// 		while (*((int *)(val->pileb)->content) != val->max)
// 			ft_rotatepileb(&val->pileb);	
// 	}
// 	return (val);
// }

// void	ft_casplus(t_val *val)
// {
// 	t_list	*tmp;
// 	int		i;
// 	int 	check;

// 	i = 0;
	
// 	while (val->pilea->next->next->next)
// 	{
// 		check = ft_checknear(&tmp, i);
// 		tmp = val->pilea;
// 		if (val->pilea->next->index == i && val->pilea->index == i + 1)
// 			ft_callswap(&val->pilea, tmp);
// 		if (check > (ft_lstsize(tmp) / 2))
// 		{
// 			while (val->pilea->index != i)
// 				ft_rotatepilea(&val->pilea);
// 		}
// 		if (check <= (ft_lstsize(tmp) / 2))
// 		{
// 			while (val->pilea->index != i)
// 	 			ft_rotaterevpilea(&val->pilea);
// 		}
// 	 	ft_pushb(&val->pilea, &val->pileb);
// 		i++;
// 	}
// 	val->pilea = ft_castrois(val->pilea, tmp, *val);
// 	while (val->pileb)
// 	{
// 		ft_pusha(&val->pilea, &val->pileb);
// 	}
// }


// void	ft_casplus(t_val *val)
// {
// 	t_list	*tmp;
// 	int		i;
// 	int 	check;

// 	i = val->len;
// 	tmp = val->pilea;
// 	if (val->len % 2 == 0)
// 	{
// 		while (ft_lstsize(tmp)  > (i / 2) + 1 )
// 		{
// 			if (val->pilea->index < i / 2  - 1)
// 			{
// 				ft_pushb(&val->pilea, &val->pileb);
// 			}
// 			ft_rotatepilea(&val->pilea);
// 			tmp = val->pilea;
	
// 		}
// 		i = ft_lstsize(tmp);
// 		while (val->pilea->next->next)
// 		{
// 			if (val->pilea->index > i / 2 - 1 && val->pilea->index != val->len - 1 && val->pilea->index != val->len - 2)
// 			{
// 				ft_pushb(&val->pilea, &val->pileb);
// 			}
// 			ft_rotatepilea(&val->pilea);

// 			tmp = val->pilea;
// 		}

// 	}
// 	if (val->len % 2 == 1)
// 	{
// 		while (ft_lstsize(tmp)  > (i / 2) + 2 )
// 		{
// 			if (val->pilea->index < i / 2  - 1)
// 			{
// 				ft_pushb(&val->pilea, &val->pileb);
// 			}
// 			ft_rotatepilea(&val->pilea);
// 			tmp = val->pilea;
	
// 		}
// 		i = ft_lstsize(tmp);
// 		while (val->pilea->next->next)
// 		{
// 			if (val->pilea->index > i / 2 - 1 && val->pilea->index != val->len - 1 && val->pilea->index != val->len - 2)
// 			{
// 				ft_pushb(&val->pilea, &val->pileb);
// 			}
// 			ft_rotatepilea(&val->pilea);

// 			tmp = val->pilea;
// 		}

	
// 	 }
// }



// parfait

// void	ft_casplus(t_val *val)
// {
// 	t_list	*tmp;
// 	int		i;
// 	int 	check;

// 	tmp = val->pilea;
// 	i = ft_lstsize(tmp);
	
// 	while (val->pilea->next->next)
// 	{
// 		i = i / 2;
// 		tmp = val->pilea;
// 		check = val->len - ((val->len - ft_lstsize(val->pileb)) / 2);
// 		while (ft_lstsize(tmp) > i  && val->pilea->next->next && i != 2)
// 		{
	
// 			if (val->pilea->index < check  && val->pilea->index != val->len - 1 && val->pilea->index != val->len - 2)
// 			{
// 				ft_pushb(&val->pilea, &val->pileb);
// 			}
// 			ft_rotatepilea(&val->pilea);
// 			tmp = val->pilea;
	
// 		}

// 	}

// }



//


	// t_list	*tmp;
	// int		i;
	// int 	check;

	// tmp = val->pilea;
	// i = ft_lstsize(tmp);
	
	// while (val->pilea->next->next)
	// {
	// 	i = i / 2;
	// 	tmp = val->pilea;
	// 	check = val->len - ((val->len - ft_lstsize(val->pileb)) / 2);
	// 	while (ft_lstsize(tmp) > i  && val->pilea->next->next && i != 2)
	// 	{
	// 		if (val->pilea->index < check  && val->pilea->index != val->len - 1 && val->pilea->index != val->len - 2)
	// 		{
	// 			ft_pushb(&val->pilea, &val->pileb);
	// 		}
	// 		ft_rotatepilea(&val->pilea);
	// 		tmp = val->pilea;
	// 	}
	// }
	// check = val->len - ((val->len - ft_lstsize(val->pileb)) / 2);
	// ft_pusha(&val->pilea, &val->pileb);
	// while (val->pileb->index > check)
	// {
	// 	if(val->pileb->index < val->pilea->index)
	// 		ft_pusha(&val->pilea, &val->pileb);
	// 	if(val->pileb->index > val->pilea->index)
	// 	{
	// 		while (val->pilea->index < val->pileb->index)
	// 			ft_rotatepilea(&val->pilea);
	// 		ft_pusha(&val->pilea, &val->pileb);
	// 	}
	// 	*val = ft_minmax(val->pilea, tmp, *val);
	// 	while (val->pilea->index != val->min)
	// 			ft_rotaterevpilea(&val->pilea);
	// }
	// check = val->len - ((val->len - ft_lstsize(val->pileb)) / 2);
	// while (val->pileb->index > check)
	// {
	// 	if(val->pileb->index < val->pilea->index)
	// 		ft_pusha(&val->pilea, &val->pileb);
	// 	if(val->pileb->index > val->pilea->index)
	// 	{
	// 		while (val->pilea->index < val->pileb->index)
	// 			ft_rotatepilea(&val->pilea);
	// 		ft_pusha(&val->pilea, &val->pileb);
	// 	}
	// 	*val = ft_minmax(val->pilea, tmp, *val);
	// 	while (val->pilea->index != val->min)
	// 			ft_rotaterevpilea(&val->pilea);
	// }

	// while (val->pileb)
	// {
	// 	// if(val->pileb->index == 49)
	// 	// 	ft_pusha(&val->pilea, &val->pileb);
	// 	tmp = val->pileb;
	// 	if (val->pileb->index == val->pilea->index - 1)
	// 		ft_pusha(&val->pilea, &val->pileb);
	// 	else 
	// 	{
	// 		if (ft_checknearindex(&tmp, val->pilea->index - 1) > ft_lstsize(tmp) / 2)
	// 		{
	// 			while (val->pileb->index != val->pilea->index - 1 )
	// 				ft_rotaterevpileb(&val->pileb);
	// 		}
	// 		else
	// 		{
	// 			while (val->pileb->index != val->pilea->index - 1)
	// 				ft_rotatepileb(&val->pileb);
	// 		}
			
			
	// 		ft_pusha(&val->pilea, &val->pileb);
	// 	}
	// }



// 	void	ft_casplus(t_val *val)
// {
// 	t_list	*tmp;
// 	int		i;
// 	int		count;
// 	int		saveindex;

// 	i = 0; // val->binlen - 1;
	
// 	while (i + 1 <  val->binlen - 1)
// 	{
// 		tmp = val->pilea;
// 		saveindex = ft_saveindex(tmp, i);
// 		count = ft_countunit(&val->pilea, i);
	
// 		while (count > 0)
// 		{
// 			if (val->pilea->binary[i] == 1)
// 			{
// 				ft_pushb(&val->pilea, &val->pileb);
// 				count--;
// 			}
// 			else
// 				ft_rotatepilea(&val->pilea);
// 		}
// 		while (val->pilea->index != saveindex && i < val->binlen)
// 			ft_rotatepilea(&val->pilea);
		
		
		
// 		i++;
// 	}
// 	while (val->pilea)
// 			ft_pushb(&val->pilea, &val->pileb);
// 	while (val->pileb->index != val->len - 1)
// 		ft_rotaterevpileb(&val->pileb);
// 	ft_pusha(&val->pilea, &val->pileb);
// 	while (val->pileb)
// 	{
		
// 		tmp = val->pileb;
// 		if (val->pileb->index == val->pilea->index - 1)
// 			ft_pusha(&val->pilea, &val->pileb);
// 		else if (ft_checknearindex(&tmp, val->pileb->index - 1) > (ft_lstsize(tmp) / 2))
// 		{
// 			while (val->pileb->index != val->pilea->index - 1)
// 				ft_rotaterevpileb(&val->pileb);
// 			ft_pusha(&val->pilea, &val->pileb);
// 		}
// 		else 
// 		{
// 			while (val->pileb->index != val->pilea->index - 1)
// 				ft_rotatepileb(&val->pileb);
// 			ft_pusha(&val->pilea, &val->pileb);
// 		}
		
// 	}
// }
