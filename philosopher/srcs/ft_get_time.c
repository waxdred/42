/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:00:59 by jmilhas           #+#    #+#             */
/*   Updated: 2022/01/24 18:00:59 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long long time_ms(struct timeval *start)
{
	struct timeval end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec - start->tv_sec) * 1000 + (end.tv_usec - start->tv_usec) / 1000);
}
