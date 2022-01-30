/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:02:08 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/27 01:27:31 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* fonction init mutex for lock the thread */
/* return: (int) */
int	init_mutex(t_env *env)
{
	int	i;

	i = env->nb_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(env->forks[i]), NULL))
		{
			set_error(2);
			return (1);
		}
	}
	if (pthread_mutex_init(&(env->writing), NULL))
	{
		set_error(2);
		return (1);
	}
	if (pthread_mutex_init(&(env->meal_check), NULL))
	{
		set_error(2);
		return (1);
	}
	return (0);
}

/* function set all var for the philo */
/* return: (int) */
int	init_philo(t_env *env)
{
	int	i;

	i = env->nb_philo;
	while (--i >= 0)
	{
		env->philo[i].id = i;
		env->philo[i].x_ate = 0;
		env->philo[i].l_fork = i;
		env->philo[i].r_fork = (i + 1) % env->nb_philo;
		env->philo[i].t_last_meal = 0;
		env->philo[i].env = env;
	}
	return (0);
}

/* fonction init env with args */
/* return: (int) */
int	init_env(t_env *env, char **av)
{
	env->nb_philo = ft_atoi(av[1]);
	env->time_death = ft_atoi(av[2]);
	env->time_eat = ft_atoi(av[3]);
	env->time_sleep = ft_atoi(av[4]);
	env->all_ate = 0;
	env->dieded = 0;
	if (env->nb_philo < 1 || env->time_death < 0 || env->time_eat < 0
		|| env->time_sleep < 0 || env->nb_philo > 250)
		return (1);
	if (av[5])
	{
		env->nb_eat = (ft_atoi(av[5]) - 1);
		if (env->nb_eat < 0)
			return (1);
	}
	else
		env->nb_eat = -1;
	if (init_mutex(env))
		return (2);
	init_philo(env);
	return (0);
}
