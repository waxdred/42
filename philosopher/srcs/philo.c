/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:02:08 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/25 01:53:37 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void* param)
{
	t_env	*env;
	t_philo	*philo;

	philo = (t_philo *)param;
	env = (t_env *)philo->env;
	while (1)
	{
		pthread_mutex_lock(&env->m_death);
		ft_check_death(philo, env);
		if (env->died == 1 || env->eat_stop == 1)
		{
			pthread_mutex_unlock(&env->m_death);
			return (0);
		}
		pthread_mutex_unlock(&env->m_death);
		if (env->forks[philo->rfork] == 1 && env->forks[philo->rfork] == 1)
		{
			ft_mutex_fork(philo, env, 0);
			if (ft_eat(philo, env) == -1)
				return (0);
			ft_mutex_fork(philo, env, 1);
			if (ft_sleep(philo, env) == -1)
				return (0);
		}
		usleep(10);
	}
	return (0);
}

void	ft_allocation_thread(t_env *env, t_track *t)
{
	long	i;

	i = 1;
	env->forks = ft_track(ft_memalloc(sizeof(pthread_mutex_t) 
			* (env->nb_philo + 1)), t);
	env->philo = ft_memalloc(sizeof(t_philo) * (env->nb_philo + 1));
	pthread_mutex_init(&env->m_forks, NULL);
	pthread_mutex_init(&env->m_death, NULL);
	pthread_mutex_init(&env->m_write, NULL);
	while (i <= env->nb_philo)
	{
		env->philo[i] = ft_track(malloc(sizeof(t_philo)), t);
		env->philo[i]->env = env; 
		env->philo[i]->philo_nb = i;
		ft_add_forks(env->philo[i], env, i);
		gettimeofday(&env->philo[i]->start, NULL);
		env->philo[i]->reset = env->philo[i]->start;
		pthread_create(&env->t_philo[i], NULL, routine, (void *)env->philo[i]);
		usleep(1000);
		i++;
	}
	ft_track_tab((void **)env->philo, t);
}

int	ft_pilo(t_env *env, char **av, int ac)
{
	long	i;

	i = 1;
	if (ft_init(env, av, ac))
		return (-1);
	ft_allocation_thread(env, env->t);
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
		pthread_mutex_destroy(&env->m_forks);
		pthread_mutex_destroy(&env->m_death);
		pthread_mutex_destroy(&env->m_write);
		ft_track_free_all(env->t);
	}
	else
		write(2, "invalide argument:\n", 17);
	free(env);
	return (0);
}
