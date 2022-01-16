/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:23:20 by jmilhas           #+#    #+#             */
/*   Updated: 2021/12/16 19:23:20 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/include/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_env
{
	char	**cmd;
	char	*bin;
	char	*fn;
	char	*limiter;
	int		bin_check;
	int		check_sleep;
	int		fdin;
	int		fdout;
	int		save_fdin;
	int		save_fdout;
	int		here_doc;
	int		pfd[2];
	int		pipefd[2];
	pid_t	pid[2];
	pid_t	pid_sleep;
}		t_env;

char	*ft_get_path(char *cmd, char **env, t_env *envp);
char	*ft_loop_pipe(t_env *env);
int		ft_check_empty(char **av, int ac);
int		ft_check_empty_string(char *cmd);
void	ft_exec_cmd(char **envp, t_env *env, int check);
void	ft_free_split(t_env *env);
void	ft_get_cmd(char *cmd, char **envp, t_env *env);

#endif
