#include "includes/cube.h"

static void	ray_horizontal(t_cube *cube, t_player *p, t_ray *ray)
{
	ray->dof = 0;
	ray->disH = 100000;
	ray->Tan = 1.0 / ray->Tan; 
	if(sin(deg_rad(ray->ra)) > 0.001)
	{ 
		ray->ry = (((int)p->pos_y >> 6) << 6) -0.0001;
		ray->rx = (p->pos_y - ray->ry) * ray->Tan + p->pos_x;
		ray->yo = -SQUARES;
		ray->xo = -ray->yo * ray->Tan;
	}
  	else if(sin(deg_rad(ray->ra)) < -0.001)
	{
		ray->ry = (((int)p->pos_y >> 6) << 6) + SQUARES;
		ray->rx = (p->pos_y - ray->ry) * ray->Tan + p->pos_x;
		ray->yo = SQUARES;
		ray->xo = -ray->yo *ray->Tan;
	}
	else
	{
		ray->rx = p->pos_x;
		ray->ry = p->pos_y;
		ray->dof = 8;
	}                                                   //looking straight left or right
 
	while(ray->dof < 8) 
	{ 
		ray->mx = (int)(ray->rx) >> 6;
	ray->my = (int)(ray->ry) >> 6;
		ray->mp = ray->my * cube->i_map->mapX + ray->mx;                          
	   	if(ray->mp > 0 && ray->mp < cube->i_map->mapX * cube->i_map->mapY && cube->map[ray->mp] == 1)
		{
			ray->dof = 8;
			ray->disH = cos(deg_rad(ray->ra)) * (ray->rx - p->pos_x) - sin(deg_rad(ray->ra))
				* (ray->ry - p->pos_y);
		}
	   	else
		{ 
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof += 1;
		}                                               //check next horizontal
	}
}

static void	ray_vertical(t_cube *cube, t_player *p, t_ray *ray)
{
	ray->dof = 0;
	ray->side = 0;
	ray->disH = 100000;
	ray->Tan = tan(deg_rad(ray->ra)); 
	if(cos(deg_rad(ray->ra)) > 0.001)
	{ 
		ray->rx = (((int)p->pos_x >> 6) << 6) + SQUARES;
		ray->ry = (p->dp_x - ray->rx) * ray->Tan + p->pos_y;
		ray->xo = SQUARES;
		ray->yo = -ray->xo * ray->Tan;
	}
  	else if(cos(deg_rad(ray->ra)) < -0.001)
	{
		ray->rx = (((int)p->pos_x >> 6) << 6) - 0.001;
		ray->ry = (p->pos_x - ray->rx) * ray->Tan + p->pos_y;
		ray->xo = -SQUARES;
		ray->yo = -ray->xo *ray->Tan;
	}
	else
	{
		ray->rx = p->pos_x;
		ray->ry = p->pos_y;
		ray->dof = 8;
	}                                                   //looking straight left or right
 
	while(ray->dof < 8) 
	{ 
		ray->mx = (int)(ray->rx) >> 6;
		ray->my = (int)(ray->ry) >> 6;
		ray->mp = ray->my * cube->i_map->mapX + ray->mx;                          
	   	if(ray->mp > 0 && ray->mp < cube->i_map->mapX * cube->i_map->mapY && cube->map[ray->mp] == 1)
		{
			ray->dof = 8;
			ray->disV = cos(deg_rad(ray->ra)) * (ray->rx - p->pos_x) - sin(deg_rad(ray->ra))
				* (ray->ry - p->pos_y);
		}
	   	else
		{ 
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof += 1;
		}                                               //check next horizontal
	}
	ray->vx = ray->rx;
	ray->vy = ray->ry;
}
void	draw_ray_3d(t_cube *cube, t_player *p)
{
	t_ray ray;

	ft_bzero(&ray, sizeof(t_ray));
	ray.ra = fix_angle(p->pa + 30);
	while (ray.r < 60)
	{
		ray_vertical(cube, p, &ray);
		ray_horizontal(cube, p, &ray);
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
		}
		ft_bresenham(cube, p->pos_x, p->pos_y, ray.rx, ray.ry, 0xFF0000);
		ray.ca = fix_angle(p->pa - ray.ra);
		ray.disT = ray.disT * cos(deg_rad(ray.ca));
		ray.lineH = (SQUARES * 320) / ray.disT;
		ray.lineO = 160 - ray.lineH/2;
		if (ray.lineH > 320)
			ray.lineH = 320;
		ft_bresenham(cube, ray.r*2+ 200, ray.lineO, ray.r*2 + 200, ray.lineH + ray.lineO, 0xFF0000);
		/* ft_draw_wall(cube, ray.r, , ray.lineH + ray.lineO, 0x475869); */
		ray.ra = fix_angle(ray.ra + RAD);
		ray.r++;
	}
}
	


static void	ray_horizontal(t_cube *cube, t_player *p, t_ray *ray)
{
	ray->dof = 0;
	ray->disH = 100000000;
	ray->hx = p->pos_x;
	ray->hy = p->pos_y;
	ray->Tan = -1/tan(ray->ra);
	if (ray->ra > PI)
	{
		ray->ry = (((int)p->pos_y >> 6) << 6) - 0.0001;
		ray->rx = (p->pos_y - ray->ry) * ray->Tan + p->pos_x;
		ray->yo =-(SQUARES * SCALE);
		ray->xo = -ray->yo * ray->Tan;
	}
	if (ray->ra < PI)
	{
		ray->ry = (((int)p->pos_y >> 6) << 6) + (SQUARES * SCALE);
		ray->rx = (p->pos_y - ray->ry) * ray->Tan + p->pos_x;
		ray->yo = (SQUARES * SCALE);
		ray->xo = -ray->yo * ray->Tan;
	}
	if (ray->ra == 0 || ray->ra == PI)
	{
		ray->rx = p->pos_x;
		ray->ry = p->pos_y;
		ray->dof = 8;
	}
	while (ray->dof < 8)
	{
		ray->mx = (int)(ray->rx) >> 6;
		ray->my = (int)(ray->ry) >> 6;
		ray->mp = ray->my * cube->i_map->mapX + ray->mx;
		if (ray->mp > 0 && ray->mp < cube->i_map->mapX * cube->i_map->mapY && cube->map[ray->mp] == 1)
		{
			ray->hx = ray->rx;
			ray->hy = ray->ry;
			ray->disH = distance(p->pos_x, p->pos_y, ray->hx, ray->hy, ray->ra);
			ray->dof = 8;
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
	ray->disV = 100000000;
	ray->vx = p->pos_x;
	ray->vy = p->pos_y;
	ray->Tan = -tan(ray->ra);
	if (ray->ra > P2 && ray->ra < P3)
	{
		ray->rx = (((int)p->pos_x >> 6) << 6) - 0.0001;
		ray->ry = (p->pos_x - ray->rx) * ray->Tan + p->pos_y;
		ray->xo = -(SQUARES * SCALE);
		ray->yo = -ray->xo * ray->Tan;
	}
	if (ray->ra < P2 || ray->ra > P3)
	{
		ray->rx = (((int)p->pos_x >> 6) << 6) + (SQUARES * SCALE);
		ray->ry = (p->pos_x - ray->rx) * ray->Tan + p->pos_y;
		ray->xo = (SQUARES * SCALE);
		ray->yo = -ray->xo * ray->Tan;
	}
	if (ray->ra == 0 || ray->ra == PI)
	{
		ray->rx = p->pos_x;
		ray->ry = p->pos_y;
		ray->dof = 8;
	}
	while (ray->dof < 8)
	{
		ray->mx = (int)(ray->rx) >> 6;
		ray->my = (int)(ray->ry) >> 6;
		ray->mp = ray->my * cube->i_map->mapX + ray->mx;
		if (ray->mp > 0 && ray->mp < cube->i_map->mapX * cube->i_map->mapY && cube->map[ray->mp] == 1)
		{
			ray->vx = ray->rx;
			ray->vy = ray->ry;
			ray->disV = distance(p->pos_x, p->pos_y, ray->vx, ray->vy, ray->ra);
			ray->dof = 8;
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

	ft_bzero(&ray, sizeof(t_ray));
	ray.ra = p->pa - RAD * 30;
	if (ray.ra < 0)
		ray.ra += 2 * PI;
	else if (ray.ra > 2 * PI)
		ray.ra -= 2 * PI;
	while ( ray.r < 180)
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
			ray.disT = ray.disV;
		}
		ft_bresenham(cube, p->pos_x, p->pos_y, ray.rx, ray.ry, 0xE0FFFF);
		ray.ca = p->pa - ray.ra;
		if (ray.ca < 0)
			ray.ca += 2 * PI;
		if (ray.ca > 2 * PI)
			ray.ca -= 2 * PI;
		ray.disT = ray.disT * cos(ray.ca);
		ray.lineH = (SQUARES * 320) / ray.disT;
		ray.lineO = 160 - ray.lineH / 2;
		if (ray.lineH > 320)
			ray.lineH = 320;
		ft_bresenham(cube, ray.r, (cube->mlx->wd_width / 2) - 32 / ray.disT,
				ray.r,  (cube->mlx->wd_width / 2) - 32 / ray.disT, 0xFF0000);
		ft_draw_wall(cube, ray.r, , ray.lineH + ray.lineO, 0x475869);
		ray.ra += RAD;
		if (ray.ra < 0)
			ray.ra += 2 * PI;
		else if (ray.ra > 2 * PI)
			ray.ra -= 2 * PI;
		ray.r++;
	}
}

oooooooooooooooooooooooooooooooooooooooooooooooooooooooooo


#include "../includes/cube.h"


static void	ray_horizontal(t_cube *cube, t_player *p, t_ray *ray)
{
	ray->dof = 0;
	ray->disH = 100000000;
	ray->hx = p->pos_x;
	ray->hy = p->pos_y;
	ray->Tan = -1/tan(ray->ra);
	if (ray->ra > PI)
	{
		ray->ry = (((int)p->pos_y >> 6) << 6) - 0.0001;
		ray->rx = (p->pos_y - ray->ry) * ray->Tan + p->pos_x;
		ray->yo =-(SQUARES * SCALE);
		ray->xo = -ray->yo * ray->Tan;
	}
	if (ray->ra < PI)
	{
		ray->ry = (((int)p->pos_y >> 6) << 6) + (SQUARES * SCALE);
		ray->rx = (p->pos_y - ray->ry) * ray->Tan + p->pos_x;
		ray->yo = (SQUARES * SCALE);
		ray->xo = -ray->yo * ray->Tan;
	}
	if (ray->ra == 0 || ray->ra == PI)
	{
		ray->rx = p->pos_x;
		ray->ry = p->pos_y;
		ray->dof = 8;
	}
	while (ray->dof < 8)
	{
		ray->mx = (int)(ray->rx) >> 6;
		ray->my = (int)(ray->ry) >> 6;
		ray->mp = ray->my * cube->i_map->mapX + ray->mx;
		if (ray->mp > 0 && ray->mp < cube->i_map->mapX * cube->i_map->mapY && cube->map[ray->mp] == 1)
		{
			ray->hx = ray->rx;
			ray->hy = ray->ry;
			ray->disH = distance(p->pos_x, p->pos_y, ray->hx, ray->hy);
			ray->dof = 8;
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
	ray->disV = 100000000;
	ray->vx = p->pos_x;
	ray->vy = p->pos_y;
	ray->Tan = -tan(ray->ra);
	if (ray->ra > P2 && ray->ra < P3)
	{
		ray->rx = (((int)p->pos_x >> 6) << 6) - 0.0001;
		ray->ry = (p->pos_x - ray->rx) * ray->Tan + p->pos_y;
		ray->xo = -(SQUARES * SCALE);
		ray->yo = -ray->xo * ray->Tan;
	}
	if (ray->ra < P2 || ray->ra > P3)
	{
		ray->rx = (((int)p->pos_x >> 6) << 6) + (SQUARES * SCALE);
		ray->ry = (p->pos_x - ray->rx) * ray->Tan + p->pos_y;
		ray->xo = (SQUARES * SCALE);
		ray->yo = -ray->xo * ray->Tan;
	}
	if (ray->ra == 0 || ray->ra == PI)
	{
		ray->rx = p->pos_x;
		ray->ry = p->pos_y;
		ray->dof = 8;
	}
	while (ray->dof < 8)
	{
		ray->mx = (int)(ray->rx) >> 6;
		ray->my = (int)(ray->ry) >> 6;
		ray->mp = ray->my * cube->i_map->mapX + ray->mx;
		if (ray->mp > 0 && ray->mp < cube->i_map->mapX * cube->i_map->mapY && cube->map[ray->mp] == 1)
		{
			ray->vx = ray->rx;
			ray->vy = ray->ry;
			ray->disV = distance(p->pos_x, p->pos_y, ray->vx, ray->vy);
			ray->dof = 8;
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

	ft_bzero(&ray, sizeof(t_ray));
	ray.ra = p->pa - RAD * 30;
	if (ray.ra < 0)
		ray.ra += 2 * PI;
	if (ray.ra > 2 * PI)
		ray.ra -= 2 * PI;
	while ( ray.r < 120)
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
		}
		if (ray.disHn < ray.disVn)
		{
			ray.rx = ray.hx;
			ray.ry = ray.hy;
		}
		ray.rScale = (cube->mlx->wd_width / 2) / 120;
		printf("dist ray = %f\n", ray.disT);
		ft_bresenham(cube, p->pos_x, p->pos_y, ray.rx, ray.ry, 0xFF0000);
		ray.ca =fix_angle(p->pa - ray.ra);
		/* ray.disT = ray.disT); */
		ray.lineH = (SQUARES * 340) / ray.disT;
		if (ray.lineH > cube->mlx->wd_height)
			ray.lineH = cube->mlx->wd_height;
		ray.lineO = 160 - (ray.lineH / 2);
		/* ft_draw_rectangle(cube, 100, 100, 200, 200, 0xFF0000); */
		ft_bresenham(cube, ray.r*2+700, ray.lineO, ray.r*2+700, ray.lineH + ray.lineO, 0xFF0000);
		/* ft_draw_rectangle(cube, ray.r*8 + 200, ray.lineO, ray.r*8 + 200, ray.lineH + ray.lineO, 0xFF0000); */
		ray.ra += RAD;
		if (ray.ra < 0)
			ray.ra += 2 * PI;
		if (ray.ra > 2 * PI)
			ray.ra -= 2 * PI;
		ray.r++;
	}
}

