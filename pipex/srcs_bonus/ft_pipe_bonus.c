/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:01:45 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/09 17:22:25 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

char	*ft_get_pipe(t_env *env, char *cmd)
{
	dup2(env->save_fdout, STDOUT);
	dup2(env->save_fdin, STDIN);
	ft_putstr_fd("Pipe> ", 1);
	cmd = get_next_line(0);
	dup2(env->fdout, STDOUT);
	dup2(env->fdin, STDIN);
	cmd[ft_strlen(cmd) - 1] = '\0';
	return (cmd);
}
