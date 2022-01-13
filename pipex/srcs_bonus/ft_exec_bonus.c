/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:38:00 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/04 22:38:00 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

void	ft_exec_cmd(char **envp, t_env *env, int check)
{
	if (check == 0)
	{
		execve(env->bin, env->cmd, envp);
		ft_putstr_fd("pipex: command not found: ", STDERR);
		ft_putstr_fd(env->bin, STDERR);
		ft_putstr_fd("\n", STDERR);
		exit (EXIT_FAILURE);
	}
	else if (check == 1)
	{
		env->pid[env->argc - 2] = fork();
		if (env->pid[env->argc - 2] == 0)
		{
			execve(env->bin, env->cmd, envp);
			ft_putstr_fd("pipex: command not found: ", STDERR);
			ft_putstr_fd(env->bin, STDERR);
			ft_putstr_fd("\n", STDERR);
			exit (EXIT_FAILURE);
		}
	}
}

void	ft_get_cmd(char *cmd, char **envp, t_env *env)
{
		env->cmd = ft_split(cmd, ' ');
		env->bin = ft_get_path(env->cmd[0], envp, env);
}
