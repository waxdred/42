/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:01:16 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/24 18:02:05 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int mails = 0;
pthread_mutex_t mutex;

void	*routine(void *param)
{
	int	i;

	i = 0;
	t_env *env = param;
	while (i < 100000000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
		i++;
	}
	env->stop = 0;
	return(NULL) ;
}

int	main(int ac, char **av)
{
	pthread_t p1, p2, p3;
	t_env *env;

	env = malloc(sizeof(t_env));
	env->stop = 1;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&p1, NULL, &routine, (void *)env) != 0)
		return (1);
	if (pthread_create(&p2, NULL, &routine, (void *)env) != 0)
		return (2);
	if (pthread_create(&p3, NULL, &ft_timer, (void *) env) != 0)
		return (3);
	if (pthread_join(p1, NULL))
		return (4);
	if (pthread_join(p2, NULL))
		return (5);
	if (pthread_join(p3, NULL))
		return (6);
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
	return (0);
}
