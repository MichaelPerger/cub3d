/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoller <mkoller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:09:07 by mkoller           #+#    #+#             */
/*   Updated: 2023/02/24 14:10:31 by mkoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycast.h"

void	set_rayprojection_val(t_rays *ray, float screen_dist, t_vars *vars)
{
	ray->fixed_dist = ray->distance * cos(ray->angle - vars->player.angle);
	ray->wallheight = (TILE_SIZE / ray->fixed_dist) * screen_dist;
	ray->wall_start = (vars->win_height / 2) - (ray->wallheight / 2);
	ray->wall_end = (vars->win_height / 2) + (ray->wallheight / 2);
	if (ray->wall_start < 0)
		ray->wall_start = 0;
	if (ray->wall_end > vars->win_height)
		ray->wall_end = vars->win_height;
}

void	set_ray_wallhit(t_rays *ray, t_vars *vars)
{
	t_inter	vert_hit;
	t_inter	horz_hit;

	set_vert_hit(&vert_hit, vars, ray);
	set_horz_hit(&horz_hit, vars, ray);
	find_vert_wallhit(vars, ray, &vert_hit);
	find_horz_wallhit(vars, ray, &horz_hit);
	if (vert_hit.distance < horz_hit.distance)
	{
		ray->wallhitx = vert_hit.wallhitx;
		ray->wallhity = vert_hit.wallhity;
		ray->distance = vert_hit.distance;
		ray->hitisvertical = TRUE;
	}
	else
	{
		ray->wallhitx = horz_hit.wallhitx;
		ray->wallhity = horz_hit.wallhity;
		ray->distance = horz_hit.distance;
		ray->hitisvertical = FALSE;
	}
}

void	set_horz_hit(t_inter *horz, t_vars *vars, t_rays *ray)
{
	float	x;
	float	y;

	x = vars->player.x;
	y = vars->player.y;
	horz->distance = (float)INT_MAX;
	horz->y_inter = ((int)(y / TILE_SIZE)) * TILE_SIZE;
	if (ray->rayisdown)
		horz->y_inter += TILE_SIZE;
	horz->x_inter = x - (horz->y_inter - y) / tan(ray->angle);
	horz->y_step = TILE_SIZE;
	if (ray->rayisup)
		horz->y_step *= -1;
	horz->x_step = TILE_SIZE / tan(ray->angle);
	if (ray->rayisleft && horz->x_step > 0)
		horz->x_step *= -1;
	else if (ray->rayisright && horz->x_step < 0)
		horz->x_step *= -1;
	horz->next_x = horz->x_inter;
	horz->next_y = horz->y_inter;
}

void	set_vert_hit(t_inter *vert, t_vars *vars, t_rays *ray)
{
	float	x;
	float	y;

	x = vars->player.x;
	y = vars->player.y;
	vert->distance = (float)INT_MAX;
	vert->x_inter = ((int)(x / TILE_SIZE)) * TILE_SIZE;
	if (ray->rayisright)
		vert->x_inter += TILE_SIZE;
	vert->y_inter = y - (vert->x_inter - x) * tan(ray->angle);
	vert->x_step = TILE_SIZE;
	if (ray->rayisleft)
		vert->x_step *= -1;
	vert->y_step = TILE_SIZE * tan(ray->angle);
	if (ray->rayisup && vert->y_step > 0)
		vert->y_step *= -1;
	else if (ray->rayisdown && vert->y_step < 0)
		vert->y_step *= -1;
	vert->next_x = vert->x_inter;
	vert->next_y = vert->y_inter;
}

void	set_ray_angle(t_rays *ray, float ray_angle)
{
	ray->angle = ray_angle;
	if (ray_angle > 0 && ray_angle < M_PI)
		ray->rayisup = TRUE;
	else
		ray->rayisup = FALSE;
	if (ray_angle < M_PI / 2 || ray_angle > (3 * M_PI) / 2)
		ray->rayisright = TRUE;
	else
		ray->rayisright = FALSE;
	ray->rayisdown = !ray->rayisup;
	ray->rayisleft = !ray->rayisright;
}
