#include "../includes/philo.h"

void	*try(void* param)
{
	int	i;
	t_philo	*philo;

	i = 0;
	philo = param;
	while (i < 500)
	{
		usleep(100);
		printf("thread nb %d and need to eat %d\n",philo->philo_nb, 
				philo->env->nb_time_eat);
		i++;
	}
	return (0);
}

void	ft_allocation_thread(t_env *env, t_track *t)
{
	long	i;

	i = 0;
	ft_track(env->forks = ft_memalloc(sizeof(pthread_mutex_t) 
			* (env->nb_philo + 1)), t);
	env->philo = ft_memalloc(sizeof(t_philo) * (env->nb_philo + 1));
	while (i < env->nb_philo)
	{
		env->philo[i] = malloc(sizeof(t_philo));
		env->philo[i]->env = env; 
		env->philo[i]->philo_nb = i;
		pthread_create(&env->t_philo[i], NULL, try, (void *)env->philo[i]);
		i++;
	}
	pthread_create(&env->t_philo[i], NULL, ft_timer, (void *)env);
	ft_track_tab((void **)env->philo, t);
}

int	ft_pilo(t_env *env, char **av, int ac)
{
	long	i;

	i = 1;
	if (ft_init(env, av, ac))
		return (-1);
	ft_allocation_thread(env, env->t);
	ft_putstr_fd("ok\n", 2);
	i = 0;
	while (i <= env->nb_philo)
	{
		pthread_join(env->t_philo[i], NULL);
		i++;
	}
	return(0);
}

int	main(int ac, char **av)
{
	t_env	*env;

	env = ft_memalloc(sizeof(t_env));
	if (!env)
		return (-1);
	env->t = ft_memalloc(sizeof(t_track));
	if (ac == 5 || ac == 6)
	{
		if(ft_pilo(env, av, ac))
		{
			free(env->t);
			free(env);
			return (-1);
		}
		ft_track_free_all(env->t);
	}
	else
		write(2, "invalide argument:\n", 17);
	free(env);
	return (0);
}
