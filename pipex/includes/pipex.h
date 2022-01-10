/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:23:20 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/09 17:10:14 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
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

typedef struct s_env
{
	char	**cmd;
	char	*bin;
	char	*shell;
	char	*fn;
	char	*limiter;
	int		bin_check;
	int		save_fdin;
	int		save_fdout;
	int		fdin;
	int		fdout;
	int		save_fdin;
	int		save_fdout;
	int		here_doc;
	int		pfd[2];
	int		pipefd[2];
	pid_t	pid;
}		t_env;

char	*ft_get_path(char *cmd, char **env, t_env *envp);
char	*ft_get_pipe(t_env *env, char *cmd);
void	ft_free_split(t_env *env);
<<<<<<< HEAD
int		ft_check_parsing(char *av, t_env *env);
=======
char	*ft_loop_pipe(t_env *env);

>>>>>>> 23546124416ddbcd391e1cb2673b331cf2900ecd

#endif
