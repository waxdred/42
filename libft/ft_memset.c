#include "libft.h"

void	ft_memset(void *b, int c, size_t len)
{
	unsigned char 	*pb;
	size_t		i;

	pb = (unsigned char*)b;
	i = 0;
	while(i < len)
		pb[i++] = (unsigned char)c;
	b = (void *)pb;
}
