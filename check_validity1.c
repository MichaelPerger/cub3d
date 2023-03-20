#include "cub3d.h"

int	check_input_validity(t_map *map)
{
	if (map->north == NULL || map->south == NULL || map->west == NULL
		|| map->east == NULL)
	{
		printf("Error\nTexture path is invalid\n");
		return (1);
	}
	if (map->no_count > 1 || map->so_count > 1 || map->we_count > 1
		|| map->ea_count > 1 || map->f_count > 1 || map->c_count > 1)
	{
		printf("Error\nToo many arguments\n");
		return (1);
	}
	if (access_textures_check(map) == 1)
		return (1);
	if (map->floor[0] < 0 || map->floor[1] < 0 || map->floor[2] < 0
		|| map->floor[0] > 255 || map->floor[1] > 255 || map->floor[2] > 255)
	{
		printf("Error\nFloor color is invalid\n");
		return (1);
	}
	return (0);
}

int	access_textures_check(t_map *map)
{
	map->fd_textures[0] = open(map->north, O_RDONLY);
	map->fd_textures[1] = open(map->south, O_RDONLY);
	map->fd_textures[2] = open(map->west, O_RDONLY);
	map->fd_textures[3] = open(map->east, O_RDONLY);
	if (map->fd_textures[0] == -1 || map->fd_textures[1] == -1
		|| map->fd_textures[2] == -1 || map->fd_textures[3] == -1)
	{
		printf("Error\nTexture path is invalid\n");
		return (1);
	}
	return (0);
}

int	empty_line_check(t_map *map, int i)
{
	int	j;

	j = 0;
	while (map->map && map->map[i][j] == REPLACE)
		j++;
	if (j == map->map_width)
		return (1);
	else
		return (0);
}

int	only_one_start(t_map *map, int i)
{
	int			j;

	j = 0;
	while (map->map && map->map[i][j])
	{
		if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
			|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
		{
			get_player_dir(map, i, j);
			if (map->player_x != -1 || map->player_y != -1)
				map->valid_map = 1;
			else
			{
				map->player_x = j;
				map->player_y = i;
			}
		}
		j++;
	}
	return (0);
}

void	get_player_dir(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'N')
		map->player_dir = 'N';
	else if (map->map[i][j] == 'S')
		map->player_dir = 'S';
	else if (map->map[i][j] == 'E')
		map->player_dir = 'E';
	else if (map->map[i][j] == 'W')
		map->player_dir = 'W';
}
