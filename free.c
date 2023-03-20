#include "cub3d.h"
#include "raycast.h"

void	free_all(t_map *map)
{
	free(map->north);
	free(map->south);
	free(map->west);
	free(map->east);
	free_array(map->map);
	if (map->fd_textures[0] != -1)
		close(map->fd_textures[0]);
	if (map->fd_textures[1] != -1)
		close(map->fd_textures[1]);
	if (map->fd_textures[2] != -1)
		close(map->fd_textures[2]);
	if (map->fd_textures[3] != -1)
		close(map->fd_textures[3]);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_raycast(t_vars *vars)
{
	free(vars->rays);
	if (vars->text.east.img)
		mlx_destroy_image(vars->mlx, vars->text.east.img);
	if (vars->text.north.img)
		mlx_destroy_image(vars->mlx, vars->text.north.img);
	if (vars->text.west.img)
		mlx_destroy_image(vars->mlx, vars->text.west.img);
	if (vars->text.south.img)
		mlx_destroy_image(vars->mlx, vars->text.south.img);
	if (vars->game.img)
		mlx_destroy_image(vars->mlx, vars->game.img);
	if (vars->text.minimap_wall.img)
		mlx_destroy_image(vars->mlx, vars->text.minimap_wall.img);
	if (vars->text.minimap_floor.img)
		mlx_destroy_image(vars->mlx, vars->text.minimap_floor.img);
	if (vars->text.player_up.img)
		mlx_destroy_image(vars->mlx, vars->text.player_up.img);
	if (vars->text.player_down.img)
		mlx_destroy_image(vars->mlx, vars->text.player_down.img);
	if (vars->text.player_left.img)
		mlx_destroy_image(vars->mlx, vars->text.player_left.img);
	if (vars->text.player_right.img)
		mlx_destroy_image(vars->mlx, vars->text.player_right.img);
	if (vars->text.sprite.img)
		mlx_destroy_image(vars->mlx, vars->text.sprite.img);
}

void	free_raycast2(t_vars *vars)
{
	if (vars->text.sprite_map.img)
		mlx_destroy_image(vars->mlx, vars->text.sprite_map.img);
	if (vars->text.health.img)
		mlx_destroy_image(vars->mlx, vars->text.health.img);
	if (vars->text.health_bar.img)
		mlx_destroy_image(vars->mlx, vars->text.health_bar.img);
	if (vars->text.end.img)
		mlx_destroy_image(vars->mlx, vars->text.end.img);
	if (vars->text.win.img)
		mlx_destroy_image(vars->mlx, vars->text.win.img);
	if (vars->text.sprite2.img)
		mlx_destroy_image(vars->mlx, vars->text.sprite2.img);
	if (vars->text.sprite3.img)
		mlx_destroy_image(vars->mlx, vars->text.sprite3.img);
	if (vars->text.sprite4.img)
		mlx_destroy_image(vars->mlx, vars->text.sprite4.img);
}

void	free_all_ray(t_vars *vars)
{
	free_map_struct(vars);
	free_raycast(vars);
	free_raycast2(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->sprites);
	free(vars->mlx);
	vars->mlx = NULL;
}
