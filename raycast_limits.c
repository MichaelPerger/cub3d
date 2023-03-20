#include "cub3d.h"
#include "raycast.h"

int	is_wall(float x, float y, t_vars *vars)
{
	int		row;
	int		col;
	char	item;

	row = y / TILE_SIZE;
	col = x / TILE_SIZE;
	item = vars->map[row][col];
	if (item == '1' || item == ' ')
		return (1);
	return (0);
}

int	is_maplimit(float x, float y, t_vars *vars)
{
	float	map_limit_y;
	float	map_limit_x;

	map_limit_x = TILE_SIZE * vars->max_col;
	map_limit_y = TILE_SIZE * vars->max_row;
	if (y >= map_limit_y || y < 0)
		return (1);
	if (x >= map_limit_x || x < 0)
		return (1);
	return (0);
}

void	find_vert_wallhit(t_vars *vars, t_rays *ray, t_inter *vert)
{
	float	tmp;
	float	x1;
	float	y1;

	x1 = vars->player.x;
	y1 = vars->player.y;
	tmp = 0;
	if (ray->rayisleft)
		tmp = -1;
	while (!is_maplimit(vert->next_x + tmp, vert->next_y, vars))
	{
		if (is_wall(vert->next_x + tmp, vert->next_y, vars))
		{
			vert->wallhitx = vert->next_x;
			vert->wallhity = vert->next_y;
			vert->distance = get_distance(x1, y1, vert->next_x, vert->next_y);
			return ;
		}
		vert->next_x += vert->x_step;
		vert->next_y += vert->y_step;
	}
}

void	find_horz_wallhit(t_vars *vars, t_rays *ray, t_inter *horz)
{
	float	tmp;
	float	x1;
	float	y1;

	x1 = vars->player.x;
	y1 = vars->player.y;
	tmp = 0;
	if (ray->rayisup)
		tmp = -1;
	while (!is_maplimit(horz->next_x, horz->next_y + tmp, vars))
	{
		if (is_wall(horz->next_x, horz->next_y + tmp, vars))
		{
			horz->wallhitx = horz->next_x;
			horz->wallhity = horz->next_y;
			horz->distance = get_distance(x1, y1, horz->next_x, horz->next_y);
			return ;
		}
		horz->next_x += horz->x_step;
		horz->next_y += horz->y_step;
	}
}
