

#include "../includes/push_swap.h"

void	ft_print_list(t_pile **stack, t_swap *env)
{
	while (*stack != NULL)
	{
		printf("[%d] \n", (*stack)->data);
		*stack = (*stack)->next;
	}
	printf("len = %d\n", env->len);
}

int main(int argc, char **argv)
{
	t_swap *env;

	if (argc == 1)
		return (-1);	
	env = ft_memalloc(sizeof(t_swap));
	if (!env)
		return (-1);
	env->pa = ft_push_param(argc, argv);
	if (env->pa == NULL)
	{
		ft_clear_stack(&env->pa);
		free(env);
		ft_putstr("Error");
		return (-1);
	}
	ft_stack_len(env->pa, env);
	ft_print_list(&env->pa, env);
	ft_clear_stack(&env->pa);
	free(env);
	return (0);
}
