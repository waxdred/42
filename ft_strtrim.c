/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:23:37 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/04 01:43:41 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_complet(char const *s1, char const *set, char *dest)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (ft_check(s1[i], set))
		i++;
	while (ft_check(s1[len-1], set))
		len--;
	while (i < len)
	{
		dest[j] = s1[i];
		j++;
		i++;
	}
	return (dest);
}

static size_t	ft_get_trim_len(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	trimlen;

	i = 0;
	len = ft_strlen(s1);
	trimlen = len;
	while (ft_check(s1[i], set))
		i++;
	while (ft_check(s1[len], set))
	{
		len--;
		i++;
	}
	return (trimlen - i);
}

char *ft_strtrim(char const *s1, char const *set)
{
	size_t	trimlen;
	size_t	len;
	char	*dest;

	trimlen = ft_get_trim_len(s1, set);
	dest = (char *)ft_memalloc(trimlen + 1);
	len = ft_strlen(s1);
	if (!s1 || len < 1)
		return (NULL);
	if (!dest)
		return (NULL);
	dest = ft_complet(s1, set, dest);
	return (dest);
}
