/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:26:53 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/22 18:26:53 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DEFINE_H
# define DEFINE_H
# define ESC 53
# define R 15
# define LEFT 123
# define RIGHT 124
# define UNZOOM 78
# define ZOOM 69
# define UP 126
# define DOWN 125
# define CUBE 50
# define MULT 2.3

# define Z1PL (fdf->map.map[fdf->map.y][fdf->map.x])
# define Z2PL (fdf->map.map[fdf->map.y][fdf->map.x + 1])

# define Z1PC (fdf->map.map[fdf->map.y][fdf->map.x])
# define Z2PC (fdf->map.map[fdf->map.y + 1][fdf->map.x])

# define Z1IL (fdf->map.map[fdf->map.y][fdf->map.x])
# define Z2IL (fdf->map.map[fdf->map.y][fdf->map.x + 1])

# define Z1IC (fdf->map.map[fdf->map.y][fdf->map.x])
# define Z2IC (fdf->map.map[fdf->map.y + 1][fdf->map.x])
#endif
