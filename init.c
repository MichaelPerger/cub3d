#include "cub3d.h"

void	init_all(t_map *map)
{
	map->map = NULL;
	map->valid_map = 0;
	map->map_width = 0;
	map->map_height = 0;
	map->north = NULL;
	map->south = NULL;
	map->west = NULL;
	map->east = NULL;
	map->fd_textures[0] = -1;
	map->fd_textures[1] = -1;
	map->fd_textures[2] = -1;
	map->fd_textures[3] = -1;
	map->floor[0] = -1;
	map->floor[1] = -1;
	map->floor[2] = -1;
	map->ceiling[0] = -1;
	map->ceiling[1] = -1;
	map->ceiling[2] = -1;
	map->player_x = -1;
	map->player_y = -1;
	map->player_dir = 0;
	init_more(map);
}

void	init_more(t_map *map)
{
	map->no_count = 0;
	map->so_count = 0;
	map->we_count = 0;
	map->ea_count = 0;
	map->f_count = 0;
	map->c_count = 0;
}
