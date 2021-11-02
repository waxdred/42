#include "libft.h"

void	ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;
	size_t		i;

	i = 0;
	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	if (!src)
		return (NULL);
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return ((void*)dest);
}
