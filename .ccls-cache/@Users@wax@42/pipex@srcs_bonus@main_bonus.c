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

void	ft_redir(char *cmd, char **envp, t_env *env, int count)
{
	pipe(env->pipefd);
	ft_get_cmd(cmd, envp, env);
	env->pid[count] = fork();
	if (env->pid[count])
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

void	ft_fd(t_env *env, char **av, int ac)
{
	env->fdout = open(av[ac -1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	env->save_fdout = dup(STDOUT);
	if (env->fdout < 0)
		exit (EXIT_FAILURE);
	dup2(env->fdin, STDIN);
	dup2(env->fdout, STDOUT);
}

void	ft_pipex(t_env *env, int ac, char **av, char **envp)
{
	int	i;
	int	stop;

	i = 2;
	env->count = -1;
	stop = 2;
	if (env->here_doc == 0)
	{
		env->fdin = open(av[1], O_RDONLY);
		if (env->fdin < 0)
			ft_print_error(0, av, env);
	}
	if (ft_check_empty(av, ac, 0) == -1)
		ft_print_error(1, av, env);
	if (av[ac - 2][0] == '\0' || (ft_check_empty_string(av[ac - 2]) == -1))
		stop = 3;
	ft_fd(env, av, ac);
	ft_redir(av[i], envp, env, env->count++);
	while (i < ac - stop)
		ft_redir(av[i++], envp, env, env->count++);
	ft_get_cmd(av[i], envp, env);
	ft_exec_cmd(envp, env, 1);
	env->count++;
	ft_free_split(env);
}

void	ft_wait_fork(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->count)
	{
		waitpid(env->pid[i], NULL, WUNTRACED);
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_env	*env;

	env = ft_memalloc(sizeof(t_env));
	if (!env)
		return (-1);
	env->argc = ac;
	ft_args_check(av, env);
	env->pid = ft_error_malloc((int *)malloc(sizeof(int) * ac - 2), env);
	if (env->here_doc == 1 && ac >= 6)
		ft_here_doc(env, av, ac, envp);
	else if (ac >= 5)
		ft_pipex(env, ac, av, envp);
	else
		ft_putstr_fd("Invalid number of arguments.\n", STDERR);
	ft_wait_fork(env);
	close(env->fdin);
	close(env->fdout);
	free(env->pid);
	free(env);
	return (0);
}
