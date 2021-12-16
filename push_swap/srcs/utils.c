
#include "../includes/push_swap.h"

int	ft_stack_len(t_pile *stack, t_swap *env)
{
	while (stack != NULL)
	{
		stack = stack->next;
		env->len++;
	}
	return (env->len);
}
