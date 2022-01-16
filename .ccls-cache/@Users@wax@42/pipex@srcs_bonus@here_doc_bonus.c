/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:10:21 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/05 21:10:21 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

void	ft_loop(t_env *env, int fd)
{
	char	*buff;

	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		buff = get_next_line(0);
		if (!buff)
			exit(-1);
		buff[ft_strlen(buff) - 1] = '\0';
		if (ft_strcmp(buff, env->limiter) == 0)
		{
			free(buff);
			return ;
		}
		buff[ft_strlen(buff)] = '\n';
		write(fd, buff, ft_strlen(buff));
		free(buff);
	}
}

void	ft_herepipe(t_env *env, int ac, char **av, char **envp)
{
	int	i;
	int	stop;

	i = 3;
	stop = 2;
	env->count = -1;
	if (env->error_pipe == 1)
		stop = 3;
	env->fdin = open(env->fn, O_RDONLY);
	env->fdout = open(av[ac -1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	dup2(env->fdin, STDIN);
	dup2(env->fdout, STDOUT);
	ft_redir(av[i], envp, env, env->count++);
	unlink(env->fn);
	free(env->fn);
	while (i < ac - stop)
		ft_redir(av[i++], envp, env, env->count++);
	ft_get_cmd(av[i], envp, env);
	ft_exec_cmd(envp, env, 1);
	env->count++;
	ft_free_split(env);
	close(env->fdin);
	close(env->fdout);
}

void	ft_here_doc(t_env *env, char **av, int ac, char **envp)
{
	int	fd;

	if (ft_check_empty(av, ac, 1) == -1)
	{
		ft_putstr_fd("pipex: parse error near `|'\n", 1);
		exit (-1);
	}
	if (av[ac - 2][0] == '\0')
		env->error_pipe = 1;
	env->fn = (char *)ft_strdup(".here_doc");
	fd = open(env->fn, O_CREAT | O_WRONLY | O_RDONLY | O_TRUNC, 0644);
	if (fd < 0)
		return ;
	ft_loop(env, fd);
	ft_herepipe(env, ac, av, envp);
}

void	ft_args_check(char **av, t_env *env)
{
	if (ft_strncmp(av[1], "here_doc", 7) == 0)
	{
		env->here_doc = 1;
		env->limiter = av[2];
	}
	else
		env->here_doc = 0;
}
