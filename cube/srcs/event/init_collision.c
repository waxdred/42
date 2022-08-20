/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:44:12 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/12 21:47:58 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include <sys/fcntl.h>

static int8_t	ft_rl_translate(t_cub *c, t_col col, int8_t ret)
{
	if (ft_strchr("12", c->s_map[col.l_col]))
	{
		if (!ft_strchr("12", c->s_map[col.r_col]))
			c->player.pos.x += cos(col.oa) * c->player.speed;
		ret = 0;
	}
	if (ft_strchr("12", c->s_map[col.r_col]))
	{
		if (!ft_strchr("12", c->s_map[col.l_col]))
			c->player.pos.x -= sin(col.oa) * c->player.speed;
		ret = 1;
	}
	return (ret);
}

static int8_t	ft_ud_translate(t_cub *c, t_col col, int8_t ret)
{
	if (ft_strchr("12", c->s_map[col.u_col]))
	{
		if (!ft_strchr("12", c->s_map[col.d_col]))
			c->player.pos.x -= cos(col.oa) * c->player.speed;
		ret = 0;
	}
	if (ft_strchr("12", c->s_map[col.d_col]))
	{
		if (!ft_strchr("12", c->s_map[col.u_col]))
			c->player.pos.y += sin(col.oa) * c->player.speed;
		ret = 1;
	}
	return (ret);
}

static int8_t	ft_translate_move(t_cub *c, t_col col, int8_t d, int8_t i)
{
	int8_t	ret;

	ret = 0;
	if (d)
	{
		ret = ft_rl_translate(c, col, ret);
		ret = ft_ud_translate(c, col, ret);
	}
	if (!ret || i)
	{
		if (!ft_strchr("12", c->s_map[col.l_col]))
			c->player.pos.y += sin(col.oa) * c->player.speed;
		if (!ft_strchr("12", c->s_map[col.r_col]))
			c->player.pos.x += cos(col.oa) * c->player.speed;
	}
	return (ret);
}

static void	ft_change_dir(t_cub *c, t_col *col, int8_t *ret)
{
	if (c->inter.key[Q])
	{
		col->oa = c->player.pa - P2;
		if (!c->inter.active_wall[0].active)
			c->inter.active_wall[0].active = 1;
		if (c->inter.active_wall[1].active)
		{
			c->inter.active_wall[1].active = 0;
			*ret = 1;
		}
	}
	if (c->inter.key[D])
	{
		col->oa = c->player.pa + P2;
		if (!c->inter.active_wall[1].active)
			c->inter.active_wall[1].active = 1;
		if (c->inter.active_wall[0].active)
		{
			c->inter.active_wall[0].active = 0;
			*ret = 1;
		}
	}
}

void	ft_translate(t_cub *c)
{
	t_col	col;
	int8_t	ret;

	ret = 0;
	if (c->inter.key[Q] || c->inter.key[D])
	{
		ft_init_collision(&col, c);
		ft_change_dir(c, &col, &ret);
		if (ft_ft(c, col, ret))
			return ;
		if (!ret)
			ft_translate_move(c, col, 1, ret);
		else
			ft_translate_move(c, col, 0, ret);
		ft_reload(c);
	}
	return ;
}
