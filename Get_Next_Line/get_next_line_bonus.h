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

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# include <limits.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE  3
# endif
char	*get_next_line(int fd);
char	*ft_strncat(char *dest, char *src, int size);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_read(int fd, char **buffer, char **s_buff, char **line);
char	*ft_get_line(char **line, char **s_buff);
#endif
