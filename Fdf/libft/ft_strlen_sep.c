/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_sep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:48:01 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/20 01:48:01 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_sep(char const *s, char c)
{
	int	i;
	int	len;
	int	check;

	i = 0;
	len = 0;
	check = 0;
	while (s[i])
	{
		if (s[i] == c)
			check = 0;
		if (check == 0 && s[i] != ' ')
		{
			len++;
			check = 1;
		}
	i++;
	}
	return (len);
}
