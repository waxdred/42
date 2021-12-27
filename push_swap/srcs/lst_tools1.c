/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:20:15 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/28 00:20:15 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_add_back(t_pile **alst, t_pile *ne)
{
	t_pile	*elem;

	if (ne == NULL || alst == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = ne;
		return ;
	}
	elem = ft_last(*alst);
	elem->next = ne;
}
