#include "cub3d.h"
#include "raycast.h"

int	render_sprites(t_vars *vars, t_sprite *sprite)
{
	float	screen_dist;
	float	ortho_dist;

	screen_dist = (vars->win_width / 2) / tan(radconvert(FOV / 2));
	sprite->angle = vars->player.angle;
	sprite->angle += atan2(sprite->y - vars->player.y,
			sprite->x - vars->player.x);
	sprite->angle = within_twopi(sprite->angle);
	sprite->dist = get_distance(vars->player.x, vars->player.y, sprite->x,
			sprite->y);
	ortho_dist = sprite->dist * cos(sprite->angle);
	sprite->height = (TILE_SIZE / ortho_dist) * screen_dist;
	sprite->width = sprite->height;
	sprite->top_y = (vars->win_height / 2) - (sprite->height / 2);
	sprite->bottom_y = (vars->win_height / 2) + (sprite->height / 2) - 1;
	sprite->left_x = (vars->win_width / 2) + tan(sprite->angle) * screen_dist;
	sprite->left_x -= sprite->width / 2;
	sprite->right_x = sprite->left_x + sprite->width - 1;
	return (0);
}

int	sprite_color_geter(t_vars *vars, t_sprite *sprite, int x, int y)
{
	int	x_xpm;
	int	y_xpm;
	int	color;

	x_xpm = x / sprite->width * vars->text.sprite.width;
	y_xpm = y / sprite->height * vars->text.sprite.height;
	color = get_image_pixel(&vars->text.sprite, x_xpm, y_xpm);
	return (color);
}

void	draw_sprite(t_vars *vars, t_sprite *sprite, int x_offset, int y_offset)
{
	int	x;
	int	y;
	int	y_sprite;
	int	x_sprite;
	int	sprite_color;

	x = sprite->left_x + x_offset;
	x_sprite = (int)x_offset;
	while (x <= sprite->right_x && x < vars->win_width)
	{
		y_sprite = (int)y_offset;
		y = sprite->top_y + y_offset;
		while (y <= sprite->bottom_y && y < vars->win_height)
		{
			sprite_color = sprite_color_geter(vars, sprite, x_sprite, y_sprite);
			if (sprite->dist < vars->rays[x].distance)
				if (sprite_color != 0)
					my_mlx_pixel_put(vars, x, y, sprite_color);
			y_sprite++;
			y++;
		}
		x_sprite++;
		x++;
	}
}

int	cast_sprites(t_vars *vars)
{
	int	i;
	int	x_offset;
	int	y_offset;

	i = 0;
	while (i < vars->sprite_count)
		render_sprites(vars, &vars->sprites[i++]);
	sort_sprites(vars);
	i = 0;
	while (i < vars->sprite_count)
	{
		y_offset = 0;
		x_offset = 0;
		while (vars->sprites[i].left_x + x_offset < 0)
			x_offset++;
		while (vars->sprites[i].top_y + y_offset < 0)
			y_offset++;
		if (vars->sprites[i].type == 2)
			draw_sprite(vars, &vars->sprites[i], x_offset, y_offset);
		else if (vars->sprites[i].type == 3)
			draw_sprite_special(vars, &vars->sprites[i], x_offset, y_offset);
		i++;
	}
	return (0);
}
