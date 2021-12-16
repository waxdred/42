
#include "../includes/push_swap.h"

void	ft_clear_stack(t_pile **list)
{
	if (*list != NULL)
	{
		ft_clear_stack(&((*list)->next));
		free(*list);
		*list = NULL;
	}
}
