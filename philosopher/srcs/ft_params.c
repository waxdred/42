/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:05:19 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/27 01:11:11 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_check_death(t_philo *philo, t_env *env)
{
	if (env->eat_stop == 0 && env->died == 0)
	{
		if (time_ms(&philo->reset) >= env->time_to_die)
		{
			env->died = 1;
			pthread_mutex_lock(&env->m_write);
			dprintf(1, "%llu: philo %d dead\n", 
			time_ms(&philo->start) ,philo->philo_nb);
			pthread_mutex_unlock(&env->m_write);
			pthread_mutex_unlock(&env->m_death);
			return (-1);
		}
		if (philo->eat_count >= env->nb_time_eat && 
			env->nb_time_eat != -1)
		{
			env->eat_stop = 1;
			pthread_mutex_lock(&env->m_write);
			dprintf(1, "%llu: philo %d finish to eat\n", 
			time_ms(&philo->start) ,philo->philo_nb);
			pthread_mutex_unlock(&env->m_write);
			pthread_mutex_unlock(&env->m_death);
			return (-1);
		}
	}
	return (0);
}

int	ft_sleep(t_philo *philo, t_env *env)
{
	struct timeval		sleep;

	gettimeofday(&sleep, NULL);
	usleep(10);
	pthread_mutex_lock(&env->m_write);
	if (ft_write(philo, env, 1) == -1)
	{
		pthread_mutex_unlock(&env->m_write);
		return (-1);
	}
	pthread_mutex_unlock(&env->m_write);
	while (time_ms(&sleep) < env->time_to_sleep)
		usleep(env->time_to_sleep);
	pthread_mutex_lock(&env->m_write);
	ft_write(philo, env, 1);
	pthread_mutex_unlock(&env->m_write);
	return (0);
}

int	ft_write(t_philo *philo, t_env *env, int check)
{
	pthread_mutex_lock(&env->m_death);
	if (env->died == 1 || env->eat_stop == 1)
	{
		pthread_mutex_unlock(&env->m_death);
		return (-1);
	}
	if (check == 0)
	{
		dprintf(1, "%llu: philo %d take the forks\n", 
		time_ms(&philo->start) ,philo->philo_nb);
		dprintf(1, "%llu: philo %d eat\n", 
		time_ms(&philo->start) ,philo->philo_nb);
	}
	else if (check == 1)
	{
		dprintf(1, "%llu: philo %d sleep\n", 
		time_ms(&philo->start) ,philo->philo_nb);
	}
	else if (check == 2)
	{
		dprintf(1, "%llu: philo %d think\n", 
		time_ms(&philo->start) ,philo->philo_nb);
	}
	pthread_mutex_unlock(&env->m_death);
	return (0);
}

void	ft_mutex_fork(t_philo *philo, t_env *env, int check)
{
	if (check == 0)
	{
		pthread_mutex_lock(&env->m_forks);
		env->forks[philo->rfork]--;
		env->forks[philo->lfork]--;
		pthread_mutex_unlock(&env->m_forks);
	}
	if (check == 1)
	{
		pthread_mutex_lock(&env->m_forks);
		env->forks[philo->rfork]++;
		env->forks[philo->lfork]++;
		pthread_mutex_unlock(&env->m_forks);
	}

}

int	ft_eat(t_philo *philo, t_env *env)
{
	gettimeofday(&philo->reset, NULL);
	pthread_mutex_lock(&env->m_write);
	if (ft_write(philo, env, 0) == -1)
	{
		pthread_mutex_unlock(&env->m_write);
		return (-1);
	}
	pthread_mutex_unlock(&env->m_write);
	if (env->nb_time_eat != -1)
		philo->eat_count++;
	while (time_ms(&philo->reset) <= env->time_to_eat)
		usleep(10);
	return (0);
}

void	ft_add_forks(t_philo *philo, t_env *env, int i)
{
	int	j;

	j = 0;
	if (i == 1)
	{
		env->forks = ft_track(ft_memalloc(sizeof(int)
			* (env->nb_philo + 1)), env->t);
		while (j <= env->nb_philo)
			env->forks[j++] = 1;
		philo->rfork = philo->philo_nb;
		philo->lfork = i;
	}
	if (env->nb_philo < 2)
	{
		philo->rfork = -1;
		philo->lfork = i;
		return ;
	}
	else
	{
		philo->rfork = i - 1;
		philo->lfork = i;
	}
}
