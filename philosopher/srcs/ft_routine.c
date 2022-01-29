/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:02:08 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/27 01:27:31 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* function when the philo eating */
/* return: (void) */
void	ft_eat(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	pthread_mutex_lock(&(env->forks[philo->l_fork]));
	print_action(env, philo->id, 4);
	pthread_mutex_lock(&(env->forks[philo->r_fork]));
	print_action(env, philo->id, 4);
	pthread_mutex_lock(&(env->meal_check));
	print_action(env, philo->id, 1);
	philo->t_last_meal = timestamps();
	pthread_mutex_unlock(&(env->meal_check));
	check_sleep(env->time_eat, env);
	(philo->x_ate)++;
	pthread_mutex_unlock(&(env->forks[philo->l_fork]));
	pthread_mutex_unlock(&(env->forks[philo->r_fork]));
}

/* function routine of all philo thread */
/* return: (void); */
void	*routine(void *args)
{
	int		i;
	t_env	*env;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)args;
	env = philo->env;
	if (philo->id % 2)
		usleep(15000);
	if (env->nb_philo == 1)
	{
		ft_alone(env, philo);
		return (NULL);
	}
	while (!(env->dieded) || env->all_ate < 1)
	{
		ft_eat(philo);
		if (env->all_ate)
			break ;
		print_action(env, philo->id, 2);
		check_sleep(env->time_sleep, env);
		print_action(env, philo->id, 3);
		i++;
	}
	return (NULL);
}

/* function run the philo with thread */
/* return: (int) */
int	run_philo(t_env *env)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = env->philo;
	env->first_timestamp = timestamps();
	while (i < env->nb_philo)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, routine, &(philo[i])))
		{
			set_error(3);
			return (1);
		}
		philo[i].t_last_meal = timestamps();
		i++;
	}
	ft_check_death(env, env->philo);
	start_exit(env, philo);
	return (0);
}

/* function for wait and destroy thread and mutuex */
/* return: (void) */
void	start_exit(t_env *env, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < env->nb_philo)
		pthread_join(philo[i].thread_id, NULL);
	i = -1;
	while (++i < env->nb_philo)
		pthread_mutex_destroy(&(env->forks[i]));
	pthread_mutex_destroy(&(env->writing));
}

/* function will check the death and end of eating */
/* return: (void) */
void	ft_check_death(t_env *e, t_philo *p)
{
	int	i;

	while (!(e->all_ate))
	{
		i = -1;
		while (++i < e->nb_philo && !(e->dieded))
		{	
			pthread_mutex_lock(&(e->meal_check));
			if (dif_time(p[i].t_last_meal, timestamps()) > e->time_death)
			{
				print_action(e, i, 0);
				e->dieded = 1;
			}
			pthread_mutex_unlock(&(e->meal_check));
			usleep(100);
		}
		if (e->dieded)
			break ;
		i = 0;
		while (e->nb_eat != -1 && i < e->nb_philo && p[i].x_ate >= e->nb_eat)
			i++;
		if (i == e->nb_philo)
			e->all_ate = 1;
	}
}
