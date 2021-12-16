
#include "../includes/push_swap.h"

int	ft_check_doublon(t_pile *stack, int data)
{
	t_pile	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->data == data)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_stack_max(ssize_t data)
{
	if (data < INT_MIN || data > INT_MAX)
		return (-1);
	return (0);
}

int	ft_num(char *av)
{
	while (*av)
	{
		if (*av == '-' || *av == '+')
			av++;
		if (ft_isdigit(*av))
			return (-1);
		av++;
	}
	return (0);
}

int	ft_error(char *av)
{
	if (ft_num(av))
		return (-1);
	return (0);
}
