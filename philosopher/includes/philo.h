/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:02:08 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/27 01:27:31 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include <string.h>

struct	s_philo;

typedef struct s_philo
{
	int					id;
	int					x_ate;
	int					l_fork;
	int					r_fork;
	long long			t_last_meal;
	struct s_env		*env;
	pthread_t			thread_id;
}		t_philo;

typedef struct s_env
{
	int					nb_philo;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	int					dieded;
	int					all_ate;
	long long			first_timestamp;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		forks[250];
	pthread_mutex_t		writing;
	t_philo				philo[250];
}		t_env;

/* fonction in utils.c */
int			ft_atoi(const char *str);
long long	dif_time(long long time_start, long long time_end);
long long	timestamps(void);
void		check_sleep(long long time, t_env *env);

/* fonction in thread.c */
int			init_mutex(t_env *env);
int			init_env(t_env *env, char **av);
int			init_philo(t_env *env);

/* fonction in ft_print.c */
int			print_error(char *str);
int			set_error(int error);
void		print_action(t_env *env, int id, int check);
void		ft_alone(t_env *env, t_philo *philo);

/* fonction in ft_routine.c */
int			run_philo(t_env *env);
void		*routine(void *args);
void		ft_check_death(t_env *e, t_philo *p);
void		ft_eat(t_philo *philo);
void		start_exit(t_env *env, t_philo *philo);
#endif
