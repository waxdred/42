/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:50:16 by rcuminal          #+#    #+#             */
/*   Updated: 2021/12/24 00:43:29 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_val
{
	t_list	*pilea;
	t_list	*pileb;
	int	max;
	int	min;
	int	*output;
	int	*input;
	int	*trieur;
	int	len;
	int	binlen;
	
}			t_val;

t_list	*ft_callswap(t_list **pilea, t_list *tmp);
t_list	*ft_castrois(t_list *pilea, t_list *tmp, t_val val);
t_list	*ft_cascinq(t_list *pilea, t_list *pileb, t_list *tmp, t_val *val);
t_list	*ft_cascinqo(t_list *pilea, t_list *pileb, t_list *tmp, t_val *val);

void	ft_pusha(t_list **pilea, t_list **pileb);
void	ft_pushb(t_list **pilea, t_list **pileb);
void	ft_swaptopa(t_list **alst, t_list *new);
void	ft_swaptopb(t_list **alst, t_list *new);
void	ft_rotatepilea(t_list **pile);
void	ft_rotatepileb(t_list **pile);
void	ft_rotaterevpilea(t_list **pile);
void	ft_rotaterevpileb(t_list **pile);

t_list	*ft_lstplus(t_list *lst);
int		ft_lstpluscheck(t_list *lst, int val);
void	ft_lstprint(t_list *lst);
void	ft_parsargv(char **argv, t_list **pilea, int argc);
int		*ft_parsinput(t_list *pile, int *tab);
int		ft_prefix(int tab, int	coeff);
int		ft_sizevalue(int min, int max);
void	ft_cumulprefix(t_val val, int coef);
void	ft_sortoutput(t_val val, int coef);
void	ft_transfert(t_val val);
void	ft_casneg(t_val val);
void	ft_addindex(t_val *val);

t_val	ft_minmax(t_list *pile, t_list *tmp, t_val val);
int		ft_checkmin(t_list **pile);
int		ft_checkmax(t_list **pile);
int		ft_checknear(t_list **pile, int i);
int	ft_checknearindex(t_list **pile, int i);
int		ft_checkorder(t_list **pile);
int		ft_checkdoublons(char **argv);
int	ft_checknearbinary(t_list **pile, int i);

int    *ft_dec_to_bin(int nbr, int size);
int    ft_count_len_binary(int nbr);
int		ft_countunit(t_list **temp, int unit);
int	ft_saveindex(t_list *pile, int unit);

#endif