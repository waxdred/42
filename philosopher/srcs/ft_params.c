/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:05:19 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/25 01:56:59 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_check_death(t_philo *philo, t_env *env)
{
	if (time_ms(&philo->start, &philo->end) - env->time_to_eat >= env->time_to_die)
	{
		env->died = 1;
		return (-1);
	}
	return (0);
}

void	ft_sleep(t_philo *philo, t_env *env)
{
	dprintf(1, "%llu: philo %d sleep\n", 
	time_ms(&philo->start, &philo->end) ,philo->philo_nb);
	while (time_ms(&philo->start, &philo->end) < env->time_to_sleep)
		usleep(10);
}

void	ft_eat(t_philo *philo, t_env *env)
{
	gettimeofday(&philo->reset, NULL);
	dprintf(1, "%llu: philo %d take the forks\n", 
	time_ms(&philo->start, &philo->end) ,philo->philo_nb);
	dprintf(1, "%llu: philo %d eat\n", 
	time_ms(&philo->start, &philo->end) ,philo->philo_nb);
	env->forks[philo->rfork]--;
	env->forks[philo->lfork]--;
	while (time_ms(&philo->reset, &philo->end) <= env->time_to_eat)
		usleep(10);
	env->forks[philo->rfork]++;
	env->forks[philo->lfork]++;
}

void	ft_add_forks(t_philo *philo, t_env *env, int i)
{
	int	j;

	j = 0;
	if (i == 1)
	{
		env->forks = ft_track(ft_memalloc(sizeof(int) * (env->nb_philo + 1)), env->t);
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
	if (i == 1)
		philo->rfork = env->nb_philo;
	else if (i == env->nb_philo)
		philo->rfork = 1;
	philo->lfork = i;
}
