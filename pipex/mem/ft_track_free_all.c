/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_track_free_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:12:31 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/03 18:48:52 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_check_track(t_track *track, void *mem, int *check)
{
	*check = 0;
	if (track->len == 2)
	{
		ft_track_free_all(track);
		return (-1);
	}
	while (track->mem[*check] != mem)
		(*check)++;
	return (0);
}

void	**ft_track_free(t_track *track, void *mem)
{
	void	**dest;
	int		i;
	int		j;
	int		check;

	i = 0;
	j = 0;
	if (ft_check_track(track, mem, &check) == -1)
		return (NULL);
	dest = ft_error_mal(malloc(sizeof(void *) * (track->len - 1)), track);
	ft_bzero(dest, sizeof(dest) * (track->len - 1));
	while (track->mem[i] != NULL)
	{
		if (i != check)
			dest[j++] = track->mem[i];
		i++;
	}
	free(track->mem[check]);
	free(track->mem);
	track->mem = dest;
	track->len--;
	return (dest);
}

void	**ft_track_free_all(t_track *track)
{
	int	i;

	i = 0;
	if (track->mem == NULL)
		return (NULL);
	while (track->mem[i])
	{
		free(track->mem[i]);
		track->len--;
		i++;
	}
	free(track->mem);
	track->len--;
	track->mem = NULL;
	free(track);
	return (NULL);
}
