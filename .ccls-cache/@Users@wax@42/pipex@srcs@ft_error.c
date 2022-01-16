/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:37:50 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/04 22:37:50 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_check_empty(char **av, int ac)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	while (i < ac - 2)
	{
		count = 0;
		j = 0;
		while (av[i][j] != '\0')
		{
			if (ft_isa_white_space(av[i][j]) == 0)
				count++;
			j++;
		}
		if (count == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_empty_string(char *cmd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd[i] != '\0')
	{
		if (ft_isa_white_space(cmd[i]) == 0)
			count++;
		i++;
	}
	if (count == 0)
		return (-1);
	return (0);
}
