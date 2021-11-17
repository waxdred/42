#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *left;

	if (lst != NULL)
	{
		left = lst;
		while (1)
		{
			(*f)(left->content);
			left = left->next;
			if (left == NULL)
				return ;
		}
	}
}
