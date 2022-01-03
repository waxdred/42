/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:23:20 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/16 19:23:20 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	ft_free_struct(t_env *env)
{
	ft_freetab(env->cmd1);
	ft_freetab(env->cmd2);
	free(env->bin);
	free(env);
}

void	child_one(char **envp, t_env *env)
{
	env->bin  = ft_get_path(env->cmd1[0], envp);
	execve(env->bin, env->cmd1, NULL);
	perror("execve() failed");
}

void	child_two(char **envp, t_env *env)
{
	env->bin = ft_get_path(env->cmd2[0], envp);
	dup2(env->fd2, STDOUT_FILENO);
	execve(env->bin, env->cmd2, NULL);
	perror("execve() failed");
}

void	pipex(char **envp, t_env *env)
{
	int	status;
	int	end[2];

	pipe(end);
	env->child1 = fork();
	if (env->child1 < 0)
		return (perror("Fork: "));
	if (env->child1 == 0)
			child_one(envp, env);
		env->child2 = fork();
	if (env->child2 < 0)
		return (perror("Fork: "));
	if (env->child2 == 0)
		child_two(envp, env);
	close(end[0]);
	close(end[1]);
	waitpid(env->child1, &status, 0);
	waitpid(env->child2, &status, 0);
}


int main(int argc, char **argv, char **envp)
{
	t_env	*env;
	int	fd1;
	int	fd2;

	env = ft_memalloc(sizeof(t_env));
	if (argc == 5)
	{
		env->fd1 = open(argv[1], O_RDONLY);
		env->fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (env->fd1 < 0 || env->fd2 < 0)
			return (-1);
		env->cmd1 = ft_split(argv[2], ' ');
		env->cmd2 = ft_split(argv[3], ' ');
		pipex(envp, env);
	}
	else
		write(2, "invalid number of arguments.\n", 29);
	ft_free_struct(env);
	return (0);
}
