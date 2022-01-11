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

#include "../includes_bonus/pipex_bonus.h"

int	ft_check_empty(char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac - 2)
	{
		if (av[i][0] == '\0')
			return (-1);
		i++;
	}
	return (0);
}

void	ft_print_error(int error, char **av, t_env *env)
{
	if (error == 0)
	{
		ft_putstr_fd(av[2], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(-1);
	}
	if (error == 1)
	{
		ft_putstr_fd("pipex: parse error near `|'\n", 1);
		exit (-1);
	}
	if (error == 2)
	{
		ft_putstr_fd("pipex: command not found ", 2);
		ft_putstr_fd(env->bin, 2);
		ft_putstr_fd("\n", 2);
		exit(-1);
	}
}

void	ft_get_errors(char *cmd, t_env *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!env->error)
		env->error = (char **)ft_memalloc(sizeof(char *) * env->argc);
	if (!env->error)
		return ;
	while (env->error[i])
		i++;
	env->error[i] = (char *)ft_memalloc(sizeof(char) * ft_strlen(cmd) + 1);
	if (env->error[i])
	{
		ft_freetab(env->error);
		return ;
	}
	while (*cmd)
		env->error[i][j++] = *cmd++;
}
