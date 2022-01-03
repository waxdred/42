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

char	*ft_add_path(char *str)
{
	int	i;
	int	len;
	char	*full_path;
	char	*path;

	i = 0;
	len = ft_strlen(str) + ft_strlen(path) + 1;
	path = "/bin/";
	full_path = (char *)malloc(sizeof(char) * len);
	if (!full_path)
		return (NULL);
	while (*path)
		full_path[i++] = *path++;
	while (*str)
		full_path[i++] = *str++;
	full_path[i] = '\0';
	return (full_path);
}

void	child_one(int f1, char **cmd1, char **env)
{
	char	*bin;

	bin  = ft_get_path(cmd1[0], env);
	execve(bin, cmd1, NULL);
	perror("execve() failed");
}

void	child_two(int f2, char **cmd2, char **env)
{
	char	*bin;

	bin = ft_get_path(cmd2[0], env);
	dup2(f2, STDOUT_FILENO);
	execve(bin, cmd2, NULL);
	perror("execve() failed");
}

void	pipex(int f1,  int f2, char **cmd1, char **cmd2, char **env)
{
	int	end[2];
	int	status;
	pid_t	child1;
	pid_t	child2;

	pipe(end);
	child1 = fork();
	if (child1 < 0)
		return (perror("Fork: "));
	if (child1 == 0)
		child_one(f1, cmd1, env);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork: "));
	if (child2 == 0)
		child_two(f2, cmd2, env);
	close(end[0]);
	close(end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

int main(int argc, char **argv, char **env)
{
	int	fd1;
	int	fd2;
	if (argc == 5)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd1 < 0 || fd2 < 0)
			return (-1);
		pipex(fd1, fd2, ft_split(argv[2], ' '), ft_split(argv[3], ' '), env);
	}
	else
		write(2, "invalid number of arguments.\n", 29);
	return (0);
}
