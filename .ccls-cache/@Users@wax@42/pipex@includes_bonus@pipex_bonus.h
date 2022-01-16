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
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  3
# endif
# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_env
{
	char	**cmd;
	char	**error;
	char	*bin;
	char	*fn;
	char	*limiter;
	int		count;
	int		argc;
	int		bin_check;
	int		fdin;
	int		fdout;
	int		save_fdin;
	int		save_fdout;
	int		here_doc;
	int		error_pipe;
	int		pfd[2];
	int		pipefd[2];
	pid_t	*pid;
}		t_env;

char	*ft_get_line(char **line, char **s_buff);
char	*ft_get_path(char *cmd, char **env, t_env *envp);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strncat(char *dest, char *src, int size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
int		ft_read(int fd, char **buffer, char **s_buff, char **line);
void	ft_args_check(char **av, t_env *env);
void	ft_exec_cmd(char **envp, t_env *env, int check);
void	ft_free_split(t_env *env);
void	ft_get_errors(char *cmd, t_env *env);
void	ft_here_doc(t_env *env, char **av, int ac, char **envp);
void	ft_pipex(t_env *env, int ac, char **av, char **envp);
void	ft_print_error(int error, char **av, t_env *env);
void	ft_redir(char *cmd, char **envp, t_env *env, int count);
void	ft_get_cmd(char *cmd, char **envp, t_env *env);
void	*ft_error_malloc(void	*mem, t_env *env);
int		ft_check_empty_string(char *cmd);
int		ft_check_empty(char **av, int ac, int st);
#endif
