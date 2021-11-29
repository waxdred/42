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

int	ft_fdf(char *argv);
int	ft_free_map(t_env *fdf);
int	ft_create_map(char *argv, t_env *fdf);
int	ft_create_map_or(t_env *fdf);
void	ft_draw_tab(t_env *fdf);
void	ft_init(t_env *fdf);
void	ft_window(t_env *fdf);
int	ft_mlx(t_env *fdf, char *argv);
void	ft_add_ord(t_env *fdf, int i, int j);
int	deal_key(int key, t_env *fdf);
int	**ft_tabnew_two(size_t x, size_t y);
void	ft_draw_mlx_print(t_env *fdf);
void	ft_put_str_mlx(t_env *fdf, char *argv);
void	ft_bresenham(t_env *fdf);
#endif
