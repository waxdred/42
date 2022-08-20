/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:35:24 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/19 23:23:41 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

# include "define.h"

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_col
{
	long	xo;
	long	yo;
	long	ipx;
	long	ipy;
	long	ipx_add_xo;
	long	ipy_add_yo;
	long	ipp_add_xo;
	long	ipp_add_yo;
	long	ipx_sub_xo;
	long	ipy_sub_yo;
	long	r_col;
	long	l_col;
	long	u_col;
	long	d_col;
	double	oa;
}		t_col;

typedef struct s_mouse
{
	t_pos	pos;
	t_pos	last_pos;
	int		button[6];
}		t_mouse;

typedef enum e_dir
{
	EA = 0,
	NO,
	WE,
	SO,
	DO
}	t_dir;

typedef struct s_draw
{
	int	ex;
	int	ey;
	int	dx;
	int	dy;
	int	d_x;
	int	d_y;
	int	i;
	int	x_incr;
	int	y_incr;
	int	x_rect;
	int	y_rect;
}		t_draw;

typedef struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	color;
}		t_line;

typedef union u_color
{
	unsigned int	i;
	unsigned char	str[4];
}	t_color;

typedef struct s_rgb
{
	float	r;
	float	g;
	float	b;
	t_color	*rgb_bright;
}		t_rgb;

typedef struct s_activ
{
	int8_t	press;
	int8_t	active;
}		t_activ;

typedef struct s_player
{
	t_pos	pos;
	double	dp_x;
	double	dp_y;
	double	pa;
	double	speed;
	double	scale;
}	t_player;

typedef struct s_ray
{
	double	tans;
	double	ca;
	double	dis_h;
	double	dis_hn;
	double	dis_t;
	double	dis_v;
	double	dis_vn;
	double	hx;
	double	hy;
	double	ntans;
	double	ra;
	double	rx;
	double	ry;
	double	vx;
	double	vy;
	double	xo;
	double	yo;
	t_pos	ra_base;
	long	dof;
	long	mx;
	long	my;
	long	mp;
	long	vmp;
	long	hmp;
	long	last_mp;
	long	last_pos;
	long	last_dir;
	long	new_dir;
	long	r;
	long	side;
	long	up;
	long	down;
	long	right;
	long	left;
	long	m_pos;
	int8_t	h_door;
	int8_t	v_door;
	int8_t	door;
}		t_ray;

typedef struct s_wall
{
	int8_t			door;
	t_dir			dir;
	t_pos			origin;
	double			width_img;
	double			inter_dist;
	double			col1_x;
	double			col1_y;
	t_pos			l_extrem;
	double			l_dist;
	double			l_heigth;
	double			l_angle;
	t_pos			r_extrem;
	double			r_dist;
	double			r_heigth;
	double			r_angle;
	double			heigth_max;
	size_t			start;
	size_t			end;
	struct s_wall	*next;
}	t_wall;

typedef struct s_texture
{
	int		x_xpm;
	int		y_xpm;
	void	*img;
	t_color	*map;
	t_color	**tab;
	int		bpp;
	int		size_line;
	int		endian;
	char	*file;
}	t_texture;

typedef struct s_surface
{
	t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;
	t_texture	door;
	t_color		floor;
	t_color		ceiling;
}	t_surface;

typedef struct s_inter
{
	int8_t	key[KEY];
	int8_t	door;
	t_mouse	mouse;
	t_activ	activ_map;
	t_activ	activ_door;
	t_activ	activ_debeug;
	t_activ	active_wall[2];
}		t_inter;

typedef struct s_cub
{
	char		**map;
	char		*s_map;
	t_inter		inter;
	int8_t		check_parsing;
	size_t		x_map;
	size_t		y_map;
	size_t		r_dist;
	t_line		line;
	t_player	player;
	t_pos		mousse;
	t_surface	surface;
	t_texture	bg;
	t_texture	display;
	t_texture	mini_map;
	t_texture	player_mini_map;
	float		scale;
	t_track		*track;
	t_wall		*walls;
	void		*p_mlx;
	void		*p_win;
}	t_cub;

typedef struct s_draw_wall
{
	t_color	**display;
	size_t	y;
	size_t	x;
	size_t	x0;
	size_t	y0;
	size_t	x1;
	size_t	y1;
	double	ratio_x;
	double	*ratio;
	t_wall	*wall;
}	t_draw_wall;

#endif
