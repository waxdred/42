/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:02:08 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/27 01:27:31 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* function conv str to int */
/* return: (int) */
int	ft_atoi(const char *str)
{
	long int	n;
	int			sign;

	n = 0;
	sign = 1;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '-')
		return (-1);
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			n = n * 10 + (*str++ - '0');
		else
			return (-1);
	}
	return ((int)(n * sign));
}

/* fonction return time - time end */
/* return: (long long) */
long long	dif_time(long long time_start, long long time_end)
{
	return (time_end - time_start);
}

/* fonction get time from gettimeofday */
/* return (long long); */
long long	timestamps(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

/* fonctipn check time of sleep and death */
/* return: (void) */
void	check_sleep(long long time, t_env *env)
{
	long long	i;

	i = timestamps();
	while (!(env->dieded) || !(env->all_ate))
	{
		if (dif_time(i, timestamps()) >= time)
			break ;
		usleep(50);
	}
}
