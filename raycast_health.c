#include "cub3d.h"
#include "raycast.h"

int	health(t_vars *vars)
{
	int	actual_x_player;
	int	actual_y_player;

	actual_x_player = (vars->player.x / TILE_SIZE);
	actual_y_player = (vars->player.y / TILE_SIZE);
	if (vars->map[actual_y_player][actual_x_player] == '2'
		&& vars->player_health > 0)
	{
		vars->player_health -= 1;
	}
	health_putter(vars);
	return (0);
}

int	health_checker(t_vars *vars)
{
	if (vars->player_health == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->text.end.img, 0,
			0);
		mlx_mouse_show(vars->mlx, vars->win);
		return (1);
	}
	return (0);
}

int	health_putter(t_vars *vars)
{
	int	health;

	health = vars->player_health * 3.2;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->text.health.img, WIN_WIDTH * 0.390625,
		WIN_HEIGHT * 0.9375);
	while (health > 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->text.health_bar.img,
			WIN_WIDTH * 0.39609375 + health -1, WIN_HEIGHT * 0.94625);
		health--;
	}
	return (0);
}
