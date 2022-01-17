#include "include/libft.h"
#include <stdio.h>
int	main(int ac, char **av)
{
	int *tab;
	char	*str;
	char **split;
	t_track *track;
	int	i;

	i = 0;
	track = ft_memalloc(sizeof(t_track));
	tab = ft_error_mal(ft_track(malloc(sizeof(int) * 8), track), track);
	printf("track->len = %d\n", track->len);
	split = ft_split("salut a a toi mon grand", ' ');
	ft_error_malt((void **)split, track);
	ft_track_tab((void **)split, track);
	printf("track->len = %d\n", track->len);
	str = ft_error_mal(ft_track(malloc(sizeof(char) * 8), track), track);
	printf("track->len = %d\n", track->len);
	while (split[i] != NULL)
	{
		tab[i] = i;
		printf("tab = %d:   split line: %s\n",tab[i], split[i]);
		i++;
	}
	ft_track_free_tab(track, (void **)split);
	printf("track->len = %d\n", track->len);
	ft_track_free(track, tab);
	printf("track->len = %d\n", track->len);
	ft_track_free(track, str);
	printf("track->len = %d\n", track->len);
	ft_track_free_all(track);
	printf("track->len after free alloc:  = %d\n", track->len);
	free(track);
	return (0);
}
