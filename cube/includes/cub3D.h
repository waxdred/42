/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:26:14 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/19 20:01:41 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "includes.h"
# include "define.h"
# include "struct.h"

// error

char	ft_alloc_error(void);

// parsing

char	*ft_gnl(int fd);
char	*ft_first_elem(char *line);
int8_t	ft_isspace(char c);
size_t	ft_nb_size(char *line);
int8_t	ft_str_start_with(char *str, char *to_find);
int8_t	ft_add_texture(t_cub *cub, t_texture *text, char *line,
			const char *key);
int8_t	ft_add_map(t_cub *cub, char *line);
int8_t	ft_add_color(t_color *color, char *line, const char *key);
int8_t	ft_pars_line(t_cub *cub, char *line);
int8_t	ft_check_map(t_cub *cub);
int8_t	ft_check_texture(t_cub *cub);
int8_t	ft_parsing(t_cub *cub, const char *file);
int8_t	ft_check_pos_player(t_player *p);
int		ft_map_in_string(t_cub *cube);

void	ft_destroy_all_textures(t_cub *cub);
int8_t	ft_get_textures(t_cub *cub);

// wall

void	ft_init_start_walls(t_wall *w);
void	ft_fill_wall(t_cub *cub, double *info[3], t_wall *wall,
			t_texture *text);
int8_t	ft_get_wall_img(t_cub *cub, t_wall *wall);

// init

int		ft_init_scale(t_cub *cub);
void	ft_reinit_minimap(t_cub *cub);
void	ft_reinit_display(t_cub *cub);

// draw mini_map 
void	ft_draw_minimap(t_cub *cub);
void	ft_draw_background(t_cub *cube, t_texture *bg);

//player
void	ft_init_player(t_cub *cube);
void	ft_player(t_cub *cube, t_player *p);

//drawin
void	ft_init_draw(t_draw *draw, t_line *line, int type);
void	ft_draw_line_img(t_line *line, int type, t_texture *text);
void	ft_draw_line(t_cub *cube, t_line *line, int type);
int		ft_start_draw(t_line *line, int x0, int y0, int color);
int		ft_end_draw(t_line *line, int x0, int y0);
int8_t	ft_img_opti_tab(t_cub *cub);
int8_t	ft_get_img_tab(t_cub *cub, t_texture *text, size_t x, size_t y);

//event
int		deal_key(t_cub *cube);
int		ft_close_door(t_cub *cube);
int		ft_debeug_key(t_cub *cube);
int		ft_door_key(t_cub *cube);
int		ft_escape(t_cub *cube);
int		ft_key_hit(int key, t_cub *cub);
int		ft_key_release(int key, t_cub *cub);
int		ft_mini_map_key(t_cub *cube);
int		ft_mouse(int key, t_cub *cube);
int		ft_mouse_hit(int button, int x, int y, t_cub *cub);
int		ft_mouse_release(int button, int x, int y, t_cub *cub);
int		ft_move(t_cub *cube);
int		ft_open_door(t_cub *cube);
int		ft_option_debeug(t_cub *cube);
int		ft_option_door(t_cub *cube);
int		ft_option_map(t_cub *cube);
int		ft_rotate(t_cub *cube);
int		ft_rotate_mouse(t_cub *cube, t_mouse *m);
int8_t	ft_ft(t_cub *c, t_col col, int8_t ret);
void	ft_translate(t_cub *c);
void	ft_debeug_draw(t_cub *cub, t_wall *tmp);
void	ft_init_collision(t_col *col, t_cub *cube);
void	ft_init_collision_door(t_col *col, t_cub *cube);
void	ft_reload(t_cub *cub);
void	ft_show_map(t_cub *cub);

//raycasting

double	deg_rad(int a);
double	fix_angle(float a);
double	ft_angle_from_vectors(t_pos *v1, t_pos *v2);
double	distance(float ax, float ay, float bx, float by);
size_t	ft_get_dist_max(t_cub *c);
void	draw_ray_3d(t_cub *cube, t_player *p);
void	ray_vertical(t_cub *cube, t_player *p, t_ray *ray);
void	ray_horizontal(t_cub *cube, t_player *p, t_ray *ray);
t_wall	*ft_get_wall_size(t_ray *ray, t_player *p);
t_dir	ft_dir_wall(t_ray *r);
void	ft_get_wall_extrem(t_wall *w, t_ray *r, t_dir dir);
void	ft_get_extrem_angles(t_wall *w, t_ray *r, t_player *p);
void	ft_correc_extern_wall(t_cub *cub, t_ray *last_r, t_player *p);
void	ft_get_x_dims(t_wall *w, t_player *p, t_ray *last_r,
			const double half_angle);
double	ft_get_origin(double angle, double dist, const double half_angle);
void	ft_get_entire_wall(t_wall *w, t_player *p, const double half_angle);
void	init_pos_wall(t_ray *ray, t_player *p, int8_t b, int *color);
void	h_distance(t_ray *ray, int color, t_player *p);
void	v_distance(t_ray *ray, int color);
void	init_distance(t_ray *ray);
void	ft_exec_raycast(t_cub *cube, t_ray *ray, int *color);
void	v_init_horizontal(t_cub *cube, t_player *p, t_ray *ray);
void	h_init_horizontal(t_cub *cube, t_player *p, t_ray *ray);

#endif
