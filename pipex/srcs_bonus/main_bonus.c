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

void	ft_free_struct(t_env *env)
{
	free(env->bin);
	free(env);
}

void	ft_child(char **envp, t_env *env, char **cmd)
{
	env->bin  = ft_get_path(cmd[0], envp);
	printf("child == %s\n", env->bin);
	close(env->pfd[IN]);
	dup2(env->pfd[OUT], 1);
	close(env->pfd[OUT]);
	execve(env->bin, cmd, NULL);
	ft_free_struct(env);
	perror("execve() failed");
}

void	ft_pipe(char **envp, t_env *env, char **cmd)
{
	env->bin = ft_get_path(cmd[0], envp);
	printf("pipe == %s\n", env->bin);
	dup2(env->pfd[IN], 0);
	close(env->pfd[IN]);
	dup2(env->pfd[OUT], 1);
	close(env->pfd[OUT]);
	execve(env->bin, cmd, NULL);
	ft_free_struct(env);
	perror("execve() failed");
}

void	ft_redirection(char **envp, t_env *env, char **cmd)
{
	env->bin = ft_get_path(cmd[0], envp);
	printf("redirec == %s\n", env->bin);
	close(env->pfd[OUT]);
	dup2(env->pfd[IN], 0);
	close(env->pfd[IN]);
	dup2(env->fd2, 1);
	execve(env->bin, cmd, NULL);
	ft_free_struct(env);
	perror("execve() failed");
}

void	ft_pipex(char **envp, t_env *env)
{
	int	status;
	int	i;
	t_pile	*elem;

	i = 0;
	elem = env->list;
	pipe(env->pfd);
	if (env->pfd < 0)
		perror("pipe() failed");
	while (elem->next)
	{
		env->child1 = fork();
		printf("entry\n");
		if (env->child1 < 0)
			return (perror("Fork: "));
		if (env->child1 == 0 && i == 0)
			ft_child(envp, env, elem->data);
		if (env->child1 == 0 && i > 0)
			ft_pipe(envp, env, elem->data);
		elem = elem->next;
		i++;
		close(env->pfd[0]);
		close(env->pfd[1]);
	}
	waitpid(env->child1, NULL, 0);
	env->child2 = fork();
	if (env->child2 < 0)
		return (perror("Fork: "));
	if (env->child2 == 0)
		ft_redirection(envp, env, elem->data);
	close(env->pfd[0]);
	close(env->pfd[1]);
	waitpid(env->child2, NULL, 0);
}


//int main(int argc, char **argv, char **envp)
//{
//	t_env	*env;
//
//	env = ft_memalloc(sizeof(t_env));
//	if (argc >= 5)
//	{
//		ft_parsargv(argv, &env->list, argc);
//		env->fd1 = open(argv[1], O_RDONLY);
//		env->fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
//		if (env->fd2 < 0)
//			return (-1);
//		ft_pipex(envp, env);
//	}
//	else
//		write(2, "invalid number of arguments.\n", 29);
//	if (env->bin)
//		free(env->bin);
//	ft_free_struct(env);
//	return (0);
//}
//

void	exec (char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	path = ft_get_path(args[0], env);
	execve(path, args, env);
	exit(127);
}

void	redir (char *cmd, char **env, int fdin)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT);
		if (fdin == STDIN)
			exit(1);
		else
			exec(cmd, env);
	}
}

int	openfile (char *filename, int mode)
{
	if (mode == INFILE)
	{
		if (access(filename, F_OK))
		{
			write(STDERR, "pipex: ", 7);
			write(STDERR, ": No such file or directory\n", 28);
			return (STDIN);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}

int	main (int ac, char **av, char **env)
{
	int	fdin;
	int	fdout;
	int	i;

	i = 3;
	if (ac >= 5)
	{
		fdin = openfile(av[1], INFILE);
		fdout = openfile(av[ac - 1], OUTFILE);
		dup2(fdin, STDIN);
		dup2(fdout, STDOUT);
		redir(av[2], env, fdin);
		while (i < ac - 2)
			redir(av[i++], env, 1);
		exec(av[i], env);
	}
	else
		write(STDERR, "Invalid number of arguments.\n", 29);
	return (1);
}
