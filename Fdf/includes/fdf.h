/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 23:30:12 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/19 23:30:12 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	_FDF_H
#define _FDF_H
#include "../Gnl/includes/get_next_line.h"
#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include "fdf_struct.h"
#include "define.h"
#include <math.h>

int	**ft_tabnew_two(size_t x, size_t y);
int	deal_key(int key, t_env *fdf);
int	ft_create_map(char *argv, t_env *fdf);
int	ft_fdf(char *argv);
int	ft_free_map(t_env *fdf);
int	ft_mlx(t_env *fdf, char *argv);
int	ft_reload(t_env *fdf);
int	mouse_key(int key, t_env *fdf);
void	ft_bresenham(t_env *fdf, float x1, float y1);
void	ft_draw_mlx_print(t_env *fdf, int x, int y);
void	ft_put_string_mlx(t_env *fdf);
void	ft_init(t_env *fdf);
void	ft_menu(t_env *fdf);
void	ft_window(t_env *fdf);
int	ft_projection(t_env *fdf, int key);
int	ft_zoom(t_env *fdf, int key);
int	ft_escape(t_env *fdf, int key);
void	ft_move_proj(t_env *fdf, int key);
void	ft_move_iso(t_env *fdf, int key);
#endif
