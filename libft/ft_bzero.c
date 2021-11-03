#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *ps;

	ps = (unsigned char*)s;
	while (n > 0)
	{
		*ps++ = '\0';
		n--;
	}
}
