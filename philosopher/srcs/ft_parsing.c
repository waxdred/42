
#include "../includes/philo.h"

int	ft_check_pars(char **av, int ac)
{
	int	i;

	i = 2;
	if (ft_atol(av[1]) > 200 || ft_atol(av[1]) < 1)
	{
		ft_putstr_fd("Error: entry value 1 at 200\n", 2);
		return (-1);
	}
	while (i < ac)
	{
		if (ft_atouin(av[i]) > ULONG_MAX || ft_atouin(av[i]) == 0)
		{
			ft_putstr_fd("Error: entry lowler value\n", 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_init(t_env * env, char **av, int ac)
{
	if (ft_check_pars(av, ac))
		return (-1);
	env->nb_philo = ft_atoi(av[1]);
	env->time_to_die = ft_atouin(av[2]);
	env->time_to_eat = ft_atouin(av[3]);
	env->time_to_sleep = ft_atouin(av[4]);
	if (ac == 6)
		env->nb_time_eat = ft_atouin(av[5]);
	else
		env->nb_time_eat = -1;
	return (0);
}
