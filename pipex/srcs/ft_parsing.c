/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:01:13 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/09 15:36:46 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_split(t_env *env)
{	
	if (env->cmd)
		ft_freetab(env->cmd);
	if (env->bin_check == 0)
		free(env->bin);
}

int	ft_check_parsing(char *av, t_env *env)
{
	if (av[0] == '\0')
	{
		dup2(env->save_fdout, STDOUT);
		ft_putstr_fd("empty command:\n", 1);
		dup2(env->fdout, STDOUT);
		return (-1);
	}
	return (0);
}

char	*ft_cat_path(char *dir, char *cmd)
{
	char	*bin;
	int		len;
	int		full_len;

	len = ft_strlen(dir);
	full_len = len + ft_strlen(cmd) + 2;
	bin = (char *)malloc(sizeof(char) * full_len);
	if (!bin)
		return (NULL);
	ft_memcpy(bin, dir, len);
	bin[len] = '/';
	len++;
	while (len < full_len)
		bin[len++] = *cmd++;
	bin[len] = '\0';
	return (bin);
}

char	*ft_get_shell(char **env)
{
	char	*shell;
	int		i;

	i = 0;
	while (env[i])
		i++;
	if (i == 38)
		shell = ft_strdup("bash: ");
	else
		shell = ft_strdup("zsh: ");
	if (!shell)
		return (NULL);
	return (shell);
}

char	*ft_get_path(char *cmd, char **env, t_env *envp)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	envp->shell = ft_get_shell(env);
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env)
		return (cmd);
	path = ft_strdup(env[i] + 5);
	while (path && ft_strichr(path, ':') > -1)
	{
		dir = ft_strndup(path, ft_strichr(path, ':'));
		bin = ft_cat_path(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strichr(path, ':') + 1;
	}
	return (cmd);
}
