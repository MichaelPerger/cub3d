#include "cub3d.h"
#include "raycast.h"

int	not_valid_step(float x, float y, t_vars *vars)
{
	if (vars->bonus_toggle == 1)
	{
		if (is_wall(x, y, vars) != 0)
			return (1);
		else
			return (0);
	}
	return (0);
}

void	calc_mouse_move(t_vars *vars)
{
	int	tmp;

	vars->old_mouse_x = vars->mouse_x;
	mlx_mouse_get_pos(vars->mlx, vars->win, &vars->mouse_x, &tmp);
	if (vars->mouse_x < 100)
		mlx_mouse_move(vars->mlx, vars->win, vars->win_width, vars->win_height);
	else if (vars->mouse_x > (vars->win_width - 100))
		mlx_mouse_move(vars->mlx, vars->win, vars->win_height / 2,
			vars->win_height / 2);
	if (vars->mouse_x < vars->win_width && tmp < vars->win_height)
	{
		if (vars->turn_key == 0)
		{
			if (vars->old_mouse_x > vars->mouse_x)
				vars->player.angle = within_twopi(vars->player.angle + 1
						* (vars->rot_speed + 0.01));
			else if (vars->old_mouse_x < vars->mouse_x)
				vars->player.angle = within_twopi(vars->player.angle + (-1)
						* (vars->rot_speed + 0.01));
		}
	}
}
