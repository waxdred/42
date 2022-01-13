/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:37:50 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/04 22:37:50 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

int	ft_check_empty(char **av, int ac, int st)
{
	int	i;
	int	j;
	int	count;

	if (st == 0)
		i = 2;
	else
		i = 3;
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
	}
	if (count == 0)
		return (-1);
	return (0);
}

void	ft_print_error(int error, char **av, t_env *env)
{
	if (error == 0)
	{
		ft_putstr_fd(av[2], STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putstr_fd(av[1], STDERR);
		ft_putstr_fd(": No such file or directory\n", STDERR);
		exit(-1);
	}
	if (error == 1)
	{
		ft_putstr_fd("pipex: parse error near `|'\n", STDERR);
		exit (-1);
	}
	if (error == 2)
	{
		ft_putstr_fd("pipex: command not found ", STDERR);
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

void	*ft_error_malloc(void	*mem, t_env *env)
{
	if (!mem)
	{
		free(env);
		ft_putendl_fd("Error allocation: ", 2);
		exit (EXIT_FAILURE);
	}
	return (mem);
}
