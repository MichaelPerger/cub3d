#include "cub3d.h"
#include "raycast.h"

int	win(t_vars *vars)
{
	int	actual_x_player;
	int	actual_y_player;

	actual_x_player = (vars->player.x / TILE_SIZE);
	actual_y_player = (vars->player.y / TILE_SIZE);
	if (vars->map[actual_y_player][actual_x_player] == '3')
	{
		you_won(vars);
		return (1);
	}
	return (0);
}

int	you_won(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->text.win.img, 0, 0);
	mlx_mouse_show(vars->mlx, vars->win);
	return (0);
}
