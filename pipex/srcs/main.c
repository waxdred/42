/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:38:00 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/09 17:05:53 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exec(char *cmd, char **envp, t_env *env)
{
	if (ft_check_parsing(cmd, env) == -1)
		cmd = ft_get_pipe(env, cmd);
	env->cmd = ft_split(cmd, ' ');
	env->bin = ft_get_path(env->cmd[0], envp, env);
	execve(env->bin, env->cmd, envp);
<<<<<<< HEAD
	dup2(env->save_fdout, STDOUT);
	ft_putstr_fd(env->shell, 1);
	free(env->shell);
	ft_putstr_fd("command not found: ", 1);
	ft_putstr_fd(env->bin, 1);
	free(env->bin);
	ft_putstr_fd("\n", 1);
	dup2(env->fdout, STDOUT);
=======
	ft_putstr_fd("pipex: command not found: ", STDERR);
	ft_putstr_fd(env->bin, STDERR);
	ft_putstr_fd("\n", STDERR);
>>>>>>> 23546124416ddbcd391e1cb2673b331cf2900ecd
	exit (-1);
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

<<<<<<< HEAD
int	ft_fd(char **av, int ac, t_env *env)
{		
	env->fdin = open(av[1], O_RDONLY, 0644);
	if (env->fdin < 0)
	{
		ft_putstr_fd("Infile not found: \n", 1);
		return (-1);
	}
	env->fdout = open(av[ac -1], O_CREAT
			| O_WRONLY | O_TRUNC, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH, 0644);
	if (env->fdout < 0)
		return (-1);
	env->save_fdin = dup(STDIN);
	env->save_fdout = dup(STDOUT);
	dup2(env->fdin, STDIN);
	dup2(env->fdout, STDOUT);
	return (0);
}

int	main(int ac, char **av, char **envp)
=======
int	ft_fd(int ac, char **av, t_env *env)
>>>>>>> 23546124416ddbcd391e1cb2673b331cf2900ecd
{
	if (av[2][0] == '\0')
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
	if (av[3][0] != '\0')
	{
<<<<<<< HEAD
		if (ft_fd(av, ac, env) == -1)
			return (-1);
=======
>>>>>>> 23546124416ddbcd391e1cb2673b331cf2900ecd
		ft_redir(av[2], envp, env);
		ft_free_split(env);
		ft_exec(av[3], envp, env);
		ft_free_split(env);
	}
	else
	{
		ft_exec(av[2], envp, env);
		ft_free_split(env);
	}
	close(env->fdin);
	close(env->fdout);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_env	*env;

	env = ft_memalloc(sizeof(t_env));
	if (!env)
		return (-1);
	if (ac == 5)
		ft_pipex(ac, av, env, envp);
	else
		ft_putstr_fd("Invalid number of arguments.\n", 2);
	ft_free_split(env);
	free(env);
	return (0);
}
