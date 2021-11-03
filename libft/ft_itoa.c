#include "libft.h"

static int	ft_len_str(long long int n)
{
	long long int	i;

	i = 1;
	if (n < 0)
		n = n * -1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_complet(char *str, long long int n, int len)
{
	int		debut;

	str[len] = '\0';
	len = len - 1;
	if (n < 0)
	{
		n = n * -1;
		debut = 1;
		str[0] = '-';
	}
	else
		debut = 0;
	while (len >= debut)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int		len;
	long long int	lln;

	lln = n;
	len = ft_len_str(lln);
	if (lln < 0)
		len = len + 1;
	str = (char *)ft_memalloc(len + 1);
	if (!str)
		return(NULL);
	str = ft_complet(str, lln, len);
	return (str);
}
