/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:38:07 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/04 22:38:07 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../libft/include/libft.h"
# include "../Gnl/includes/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct	s_env
{
	int	pfd[2];
	int	pipefd[2];
	int	fdin;
	int	fdout;
	int	here_doc;
	pid_t	pid;
	char	*bin;
	char	*limiter;
	char	**cmd;
}		t_env;

char	*ft_get_path(char *cmd, char **env);
void	ft_free_split(t_env *env);
void	ft_args_check(char **av, t_env *env);
void	ft_pipex(t_env *env, int ac, char **av, char **envp);
void	ft_here_doc(t_env *env, char **av, int ac, char **envp);
void	ft_redir(char *cmd, char **envp, t_env *env);
void	ft_exec(char *cmd, char **envp, t_env *env);
#endif
