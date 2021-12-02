/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:40:42 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/20 00:40:42 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

typedef struct	s_map
{
	int	**map;
	int	max;
	int	nbcol;
	int	nblin;
	int	pad;
	int	posx;
	int	posy;
	int	x;
	int	y;
}		t_map;

typedef struct	s_point
{
	float	x_step;
	float	y_step;
	int	max;
	int	pos;
	int	spc;
	int	x;
	int	y;
	float	B_x;
	float	B_y;
	float	B_x1;
	float	B_y1;
	int	z1;
	int	z;
}		t_point;

typedef struct	s_mov
{
	double	s_x;
	double	s_y;
	double	x;
	double	y;
	float	angle;
	int	up;
}		t_mov;

typedef struct	s_env
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	color;
	int	proj;
	int	win_length;
	int	win_width;
	int	menu;
	struct	s_map	map;
	struct	s_mov	mov;
	struct	s_point p;
}		t_env;
#endif
