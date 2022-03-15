#include "include/libft.h"

int	main(int ac, char **av)
{
	t_track *t;
	char	*str;
	int	*nb;
	char	**tab;
	t = ft_memalloc(sizeof(t_track));
	/* ajout un * */ 
	str = ft_track(ft_strdup("salut"), &(t));
	nb = ft_track((int *)ft_memalloc(sizeof(int) * 10), &(t));

	/* attention ajouté les ** aprés entre complement alloé */
	tab = ft_split("salut a toi", ' ');
	ft_track_tab((void **)tab, &(t));
	

	/* fonction de free */
	/* free * */
	ft_track_free(&(t), str);
	ft_track_free_tab(&(t), (void **)tab);

	/* fonction free tous kles pointer plus le pointer du tracker */
	ft_track_free_all(&(t));

	return(0);
}
