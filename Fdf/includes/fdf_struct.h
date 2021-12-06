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

typedef struct s_map
{
	int	**map;
	int	dhigh;
	int	high;
	int	max;
	int	nbcol;
	int	nblin;
	int	pad;
	int	posx;
	int	posy;
	int	x;
	int	y;
}		t_map;

typedef struct s_point
{
	float	b_x1;
	float	b_x;
	float	b_y1;
	float	b_y;
	float	x_step;
	float	y_step;
	int		max;
	int		pos;
	int		spc;
	int		x;
	int		y;
	int		z1;
	int		z;
	int		zoom;
}		t_point;

typedef struct s_color
{
	float	coef;
	int		end;
	int		start;
}		t_color;

typedef struct s_mov
{
	double	s_x;
	double	s_y;
	double	x;
	double	y;
	float	angle;
	int		up;
}		t_mov;

typedef struct s_env
{
	char	*name;
	int		color;
	int		color_on;
	int		i;
	int		j;
	int		menu;
	int		proj;
	int		win_length;
	int		win_width;
	t_map	map;
	t_mov	mov;
	t_point	p;
	t_color	colors;
	void	*mlx_ptr;
	void	*win_ptr;
}		t_env;
#endif
