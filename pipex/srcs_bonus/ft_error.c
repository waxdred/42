/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:37:50 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/04 22:37:50 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

void	ft_print_error(t_env *env)
{
	int	i;

	i = 0;
	while (env->error[i])
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(env->error[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
}

void	ft_get_errors(char *cmd, t_env *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!env->error)
		env->error = (char **)ft_memalloc(sizeof(char *) * env->argc);
	if (!env->error)
		return ;
	while (env->error[i])
		i++;
	env->error[i] = (char *)ft_memalloc(sizeof(char) * ft_strlen(cmd) + 1);
	if (env->error[i])
	{
		ft_freetab(env->error);
		return ;
	}
	while (*cmd)
		env->error[i][j++] = *cmd++;
}
