#include "../includes/philo.h"

float	time_diff(struct timeval *start, struct timeval *end)
{
	return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

float	time_ms(struct timeval *start, struct timeval *end)
{
	return (end->tv_usec - start->tv_usec);
}

void	*ft_timer(void	*param)
{
	int		i;
	t_env		*env;
	struct timeval 	start;
	struct timeval 	end;

	i = 0;
	env = param;
	gettimeofday(&start, NULL);
	while(1)
	{
		usleep(1000);
		gettimeofday(&end, NULL);
		if (time_diff(&start, &end) >= env->time_to_die / 1000)
			return (NULL);
		printf("mms: %0.8f\n", time_diff(&start, &end));
	}
	return (NULL);
}
