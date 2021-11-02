#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int n;

	n = ft_strlen((char *)str);
	while (n >= 0)
	{
		if (str[n] == c)
			return ((char *)str + n);
		n--;
	}
	return (NULL);
}
