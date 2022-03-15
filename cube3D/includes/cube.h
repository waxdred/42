#ifndef CUBE_h
#define CUBE_h
# include "includes.h"
# include "struct.h"
int		ft_pars_map(t_cube *cube, char *path);

void	ft_draw_minimap(t_cube *cube);
void	ft_draw_wall(t_cube *cube, int x0, int y0, int y1, int color);
char	*get_next_line(int fd);
int	deal_key(int key, t_cube *cube);
int	ft_escape(t_cube *cube, int key);
void	ft_mlx(t_cube *cube, t_mlx *mlx);
void	ft_player(t_cube *cube, t_player *player);
void	ft_init_player(t_cube *cube);
void	ft_reaload(t_cube *cube);
void	ft_bresenham(t_cube *cube, int x0, int y0, int x1, int y1, int color);
void	draw_ray_3d(t_cube *cube, t_player *player);
float	deg_rad(int a);
float	fix_angle(float a);
float	distance(float ax, float ay,float bx,float by);
void	ft_draw_background(t_mlx *mlx, t_cube *cube, t_color *color, t_bg *bg);
int	ft_collision(t_cube *cube);
t_rgb	*ft_change_bright_color(t_rgb *rgb, float correction);
unsigned long createRGB(t_rgb *rgb);
#endif
