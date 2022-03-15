#ifndef CUBE_h
#define CUBE_h
# include "includes.h"
# include "struct.h"

// parsing
char	*get_next_line(int fd);
int	ft_check_extension(char *path);
int	ft_check_dir_t(t_texture *t);
int	check_map_line(char *line);
int	ft_get_map_line(t_cube *cube, char *line, int *index);
int	ft_pars_map(t_cube *cube, char *path);
void	ft_set_rgb(t_rgb *rgb, int r, int g, int b);

// color
int	ft_add_color_rgb(char **tab, t_rgb *rgb);
int 	createRGB(t_rgb *rgb);
t_rgb	*ft_change_bright_color(t_rgb *rgb, float correction);
void	ft_set_rgb(t_rgb *rgb, int r, int g, int b);

//player /cam
void	ft_init_player(t_cube *cube);
void	ft_player(t_cube *cube, t_player *p);

//mlx
void	ft_init(t_cube *cube, t_color *color);
void	ft_mlx(t_cube *cube);
void	ft_reaload(t_cube *cube);

//math
float	deg_rad(int	a);
float	fix_angle(float a);
float	distance(float ax, float ay,float bx,float by);

// event
int	deal_key(int key, t_cube *cube);
int	ft_move(t_cube *cube, int key);

//raycasting
void	draw_ray_3d(t_cube *cube, t_player *p);

//aw
void	ft_draw_line(t_cube *cube, t_line *line, int type);
int	ft_end_draw(t_line *line, int x0, int y0);
int	ft_start_draw(t_line *line, int x0, int y0, int	color);
void	ft_draw_background(t_cube *cube, t_bg *bg);
void	ft_draw_minimap(t_cube *cube);
void	ft_bresenham(t_cube *cube, int x0, int y0, int x1, int y1, int color);
#endif
