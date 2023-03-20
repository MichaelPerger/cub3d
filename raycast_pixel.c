#include "cub3d.h"
#include "raycast.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->game.addr + (y * vars->game.line_len + x * (vars->game.bpp
				/ 8));
	*(unsigned int *)dst = color;
}

int	get_image_pixel(t_img *text, int x, int y)
{
	char	*pix;

	pix = text->addr + (y * text->line_len) + (x * 4);
	return (*(unsigned int *)(pix));
}

unsigned int	color_geter(t_vars *vars, t_rays *ray, int y_text)
{
	unsigned int	color;

	color = 0;
	if (ray->hitisvertical)
	{
		if (ray->rayisright)
			color = get_image_pixel(&vars->text.east, vars->x_text, y_text);
		else
			color = get_image_pixel(&vars->text.west, vars->x_text, y_text);
	}
	else
	{
		if (ray->rayisup)
			color = get_image_pixel(&vars->text.south, vars->x_text,
					y_text);
		else
			color = get_image_pixel(&vars->text.north, vars->x_text,
					y_text);
	}
	return (color);
}

void	xpm_wall_pixel_put(t_vars *vars, t_rays ray, int x, int *y)
{
	int				y_text;
	unsigned int	color;
	int				pos_in_wall;

	y_text = 0;
	pos_in_wall = 0;
	if (ray.wallheight > vars->win_height)
		pos_in_wall += (ray.wallheight - vars->win_height) / 2;
	while (*y >= ray.wall_start && *y <= ray.wall_end)
	{
		y_text = (((int)pos_in_wall) / ray.wallheight) * vars->text.east.width;
		color = color_geter(vars, &ray, y_text);
		my_mlx_pixel_put(vars, x, *y, color);
		*y += 1;
		pos_in_wall++;
	}
}
