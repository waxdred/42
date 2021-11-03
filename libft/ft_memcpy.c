#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	while (n > 0)
	{
		*pdst++ = *psrc++;
		n--;
	}
	return (dst);
}
