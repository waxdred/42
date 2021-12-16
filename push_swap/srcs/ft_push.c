
#include "../includes/push_swap.h"

t_pile	*ft_create_elem(int data)
{
	t_pile	*stack;

	stack = (t_pile*)malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->data = data;
	stack->next = NULL;
	return (stack);
}

void	ft_push_back(t_pile **stack, int data)
{
	if (*stack)
	{
		if ((*stack)->next)
			ft_push_back(&(*stack)->next, data);
		else
			(*stack)->next = ft_create_elem(data);
	}
	else
		*stack = ft_create_elem(data);
}

t_pile	*ft_push_param(int ac, char **av)
{
	int	i;
	int	data;
	t_pile	*stack;

	stack = NULL;
	i = 1;
	if (ac)
	{
		while (i < ac)
		{
			if (ft_error(av[i]) == -1)
				return (NULL);
			data = ft_atoi(av[i]);
			if (ft_check_doublon(stack, data) == -1)
				return (NULL);
			ft_push_back(&stack, ft_atoi(av[i]));
			i++;
		}
	}
	return (stack);
}
