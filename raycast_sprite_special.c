#include "cub3d.h"
#include "raycast.h"

void	draw_sprite_special(t_vars *vars, t_sprite *sprite, int x_offset,
		int y_offset)
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
			sprite_color = sprite_color_geter_special(vars, sprite, x_sprite,
					y_sprite);
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

int	sprite_color_geter_special(t_vars *vars, t_sprite *sprite, int x, int y)
{
	int	x_xpm;
	int	y_xpm;
	int	color;

	x_xpm = x / sprite->width * vars->text.sprite.width;
	y_xpm = y / sprite->height * vars->text.sprite.height;
	if (vars->random_enemy == 0)
		color = get_image_pixel(&vars->text.sprite2, x_xpm, y_xpm);
	else if (vars->random_enemy == 1)
		color = get_image_pixel(&vars->text.sprite3, x_xpm, y_xpm);
	else
		color = get_image_pixel(&vars->text.sprite4, x_xpm, y_xpm);
	return (color);
}
