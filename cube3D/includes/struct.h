
#ifndef STRUCT_H
#define STRUCT_H
#include "includes.h"

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int	wd_width;
	int	wd_height;
}		t_mlx;

typedef struct s_map
{
	int	mapX;
	int	mapY;
}		t_map;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	dp_x;
	float	dp_y;
	float	pa;
	float	speed;
	float	scale;
}		t_player;

typedef struct s_ray
{
	int	r;
	int	mx;
	int	my;
	int	mp;
	int	dof;
	int	side;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	float	Tan;
	float	nTan;
	float	disH;
	float	disV;
	float	disHn;
	float	disVn;
	float	disT;
	float	hx;
	float	hy;
	float	vx;
	float	vy;
	int	lineH;
	int	lineO;
	float	ca;
}		t_ray;

typedef struct s_draw
{
	int	ex;
	int	ey;
	int	dx;
	int	dy;
	int	Dx;
	int	Dy;
	int	i;
	int	Xincr;
	int	Yincr;
}		t_draw;

typedef struct s_color
{
	int	sky;
	int	ground;
}		t_color;

typedef struct s_bg
{
	void		*b_img;
	int	*data;
	int	bpp;
	int	line_size;
	int	endian;
}		t_bg;

typedef struct s_key
{
	int	z;
	int	s;
	int	q;
	int	d;
}		t_key;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}		t_rgb;

typedef struct	s_cube
{
	t_mlx		*mlx;
	t_track		*track;
	t_map		*i_map;
	t_key		*key;
	t_player	*player;
	t_color		*color;
	t_bg		*bg;
	void		*img;
	int		*map;
	int	*data;
	int	*b_data;
	int	bpp;
	int	line_size;
	int	endian;
}		t_cube;

#endif
