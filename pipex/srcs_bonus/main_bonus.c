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
	if (env->bin_check == 1)
		ft_print_error(2, envp, env);
	exit (-1);
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
	}
	else
	{
		close(env->pipefd[0]);
		dup2(env->pipefd[1], STDOUT);
		ft_exec(cmd, envp, env);
	}
}

void	ft_fd(t_env *env, char **av, int ac)
{
	env->fdout = open(av[ac -1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	env->save_fdout = dup(STDOUT);
	dup2(env->fdin, STDIN);
	dup2(env->fdout, STDOUT);
}

void	ft_pipex(t_env *env, int ac, char **av, char **envp)
{
	int	i;
	int	stop;

	i = 2;
	stop = 2;
	if (env->here_doc == 0)
	{
		env->fdin = open(av[1], O_RDONLY);
		if (env->fdin < 0)
			ft_print_error(0, av, env);
	}
	if (ft_check_empty(av, ac) == -1)
		ft_print_error(1, av, env);
	if (av[ac - 2][0] == '\0')
		stop = 3;
	ft_fd(env, av, ac);
	ft_redir(av[i], envp, env);
	while (i < ac - stop)
	{
		ft_free_split(env);
		ft_redir(av[i++], envp, env);
	}
	ft_free_split(env);
	ft_exec(av[i++], envp, env);
}

int	main(int ac, char **av, char **envp)
{
	t_env	*env;

	env = ft_memalloc(sizeof(t_env));
	if (!env)
		return (-1);
	env->argc = ac;
	ft_args_check(av, env);
	if (env->here_doc == 1 && ac >= 6)
		ft_here_doc(env, av, ac, envp);
	if (ac >= 5)
	{
		ft_pipex(env, ac, av, envp);
		close(env->fdin);
		close(env->fdout);
	}
	else
		ft_putstr_fd("Invalid number of arguments.\n", STDERR);
	ft_free_split(env);
	free(env);
	return (1);
}
