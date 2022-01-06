/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:38:00 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/04 22:38:00 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

void	ft_free_struct(t_env *env)
{
	free(env->bin);
	free(env);
}

void	ft_exec(char *cmd, char **envp, t_env *env)
{
	env->cmd = ft_split(cmd, ' ');
	env->bin = ft_get_path(env->cmd[0], envp);
	execve(env->bin, env->cmd, envp);
	perror("execve() failed");
}

void	ft_redir(char *cmd, char **envp, t_env *env)
{
	pipe(env->pipefd);
	env->pid = fork();
	if (env->pid)
	{
		close(env->pipefd[1]);
		dup2(env->pipefd[0], STDIN);
		waitpid(env->pid, NULL, 0);
	}
	else
	{
		close(env->pipefd[0]);
		dup2(env->pipefd[1], STDOUT);
		ft_exec(cmd, envp, env);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_env	*env;

	env = ft_memalloc(sizeof(t_env));
	if (!env)
		return (-1);
	if (ac == 5)
	{
		env->fdin = open(av[1], O_RDONLY);
		env->fdout = open(av[ac -1], O_CREAT
				| O_WRONLY | O_TRUNC, S_IRUSR
				| S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
		dup2(env->fdin, STDIN);
		dup2(env->fdout, STDOUT);
		ft_redir(av[2], envp, env);
		ft_free_split(env);
		ft_exec(av[3], envp, env);
	}
	else
		write(STDERR, "Invalid number of arguments.\n", 29);
	ft_free_split(env);
	free(env);
	return (1);
}
