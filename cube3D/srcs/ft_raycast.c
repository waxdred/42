
#include "../includes/cube.h"

static void	ray_horizontal(t_cube *cube, t_player *p, t_ray *ray)
{
	ray->dof = 0;
	ray->disH = 2000;
	ray->hx = p->pos_x;
	ray->hy = p->pos_y;
	ray->Tan = -1/tan(ray->ra);
	if (ray->ra > PI)
	{
		ray->ry = (((int)p->pos_y >> 6) << 6) - 0.0001;
		ray->rx = (p->pos_y - ray->ry) * ray->Tan + p->pos_x;
		ray->yo =-(SQUARES);
		ray->xo = -ray->yo * ray->Tan;
	}
	if (ray->ra < PI)
	{
		ray->ry = (((int)p->pos_y >> 6) << 6) + (SQUARES);
		ray->rx = (p->pos_y - ray->ry) * ray->Tan + p->pos_x;
		ray->yo = (SQUARES);
		ray->xo = -ray->yo * ray->Tan;
	}
	if (ray->ra == 0 || ray->ra == PI)
	{
		ray->rx = p->pos_x;
		ray->ry = p->pos_y;
		ray->dof = 5;
	}
	while (ray->dof < 5)
	{
		ray->mx = (int)(ray->rx) >> 6;
		ray->my = (int)(ray->ry) >> 6;
		ray->mp = ray->my * cube->i_map->mapX + ray->mx;
		if (ray->mp > 0 && ray->mp < cube->i_map->mapX * cube->i_map->mapY && cube->map[ray->mp] == 1)
		{
			ray->hx = ray->rx;
			ray->hy = ray->ry;
			ray->disH = distance(p->pos_x, p->pos_y, ray->hx, ray->hy);
			ray->dof = 5;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof += 1;
		}
	}
}
static void	ray_vertical(t_cube *cube, t_player *p, t_ray *ray)
{
	ray->dof = 0;
	ray->disV = 2000;
	ray->vx = p->pos_x;
	ray->vy = p->pos_y;
	ray->Tan = -tan(ray->ra);
	if (ray->ra > P2 && ray->ra < P3)
	{
		ray->rx = (((int)p->pos_x >> 6) << 6) - 0.0001;
		ray->ry = (p->pos_x - ray->rx) * ray->Tan + p->pos_y;
		ray->xo = -(SQUARES);
		ray->yo = -ray->xo * ray->Tan;
	}
	if (ray->ra < P2 || ray->ra > P3)
	{
		ray->rx = (((int)p->pos_x >> 6) << 6) + (SQUARES);
		ray->ry = (p->pos_x - ray->rx) * ray->Tan + p->pos_y;
		ray->xo = (SQUARES);
		ray->yo = -ray->xo * ray->Tan;
	}
	if (ray->ra == 0 || ray->ra == PI)
	{
		ray->rx = p->pos_x;
		ray->ry = p->pos_y;
		ray->dof = 5;
	}
	while (ray->dof < 5)
	{
		ray->mx = (int)(ray->rx) >> 6;
		ray->my = (int)(ray->ry) >> 6;
		ray->mp = ray->my * cube->i_map->mapX + ray->mx;
		if (ray->mp > 0 && ray->mp < cube->i_map->mapX * cube->i_map->mapY && cube->map[ray->mp] == 1)
		{
			ray->vx = ray->rx;
			ray->vy = ray->ry;
			ray->disV = distance(p->pos_x, p->pos_y, ray->vx, ray->vy);
			ray->dof = 5;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof += 1;
		}
	}
}
void	draw_ray_3d(t_cube *cube, t_player *p)
{
	t_ray ray;
	int	color;

	ft_bzero(&ray, sizeof(t_ray));
	ray.ra = fix_angle(p->pa - RAD * (DOF / 2));

	while ( ray.r < DOF)
	{
		ray_horizontal(cube, p, &ray);
		ray_vertical(cube, p, &ray);
		if (ray.disH < 0)
			ray.disHn = ray.disH * -1;
		else
			ray.disHn = ray.disH;
		if (ray.disV < 0)
			ray.disVn = ray.disV * -1;
		else
			ray.disVn = ray.disV;
		if (ray.disVn < ray.disHn)
		{
			ray.rx = ray.vx;
			ray.ry = ray.vy;
			ray.disT = ray.disV;
		}
		if (ray.disHn < ray.disVn)
		{
			ray.rx = ray.hx;
			ray.ry = ray.hy;
			ray.disT = ray.disH;
			color = 0xFFFF00;
		}
		ray.ca =fix_angle(p->pa - ray.ra);
		ray.disT = ray.disT * cos(ray.ca);
		ray.lineH = (SQUARES * cube->mlx->wd_height) / ray.disT;
		if (ray.lineH > cube->mlx->wd_width)
			ray.lineH = cube->mlx->wd_width;
		ray.lineO = cube->mlx->wd_height / 2 - (ray.lineH / 2);
		int	i;
		int	size;

		size = (int)(cube->mlx->wd_width / DOF) + 1;
		i = 0;
		while (i++ < size)
		{
			ft_bresenham(cube, ray.r * size + size - i, ray.lineO,
					ray.r * size + size - i, ray.lineH + ray.lineO, color);
		}
		//ray off the player drawn
		/* ft_bresenham(cube, p->pos_x * SCALE, p->pos_y * SCALE, ray.rx * SCALE, */
		/* 		ray.ry * SCALE, 0xFF0000); */
		ray.ra = fix_angle(ray.ra + RAD);
		ray.r++;
	}
}
