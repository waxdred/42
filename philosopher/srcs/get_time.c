#include "philo.h"
float	time_diff(struct timeval *start, struct timeval *end)
{
	return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

void 	*ft_timer(void *param)
{
	t_env *env = param;
	struct timeval	start;
	struct timeval	end;
	gettimeofday(&start, DST_NONE);
	int 	i;

	i = 0;
	while (env->stop)
	{
		usleep(765);
		gettimeofday(&end, DST_NONE);
		printf("mms: %0.8f\n", time_diff(&start, &end));
		i++;
		if (i == 10000000)
			env->stop = 0;
	}
}
