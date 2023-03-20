#include "cub3d.h"
#include "raycast.h"

typedef struct s_time_stuff
{
	double	current_time;
	double	elapsed_time;
	double	fps;
	char	*itoa;
}			t_time_stuff;

int	fps_putter(t_vars *vars)
{
	t_time_stuff	time_stuff;
	time_t			t;
	static int		frames;
	static double	time_now;
	static double	old_fps;

	time_stuff.current_time = time(&t);
	time_stuff.elapsed_time = time_stuff.current_time - time_now;
	frames++;
	mlx_string_put(vars->mlx, vars->win, 5, 795, 0x000000, "FPS:  ");
	if (time_stuff.elapsed_time >= 1.0)
	{
		time_stuff.fps = frames / time_stuff.elapsed_time;
		old_fps = time_stuff.fps;
		time_now = time_stuff.current_time;
		frames = 0;
	}
	time_stuff.itoa = ft_itoa(old_fps);
	mlx_string_put(vars->mlx, vars->win, 35, 795, 0x000000, time_stuff.itoa);
	free(time_stuff.itoa);
	return (0);
}

int	bonus_putter(t_vars *vars)
{
	static int	i = 0;
	static int	j = 0;

	if (vars->bonus_toggle == 1 && i < 600)
	{
		mlx_string_put(vars->mlx, vars->win, 30, 30, 0x000000, "BONUS: ");
		mlx_string_put(vars->mlx, vars->win, 70, 30, 0x000000, "ON");
		mlx_string_put(vars->mlx, vars->win, 30, 60, 0x000000,
			"ADDED: WALL COLLISION, SPRITES, MINI MAP, FPS");
		i++;
		j = 0;
	}
	if (vars->bonus_toggle == 0 && j < 600)
	{
		mlx_string_put(vars->mlx, vars->win, 30, 30, 0x000000, "BONUS:  ");
		mlx_string_put(vars->mlx, vars->win, 90, 30, 0x000000, "OFF");
		mlx_string_put(vars->mlx, vars->win, 30, 60, 0x000000,
			"PRESS B to toggle Bonus Mode");
		j++;
		i = 0;
	}
	return (0);
}
