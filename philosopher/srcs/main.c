/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:02:08 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/27 01:27:31 by jmilhas          ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	int		ret;
	t_env	env;

	if (ac != 5 && ac != 6)
		return (print_error("Wrong amount of arguments"));
	ret = init_env(&env, av);
	if (ret)
		return (set_error(ret));
	if (run_philo(&env))
		return (print_error("Error: Threads wasn't create'"));
	return (0);
}
