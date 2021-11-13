/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:28:22 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/07 18:28:22 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <fcntl.h>
#include <stdio.h>
#include "libft/libft.h"
# define BUFFER_SIZE  10
char	*get_next_line(int *fd);
char	*ft_strldup(char *str, int len);
int	ft_strichr(char *s, int c);
char	*ft_stredup(char *str, int index);
void	ft_free(char *ptr);

#endif
