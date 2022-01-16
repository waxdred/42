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

#include "../includes/pipex.h"

void	ft_redir(char *cmd, char **envp, t_env *env)
{
	pipe(env->pipefd);
	ft_get_cmd(cmd, envp, env);
	env->pid[0] = fork();
	if (env->pid[0])
	{
		close(env->pipefd[1]);
		dup2(env->pipefd[0], STDIN);
	}
	else
	{
		close(env->pipefd[0]);
		dup2(env->pipefd[1], STDOUT);
		ft_exec_cmd(envp, env, 0);
	}
	ft_free_split(env);
}

int	ft_fd(int ac, char **av, t_env *env)
{
	if (ft_check_empty(av, ac) == -1)
	{
		ft_putstr_fd("pipex: parse error near `|' \n", 2);
		return (-1);
	}
	env->fdin = open(av[1], O_RDONLY, 0644);
	{
		if (env->fdin < 0)
		{
			ft_putstr_fd("pipex: No such file or directory\n", 2);
			return (-1);
		}
	}
	env->fdout = open(av[ac -1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (env->fdout < 0)
		return (-1);
	env->save_fdin = dup(0);
	dup2(env->fdin, STDIN);
	dup2(env->fdout, STDOUT);
	return (0);
}

int	ft_pipex(int ac, char **av, t_env *env, char **envp)
{	
	if (ft_fd(ac, av, env) == -1)
		return (-1);
	if (ft_check_empty_string(av[3]) == 0)
	{
		ft_redir(av[2], envp, env);
		ft_get_cmd(av[3], envp, env);
		ft_exec_cmd(envp, env, 1);
	}
	else
	{
		ft_get_cmd(av[2], envp, env);
		ft_exec_cmd(envp, env, 1);
	}
	close(env->fdin);
	close(env->fdout);
	dup2(env->save_fdin, STDIN);
	dup2(env->save_fdout, STDOUT);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_env	*env;

	env = ft_memalloc(sizeof(t_env));
	if (!env)
		return (-1);
	if (ac == 5)
	{
		if (ft_pipex(ac, av, env, envp) == -1)
			exit (EXIT_FAILURE);
	}
	else
	{
		ft_putstr_fd("Invalid number of arguments.\n", 2);
		free(env);
		return (-1);
	}
	ft_free_split(env);
	waitpid(env->pid[0], NULL, WUNTRACED);
	waitpid(env->pid[1], NULL, WUNTRACED);
	free(env);
	return (0);
}
