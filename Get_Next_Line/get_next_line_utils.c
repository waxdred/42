



#include "get_next_line.h"

int	ft_strichr(char *s, int c)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return (i);
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

char	*ft_stredup(char *str, int index)
{
	int	i;
	int	len;
	char	*dest;

	i = 0;
	len = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * (len - index) + 1);
	if (!dest)
		return (NULL);
	while (str[index])
	{
		dest[i] = str[index];
		i++;
		index++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strldup(char *str, int len)
{
	int	i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
