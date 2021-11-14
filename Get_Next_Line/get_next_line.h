/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:28:22 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/14 23:13:28 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE  3
# endif
char	*get_next_line(int fd);
int	ft_strichr(char *s, int c);
size_t	ft_strlen(char *s1);
void	*ft_memalloc(size_t size);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_bzero(void *b, size_t n);
char	*ft_strncat(char *dest, char *src, int size);
#endif
