#include "libft.h"

void	ft_memset(void *b, int c, size_t len)
{
	unsigned char 	*pb;
	size_t		i;

	pb = (unsigned char*)b;
	i = 0;
	if (!b)
		return (NULL);
	while(i <= len)
	{
		pb[i] = (unsigned char)c;
		i++;
	}
}
