/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:02:08 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/27 01:27:31 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* fonction print errror */
/* return: (int); */
int	print_error(char *str)
{
	dprintf(2, "Error: %s\n", str);
	return (1);
}

/* fonction print error entry */
/* return: (int); */
int	set_error(int error)
{
	if (error == 1)
		return (print_error("At least one wrong argument"));
	if (error == 2)
		return (print_error("Error inializing mutuex"));
	if (error == 2)
		return (print_error("Error inializing thread"));
	return (1);
}

/* fonction print the action of the philo */
/* return: (void) */
void	print_action(t_env *env, int id, int check)
{
	pthread_mutex_lock(&(env->writing));
	if (env->dieded == 0)
	{
		dprintf(1, "%lli: ", timestamps() - env->first_timestamp);
		if (check == 0)
			dprintf(1, "%d %s\n", id + 1, "\033[0;31mdied");
		if (check == 1)
			dprintf(1, "%d %s\n", id + 1, "is eating");
		if (check == 2)
			dprintf(1, "%d %s\n", id + 1, "is sleeping");
		if (check == 3)
			dprintf(1, "%d %s\n", id + 1, "is thinking");
		if (check == 4)
			dprintf(1, "%d %s\n", id + 1, "has taken a fork");
	}
	pthread_mutex_unlock(&(env->writing));
}

/* fonction if has 1 philo */
/* return (void) */
void	ft_alone(t_env *env, t_philo *philo)
{
	print_action(env, philo->id, 4);
	check_sleep(env->time_eat, env);
}
