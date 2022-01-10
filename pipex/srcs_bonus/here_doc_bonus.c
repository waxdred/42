/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:10:21 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/09 17:02:29 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

void	ft_loop(t_env *env, int fd)
{
	char	*buff;

	while (1)
	{
		write(1, "heredoc> ", 9);
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

	i = 3;
	env->fdin = open(env->fn, O_RDONLY);
	env->fdout = open(av[ac -1], O_CREAT
			| O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR
			| S_IRGRP | S_IWGRP | S_IROTH);
	env->save_fdin = dup(STDIN);
	env->save_fdout = dup(STDOUT);
	dup2(env->fdin, STDIN);
	dup2(env->fdout, STDOUT);
	ft_redir(av[3], envp, env);
	while (i < ac - 2)
	{
		ft_free_split(env);
		ft_redir(av[i++], envp, env);
	}
	ft_free_split(env);
	ft_exec(av[i], envp, env, 1);
	close(env->fdin);
	close(env->fdout);
}

void	ft_here_doc(t_env *env, char **av, int ac, char **envp)
{
	int	fd;

	env->fn = (char *)ft_strdup(".here_doc");
	fd = open(env->fn, O_CREAT | O_WRONLY | O_RDONLY | O_TRUNC, 0644);
	if (fd < 0)
		return ;
	ft_loop(env, fd);
	ft_herepipe(env, ac, av, envp);
	unlink(env->fn);
	free(env->fn);
	close(fd);
}

int	ft_fd(char **av, int ac, t_env *env)
{		
	if (env->here_doc == 0)
	{
		env->fdin = open(av[1], O_RDONLY, 0644);
		if (env->fdin < 0)
		{
			ft_putstr_fd("Infile not found: \n", 1);
			return (-1);
		}
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
