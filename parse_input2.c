#include "cub3d.h"

void	i_love_norm(char *new, int *j)
{
	new[*j] = REPLACE;
	new[++(*j)] = REPLACE;
	new[++(*j)] = REPLACE;
	new[++(*j)] = REPLACE;
}

void	check_input_norm(char *line, t_map *map, char **split)
{
	if (split && ft_strncmp(split[0], "EA", 2) == 0 && split[1] && !split[2])
	{
		map->east = fill_texture(split[1]);
		map->ea_count++;
	}
	else if (split && ft_strncmp(split[0], "F", 1) == 0 && split[1])
	{
		rgb_to_int(split, map->floor);
		map->f_count++;
	}
	else if (split && ft_strncmp(split[0], "C", 1) == 0 && split[1])
	{
		rgb_to_int(split, map->ceiling);
		map->c_count++;
	}
	else if (split && (ft_strncmp(split[0], "NO", 2) != 0
			&& ft_strncmp(split[0], "SO", 2) != 0 && ft_strncmp(split[0],
				"WE", 2) != 0 && ft_strncmp(split[0], "EA", 2) != 0))
		map_dimensions(line, map);
}

int	check_chars(char **split, t_map *map)
{
	if (split && ft_strncmp(split[0], "NO\0", 3) != 0 && ft_strncmp(split[0],
			"SO\0", 3) != 0 && ft_strncmp(split[0], "WE\0", 3) != 0
		&& ft_strncmp(split[0], "EA\0", 3) != 0 && ft_strncmp(split[0], "F\0",
			2) != 0 && ft_strncmp(split[0], "C\0", 2) != 0 && ft_strncmp(split[0],
			"\t", 1) != 0 && ft_strncmp(split[0], " ", 1) != 0
		&& ft_strncmp(split[0], "1", 1) != 0 && ft_strncmp(split[0], "\n",
			1) != 0)
			{
				map->valid_map = 1;
				return (1);
			}
	return (0);
}
