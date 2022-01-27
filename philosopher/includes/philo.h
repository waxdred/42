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
	int			died;
	int			eat_stop;
	int			*forks;
	struct s_philo  	**philo;
	pthread_t		t_philo[200];
	pthread_mutex_t		m_forks;
	pthread_mutex_t 	m_death;
	pthread_mutex_t 	m_write;
	t_track			*t;
}		t_env;

typedef struct	s_philo
{
	int			philo_nb;
	unsigned long int	limit;
	unsigned long int	last_eat;
	struct timeval 		start;
	struct timeval 		reset;
	//struct timeval 		end;
	int			lfork;
	int			rfork;
	int			eat_count;
	t_env			*env;
}		t_philo;

void 	*ft_timer(void *param);
int	ft_init(t_env * env, char **av, int ac);
void	ft_add_forks(t_philo *philo, t_env *env, int i);
unsigned long long time_ms(struct timeval *start);
int	ft_eat(t_philo *philo, t_env *env);
int	ft_sleep(t_philo *philo, t_env *env);
int	ft_check_death(t_philo *philo, t_env *env);
void	ft_mutex_fork(t_philo *philo, t_env *env, int check);
int	ft_write(t_philo *philo, t_env *env, int check);

#endif
