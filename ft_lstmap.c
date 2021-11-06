/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:52:38 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/05 13:52:29 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*new;

	if (!f || !del)
		return (NULL);
	elem = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			new = elem->next;
			ft_lstclear(&elem, del);
		}
		ft_lstadd_back(&elem, new);
		lst = lst->next;
	}
	return (elem);
}
