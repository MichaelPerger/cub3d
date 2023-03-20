#include "cub3d.h"
#include "raycast.h"

void	mini_map_player(t_vars *vars, int player_x, int player_y)
{
	int	x;
	int	y;

	x = vars->win_width * 0.082 + vars->minimap_scale;
	y = vars->win_height * 0.825 + vars->minimap_scale;
	if (player_y < SIGHT_RANGE)
		y -= (SIGHT_RANGE - 1 - player_y) * vars->minimap_scale;
	if (player_x < SIGHT_RANGE)
		x -= (SIGHT_RANGE - 1 - player_x) * vars->minimap_scale;
	if (vars->player.angle >= 0.75 && vars->player.angle < 2.4)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->text.player_up.img,
			x, y);
	else if (vars->player.angle >= 2.4 && vars->player.angle < 3.9)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->text.player_left.img, x, y);
	else if (vars->player.angle >= 3.9 && vars->player.angle < 5.5)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->text.player_down.img, x, y);
	else if (vars->player.angle >= 5.5 || vars->player.angle < 0.75)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->text.player_right.img, x, y);
}

int	put_gunsight(t_vars *vars, int x, int y)
{
	draw_square(vars, x, y);
	draw_square(vars, x - 2, y + 2);
	draw_square(vars, x - 4, y + 4);
	draw_square(vars, x - 6, y + 6);
	draw_square(vars, x + 2, y + 2);
	draw_square(vars, x + 4, y + 4);
	draw_square(vars, x + 6, y + 6);
	return (0);
}

void	draw_square(t_vars *vars, int x, int y)
{
	int	y_tmp;
	int	x_tmp;
	int	offset;

	offset = 2;
	y_tmp = y - offset;
	x_tmp = x - offset;
	while (y_tmp < (y + offset))
	{
		while (x_tmp < (x + offset))
		{
			my_mlx_pixel_put(vars, x_tmp, y_tmp, 0xfbff05);
			x_tmp++;
		}
		x_tmp = x - offset;
		y_tmp++;
	}
}
