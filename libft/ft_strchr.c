#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char*)str + i);
		i++;
	}
	return (NULL);
}
#include <stdio.h>

int main() {

    const char *str = "The C Language";
    printf("%s\n", ft_strchr(str, 'C'));
    return 0;
}

