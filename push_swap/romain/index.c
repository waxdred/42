/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:34:34 by rcuminal          #+#    #+#             */
/*   Updated: 2021/12/24 02:23:36 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_saveindex(t_list *tmp, int unit)
{
	while (tmp->binary[unit] != 1)
		tmp = tmp->next;
	return (tmp->index);
}

void	ft_rotatenonoffi(t_list **pile)
{
	t_list	*tmp;

	tmp = *pile;
	*pile = (*pile)->next;
	tmp->next = NULL;
	ft_lstadd_back(pile, tmp);
	return ;
}

int	ft_prefix(int tab, int	coeff)
{
	tab = (tab >= 0) ? tab : -tab;
	while (coeff - 1 > 0)
	{
		tab /= 10;
		coeff--;
	}
	tab = tab % 10;
	return (tab);
}

int	*ft_parsinput(t_list *pile, int *tab)
{
	int	i;

	i = 0;
	while(pile)
	{
		tab[i] = *pile->content;
		pile = pile->next;
		i++;
	}
	return (tab);
}

int	ft_sizevalue(int min, int max)
{
	int	i;

	i = 0;
	min = (min <= 0) ? -min : min;
	max = (max <= 0) ? -max : max;
	max = (min >= max) ? min : max;
	while (max > 0)
	{
		max = max / 10;
		i++;
	}
	return (i);
}

void	ft_sortoutput(t_val val, int coef)
{
	int	i;
	int	prefix;

	i = val.len - 1;
	while (i >= 0)
	{
		prefix = ft_prefix(val.input[i], coef);
		val.trieur[prefix] -= 1;
		val.output[val.trieur[prefix]] = val.input[i];
		i--;
	}
}

void	ft_cumulprefix(t_val val, int coef)
{
	int	i;

	i = 0;
	while (i < val.len)
	{
		val.trieur[ft_prefix(val.input[i], coef)] +=1;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		val.trieur[i] += val.trieur[i - 1];
		i++;
	}
	return ;
}

void	ft_transfert(t_val val)
{
	int	i;

	i = 0;
	while (i < val.len)
	{
		val.input[i] = val.output[i];
		i++;
	}
	i = 0;
	while (i < 10)
	{
		val.trieur[i] = 0;
		i++;
	}
			
}

int	ft_countneg(t_val val)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < val.len)
	{
		if (val.input[j] < 0)
			i++;
		j++;
	}
	return (i);
}

void	ft_casneg(t_val val)
{
	int	*negative;
	int	*positive;
	int	i;
	int	j;
	int	k;

	i = val.len ;
	j = 0;
	k = 0;
	
	negative = malloc(sizeof(int) * ft_countneg(val));
	if (!negative)
		return ;
	positive = malloc(sizeof(int) * val.len - ft_countneg(val) - 1);
	if (!positive)
		return ;
	while (i >= 0)
	{
		if (val.input[i] < 0)
		{
			negative[j] = val.input[i];
			j++;
		}
		i--;
	}
	i = 0;
	while (i <= val.len)
	{
		if (val.input[i] >= 0)
		{
			positive[k] = val.input[i];
			k++;
		}	
		i++;
	}
	k = 0;
	i = 0;
	while (i < val.len && negative[i])
	{
		val.input[i] = negative[i];
		i++;
	}
	while (i < val.len && positive[k])
	{
		val.input[i] = positive[k];
		i++;
		k++;
	}
	
	free (negative);
	free (positive);
}

int    ft_count_len_binary(int nbr)
{
    int    i;
    i = 0;
    while (nbr > 0)
    {
        nbr /= 2;
        i++;
    }
    return (i);;
}
int    *ft_dec_to_bin(int nbr, int size)
{
    int    i;
    int    *binary;
    i = 0;
    binary = (int *)malloc(sizeof(int) * size);
    if (!binary)
        return (NULL);
    while (nbr > 0)
    {
        size--;
        binary[size] = nbr % 2;
        nbr /= 2;
    }
    while (size > 0)
    {
        size--;
        binary[size] = 0;
    }
    return (binary);
}

void	ft_addindex(t_val *val)
{
	int	i;
	t_list	*pile;

	pile = val->pilea;
	val->binlen = ft_count_len_binary(val->len - 1);
	
	while (pile->next)
	{
		i = 0;
		while (val->input[i] != *((int *)(pile)->content))
			i++;
		pile->index = i;
		pile->binary = ft_dec_to_bin(i, val->binlen);
		
		pile = pile->next;
	}
	i = 0;
	while (val->input[i] != *((int *)(pile)->content))
		i++;
	pile->index = i;
	pile->binary = ft_dec_to_bin(i, val->binlen);
}

