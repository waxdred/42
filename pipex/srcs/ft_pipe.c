/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:01:45 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/09 17:08:57 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
