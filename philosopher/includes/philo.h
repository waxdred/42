#ifndef 	PHILO_H
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>


#include "../libft/include/libft.h"

struct s_philo;
typedef struct s_env
{
	unsigned long int	time_to_die;	
	unsigned long int	time_to_eat;
	unsigned long int	time_to_sleep;

	int			nb_philo;
	int			nb_time_eat;
	struct s_philo  	**philo;
	pthread_t		t_philo[200];
	pthread_mutex_t		*forks;
	pthread_mutex_t 	death;
	t_track			*t;
}		t_env;

typedef struct	s_philo
{
	int			philo_nb;
	unsigned long int	limit;
	unsigned long int	last_eat;
	int			lfork;
	int			rfork;
	int			eat_count;
	t_env			*env;
}		t_philo;

void 	*ft_timer(void *param);
int	ft_init(t_env * env, char **av, int ac);

#endif
