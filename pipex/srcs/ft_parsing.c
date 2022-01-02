

#include "../includes/pipex.h"

char	*ft_get_path(char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int	i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env)
		return (cmd);
	path = ft_strdup(env[i] + 5);
	while(path && ft_strchr(path, ':') > -1)
	printf("dir %s\n", dir);
	return (cmd);
}
