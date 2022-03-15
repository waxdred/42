
#ifndef STRUCT_H
#define STRUCT_H
#include "includes.h"


typedef struct s_map
{
	int	mapX;
	int	mapY;
}		t_map;

typedef struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	color;
}		t_line;

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
	float	Tan;
	float	ca;
	float	disH;
	float	disHn;
	float	disT;
	float	disV;
	float	disVn;
	float	hx;
	float	hy;
	float	nTan;
	float	ra;
	float	rx;
	float	ry;
	float	vx;
	float	vy;
	float	xo;
	float	yo;
	int	dof;
	int	lineH;
	int	lineO;
	int	mp;
	int	mx;
	int	my;
	int	r;
	int	side;
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

typedef struct texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}	t_texture;

typedef struct s_color
{
	t_rgb		*sky;
	t_rgb		*ground;
	t_rgb		*no;
	t_rgb		*so;
	t_rgb		*we;
	t_rgb		*ae;
}		t_color;

typedef struct	s_cube
{
	char		**map;
	int		wd_height;
	int		wd_width;
	int		*b_data;
	int		*data;
	int		bpp;
	int		endian;
	int		line_size;
	t_bg		*bg;
	t_color		*color;
	t_key		*key;
	t_line		*line;
	t_map		*i_map;
	t_player	*player;
	t_texture	*text;
	t_track		*track;
	void		*img;
	void		*p_mlx;
	void		*p_win;
}		t_cube;

#endif
