

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
#include <stdio.h>
#include <limits.h>

typedef struct	s_pile
{
	int	data;
	struct s_pile	*next;
}		t_pile;

typedef struct	s_swap
{
	t_pile	*pa;
	t_pile	*pb;
	int	min_a;
	int	min_b;
	int	max_a;
	int	max_b;
}		t_swap;

void	ft_clear_stack(t_pile **list);
t_pile	*ft_push_param(int ac, char **av);
int	ft_check_doublon(t_pile *stack, int data);
int	ft_error(char *av);
#endif
