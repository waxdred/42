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

#define IN 0
#define OUT 1
# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1


typedef struct	s_pile
{
	char 		**data;
	struct s_pile	*next;
}		t_pile;

typedef struct	s_env
{
	t_pile	*list;
	int	fd1;
	int	fd2;
	int	pfd[2];
	pid_t	child1;
	pid_t	child2;
	int	end[2];
	char	**cmd1;
	char	**cmd2;
	char	*bin;
}		t_env;

void	ft_add_back(t_pile **alst, t_pile *ne);
t_pile	*ft_create_elem(char **data);
void	ft_clear_stack(t_pile **stack);
char	*ft_get_path(char *cmd, char **env);
int ft_parsargv(char **argv, t_pile **list, int argc);
t_pile	*ft_last(t_pile *lst);

#endif
