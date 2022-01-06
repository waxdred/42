/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:38:00 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/04 22:38:00 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

void	ft_exec(char *cmd, char **envp, t_env *env)
{
	env->cmd = ft_split(cmd, ' ');
	env->bin = ft_get_path(env->cmd[0], envp, env);
	execve(env->bin, env->cmd, envp);
	write(2, "command not found: ", 19);
	write(2, env->bin, ft_strlen(env->bin));
	write(2, "\n", 1);
}

void	ft_redir(char *cmd, char **envp, t_env *env)
{
	int	status;

	pipe(env->pipefd);
	env->pid = fork();
	if (env->pid)
	{
		close(env->pipefd[1]);
		dup2(env->pipefd[0], STDIN);
		waitpid(env->pid, &status, 0);
		if (status > 0)
			exit (0);
	}
	else
	{
		close(env->pipefd[0]);
		dup2(env->pipefd[1], STDOUT);
		ft_exec(cmd, envp, env);
	}
}

void	ft_pipex(t_env *env, int ac, char **av, char **envp)
{
	int	i;

	i = 3;
	if (env->here_doc == 0)
		env->fdin = open(av[1], O_RDONLY);
	env->fdout = open(av[ac -1], O_CREAT
			| O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR
			| S_IRGRP | S_IWGRP | S_IROTH);
	dup2(env->fdin, STDIN);
	dup2(env->fdout, STDOUT);
	ft_redir(av[2], envp, env);
	while (i < ac - 2)
	{
		ft_free_split(env);
		ft_redir(av[i++], envp, env);
	}
	ft_free_split(env);
	ft_exec(av[i], envp, env);
	close(env->fdin);
	close(env->fdout);
}

int	main(int ac, char **av, char **envp)
{
	t_env	*env;

	env = ft_memalloc(sizeof(t_env));
	if (!env)
		return (-1);
	ft_args_check(av, env);
	if (env->here_doc == 1 && ac >= 6)
		ft_here_doc(env, av, ac, envp);
	if (ac >= 5)
		ft_pipex(env, ac, av, envp);
	else
		write(STDERR, "Invalid number of arguments.\n", 29);
	ft_free_split(env);
	free(env);
	return (1);
}
