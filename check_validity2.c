#include "cub3d.h"

int	check_input_validity2(t_map *map)
{
	if (map->ceiling[0] < 0 || map->ceiling[1] < 0 || map->ceiling[2] < 0
		|| map->ceiling[0] > 255 || map->ceiling[1] > 255
		|| map->ceiling[2] > 255)
	{
		printf("Error\nCeiling color is invalid\n");
		return (1);
	}
	if (map->map == NULL || map->map_height == 0 || map->map_width == 0
		|| map->valid_map == 1 || map->player_x == -1 || map->player_y == -1
		|| map->player_dir == 0)
	{
		printf("Error\nMap is invalid\n");
		return (1);
	}
	if (map->valid_map == 1)
		return (1);
	return (0);
}
