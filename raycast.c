#include "cub3d.h"
#include "raycast.h"

void	render_walls(t_vars *vars, t_rays ray, int x)
{
	int	y;

	y = 0;
	while (y < ray.wall_start)
	{
		my_mlx_pixel_put(vars, x, y, vars->ceil_color);
		y++;
	}
	xpm_wall_pixel_put(vars, ray, x, &y);
	while (y < vars->win_height)
	{
		my_mlx_pixel_put(vars, x, y, vars->floor_color);
		y++;
	}
}

float	get_x_text(t_vars *vars, t_rays ray)
{
	int	offset;

	if (ray.hitisvertical)
	{
		offset = ray.wallhity / TILE_SIZE;
		if (ray.rayisright)
			return ((float)((ray.wallhity - (offset * TILE_SIZE))
				* (vars->text.east.width / TILE_SIZE)));
		else
			return ((float)(((-ray.wallhity + ((offset + 1) * TILE_SIZE)))
				* (vars->text.west.width / TILE_SIZE)));
	}
	else
	{
		offset = ray.wallhitx / TILE_SIZE;
		if (ray.rayisup)
			return ((float)((ray.wallhitx - (offset * TILE_SIZE))
				* (vars->text.south.width / TILE_SIZE)));
		else
			return ((float)(((-ray.wallhitx + ((offset + 1) * TILE_SIZE)))
				* (vars->text.north.width / TILE_SIZE)));
	}
}

void	cast_all_rays(t_vars *vars)
{
	float	ray_angle;
	float	screen_dist;
	int		i;

	screen_dist = (vars->win_width / 2) / tan(radconvert(FOV / 2));
	i = 0;
	while (i < vars->ray_num)
	{
		vars->x_text = get_x_text(vars, vars->rays[i]);
		ray_angle = within_twopi(vars->player.angle + atan(((vars->ray_num / 2)
						- i) / screen_dist));
		set_ray_angle(vars->rays + i, ray_angle);
		set_ray_wallhit(vars->rays + i, vars);
		set_rayprojection_val(vars->rays + i, screen_dist, vars);
		render_walls(vars, vars->rays[i], i);
		i++;
	}
}

int	update_screen(t_vars *vars)
{
	if (health_checker(vars) == 1 || win(vars) == 1)
		return (1);
	cast_all_rays(vars);
	if (vars->bonus_toggle == 1)
	{
		mlx_mouse_hide(vars->mlx, vars->win);
		calc_mouse_move(vars);
		move_sprites(vars);
	}
	else
		mlx_mouse_show(vars->mlx, vars->win);
	put_gunsight(vars, vars->win_width / 2, vars->win_height / 2);
	player_move(vars);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->game.img, 0, 0);
	if (vars->bonus_toggle == 1)
	{
		mini_map(vars);
		health(vars);
		win(vars);
		fps_putter(vars);
	}
	bonus_putter(vars);
	return (0);
}

int	raycaster(t_map *map)
{
	t_vars	vars;

	initial_game_val(&vars, map);
	sprite_wrapper(&vars);
	vars.mlx = mlx_init();
	vars.game.img = mlx_new_image(vars.mlx, vars.win_width, vars.win_height);
	vars.win = mlx_new_window(vars.mlx, vars.win_width, vars.win_height,
			"Cube3d");
	vars.game.addr = mlx_get_data_addr(vars.game.img, &vars.game.bpp,
			&vars.game.line_len, &vars.game.endian);
	if (text_loading(&vars) == 1)
		return (1);
	mlx_loop_hook(vars.mlx, update_screen, &vars);
	mlx_hook(vars.win, 33, 0, mlx_loop_end, vars.mlx);
	mlx_hook(vars.win, 2, 1L, key_press, &vars);
	mlx_hook(vars.win, 3, 2L, key_release, &vars);
	mlx_loop(vars.mlx);
	if (vars.end == 1)
	{
		free_all_ray(&vars);
		return (1);
	}
	free_all_ray(&vars);
	return (0);
}
