/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:38:00 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/09 17:32:38 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

void	ft_exec(char *cmd, char **envp, t_env *env)
{
	env->cmd = ft_split(cmd, ' ');
	env->bin = ft_get_path(env->cmd[0], envp, env);
	execve(env->bin, env->cmd, envp);
	dup2(env->save_fdout, STDOUT);
	ft_putstr_fd(env->shell, 1);
	free(env->shell);
	ft_putstr_fd("command not found: ", 1);
	ft_putstr_fd(env->bin, 1);
	free(env->bin);
	ft_putstr_fd("\n", 1);
	dup2(env->fdout, STDOUT);
	exit (-1);
}

void	ft_redir(char *cmd, char **envp, t_env *env)
{
	int	status;

	if (ft_check_parsing(cmd) == -1)
		ft_get_pipe(env, cmd);
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
	if (ft_fd(av, ac, env) == -1)
		return ;
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
	if (ac >= 6)
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
