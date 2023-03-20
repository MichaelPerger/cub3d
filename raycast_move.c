#include "raycast.h"

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 98)
		vars->bonus_toggle = !vars->bonus_toggle;
	if (keycode == EXIT)
	{
		free_all_ray(vars);
		exit(0);
	}
	if (keycode == FORWARD)
		vars->move_key = 1;
	if (keycode == RIGHT)
		vars->move_key = 2;
	if (keycode == BACK)
		vars->move_key = 3;
	if (keycode == LEFT)
		vars->move_key = 4;
	if (keycode == ROT_LEFT)
		vars->turn_key = 1;
	if (keycode == ROT_RIGHT)
		vars->turn_key = -1;
	if (keycode == 114 && vars->bonus_toggle == 1)
	{
		vars->end = 1;
		mlx_loop_end(vars->mlx);
	}
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == FORWARD)
		vars->move_key = 0;
	if (keycode == RIGHT)
		vars->move_key = 0;
	if (keycode == BACK)
		vars->move_key = 0;
	if (keycode == LEFT)
		vars->move_key = 0;
	if (keycode == ROT_LEFT)
		vars->turn_key = 0;
	if (keycode == ROT_RIGHT)
		vars->turn_key = 0;
	return (0);
}

int	player_move(t_vars *vars)
{
	float	x;
	float	y;

	x = vars->player.x;
	y = vars->player.y;
	vars->player.angle = within_twopi(vars->player.angle + vars->turn_key
			* vars->rot_speed);
	x = new_x(x, vars);
	y = new_y(y, vars);
	if (is_maplimit(x, y, vars) || not_valid_step(x, y, vars))
		return (1);
	vars->player.x = x;
	vars->player.y = y;
	return (0);
}

float	new_x(float x, t_vars *vars)
{
	float	tmp;
	float	angle;

	tmp = vars->player.x;
	angle = vars->player.angle;
	if (vars->move_key == 1)
		x = tmp + cos(angle) * vars->move_speed;
	else if (vars->move_key == 3)
		x = tmp - cos(angle) * vars->move_speed;
	else if (vars->move_key == 2)
		x = tmp + cos(within_twopi(angle + (M_PI / 2))) * vars->move_speed;
	else if (vars->move_key == 4)
		x = tmp - cos(within_twopi(angle + (M_PI / 2))) * vars->move_speed;
	return (x);
}

float	new_y(float y, t_vars *vars)
{
	float	tmp;
	float	angle;

	tmp = vars->player.y;
	angle = vars->player.angle;
	if (vars->move_key == 1)
		y = tmp - sin(angle) * vars->move_speed;
	else if (vars->move_key == 3)
		y = tmp + sin(angle) * vars->move_speed;
	else if (vars->move_key == 2)
		y = tmp - sin(within_twopi(angle + (M_PI / 2))) * vars->move_speed;
	else if (vars->move_key == 4)
		y = tmp + sin(within_twopi(angle + (M_PI / 2))) * vars->move_speed;
	return (y);
}
