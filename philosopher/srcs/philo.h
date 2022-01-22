#ifndef 	PHILO_H
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include "../libft/include/libft.h"

typedef struct s_env
{
	
	float 		time_mms;
	int		stop;
	pthread_t	t_philo[200];
}		t_env;

void *ft_timer(void *param);

#endif
