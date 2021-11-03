#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (copy == NULL)
		return (NULL);
	else
		copy = ft_strcpy(copy, s1);
	return (copy);
}
