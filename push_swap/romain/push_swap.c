/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:48:28 by rcuminal          #+#    #+#             */
/*   Updated: 2021/12/24 02:46:56 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_print_list(t_list **pa, t_val *env);

t_list	*ft_callswap(t_list **pilea, t_list *tmp)
{
	tmp = *pilea;
	*pilea = (*pilea)->next;
	tmp->next = ft_lstplus(*pilea);
	ft_swaptopa(pilea, tmp);
	return (*pilea);
}

t_val	ft_minmax(t_list *pile, t_list *tmp, t_val val)
{
	tmp = pile;
	val.min = ft_checkmin(&tmp);
	tmp = pile;
	val.max = ft_checkmax(&tmp);
	return (val);
}

void	ft_casplus(t_val *val)
{
	t_list	*tmp;
	int		i;
	int		count;
	int		saveindex;

	i = val->binlen - 1;
	
	while (i  + 1> 0)
	{
		tmp = val->pilea;
		saveindex = ft_saveindex(tmp, i);
		count = ft_countunit(&val->pilea, i);
		while (count > 0)
		{
			if (val->pilea->binary[i] == 0)
			{
				ft_pushb(&val->pilea, &val->pileb);
				count--;
			}
			else
				ft_rotatepilea(&val->pilea);
		}
		while (val->pilea->index != saveindex)
			ft_rotatepilea(&val->pilea);
		while (val->pileb)
			ft_pusha(&val->pilea, &val->pileb);
		i--;
	}

}

void	ft_print(t_val val)
{
	int	i;
	i = 0;
	printf("output     \n");
	while (i < val.len)
	{
		printf("[%d] = %d \n", i, val.input[i]);
		i++;
	}
	printf("\n");
}

void	ft_print_list(t_list **pa, t_val *env)
{
	t_list *tmp;
	int	i;
	tmp = *pa;
	printf("\n");
	while (tmp->next)
	{
		i = 0;
		printf("[");
		while (i < env->binlen)
		{
			printf("%d", tmp->binary[i]);
			i++;
		}
		printf("]  [%d] ====> [%d] \n",tmp->index, *((int *)(tmp)->content));
		tmp = tmp->next;
	}
	i = 0;
	printf("[");
	while (i < env->binlen)
	{
		printf("%d", tmp->binary[i]);
		i++;
	}
	printf("]  [%d] ====> [%d] \n",tmp->index, *((int *)(tmp)->content));
}


int	main(int argc, char **argv)  //check llongueur chaine puis atol puis compar int max min
{
	
	t_list	*tmp;
	t_list	*temp;
	t_val	val;
	int		coeff;
	int		i;
	
	val.len = 0;
	val.pilea = NULL;
	val.pileb = NULL;
	if (ft_checkdoublons(argv) == 0)
		return (write(1, "doublon(s) detecté(s)", 23));
	ft_parsargv(argv, &val.pilea, argc);
	if (ft_checkorder(&val.pilea) == 0)
		return (0);
	tmp = val.pilea;
	val.min = ft_checkmin(&tmp);
	tmp = val.pilea;
	val.max = ft_checkmax(&tmp);
	tmp = val.pilea;
	val.len = ft_lstsize(val.pilea);
	val.trieur = ft_calloc(10, sizeof(int));
	val.output = ft_calloc(val.len + 1, sizeof(int));
	val.input = ft_calloc(val.len + 1, sizeof(int));
	val.input = ft_parsinput(tmp, val.input);
	i = 1;
	coeff = ft_sizevalue(val.min, val.max);
	while (i <= coeff)
	{
		ft_cumulprefix(val, i);
		ft_sortoutput(val, i);
		ft_transfert(val);
		i++;
	}
	
	//ft_casneg(val);
	ft_addindex(&val);
	// if (argc == 4 || ft_lstsize(val.pilea) == 3)
	// 	val.pilea = ft_castrois(val.pilea, tmp, val);
	// if (argc == 6 || ft_lstsize(val.pilea) == 5)
	// 	val.pilea = ft_cascinq(val.pilea, val.pileb, tmp , &val);
	//if (argc > 6 || ft_lstsize(val.pilea) > 5)
	
	ft_casplus(&val);
//	ft_print_list(&val.pilea, &val);
	 //ft_lstprint(val.pilea);
	// ft_lstprint(val.pileb);
	//ft_print_list(&val.pilea, &val);
	free (val.input);
	free (val.output);
	free (val.trieur);
	ft_lstclear(&val.pilea, &free);
	
	return (0);
}














	// ft_lstprint(val.pilea);
	//if (ft_checkorder(&val.pilea) == 0)
	//	return (0);
	// ft_lstprint(val.pilea);
//	i = ft_lstsize(val.pilea);
	// if (argc == 4 || ft_lstsize(val.pilea) == 3)
	// 	val.pilea = ft_castrois(val.pilea, tmp, val);
	// if (argc == 6 || ft_lstsize(val.pilea) == 5)
	// 	val.pilea = ft_cascinq(val.pilea, val.pileb, tmp , &val);
	// if (argc > 6 || ft_lstsize(val.pilea) > 5){
			
	// 			ft_casplus(&val);
	// 			// while (val.pileb)
	// 			// 	ft_pusha(&val.pilea, &val.pileb);
	// 			//pileb = ft_cascinq(pilea, pileb, tmp , &val);
				
				
				
		
				

				
			
	// 	}
	// ft_lstprint(val.pilea);
	// ft_lstprint(val.pileb);
//	ft_lstclear(&val.pilea, &free);
//	return (0);
//}
