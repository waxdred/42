#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *ps;
	size_t i;

	i = 0;
	ps = (unsigned char*)s;
	while (i < n)
	{
		ps[i] = '\0';
		i++;
	}
}
