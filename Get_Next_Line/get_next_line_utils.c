/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 22:34:18 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/14 23:29:33 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s1)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (0);

	while (s1[i])
		i++;
	return (i);
}

void	ft_bzero(void *b, size_t n)
{
	unsigned char	*dest;
	size_t		i;

	dest = b;
	i = 0;
	while (i++ < n)
		*dest++ = 0;
}

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);;
	return (mem);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	return (dst);
}

int	ft_strichr(char *s, int c)
{
	int i;

	i = -1;
	if (!s)
		return (-1);
	while (s[++i])
		if (s[i] == (char)c)
			return (i);
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

char	*ft_strncat(char *dest, char *src, int size)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[size] != '\0')
	{
		dest[i] = src[size];
		i++;
		size++;
	}
	dest[i] = '\0';
	return (dest);
}

