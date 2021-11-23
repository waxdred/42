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
	int	x;
	int	y;
	int	posx;
	int	posy;
	int	nbcol;
	int	nblin;
	int	max;
	int	pad;
}		t_map;

typedef struct	s_color
{
	int	color;
	int	red;
	int	green;
	int	blue;
}		t_color;

typedef struct	s_point
{
	int	spc;
	int	pos;
}		t_point;

typedef struct	s_mov
{
	double	y;
	double	x;
	double	tmp_y;
	double	tmp_x;
	double	s_y;
	double	s_x;
}		t_mov;

typedef struct	s_env
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	win_length;
	int	win_width;
	struct s_map	map;
	struct s_mov	mov;
	struct s_point point;
	struct s_color	color;
}		t_env;
#endif
