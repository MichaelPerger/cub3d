#include "cub3d.h"

//get start position
int	check_map_validity(t_map *map)
{
	int	i;
	int	test;
	int	check;

	i = 0;
	test = 0;
	check = 0;
	while (map->map && map->map[i])
	{
		test = empty_line_check(map, i);
		if (test == 1)
			map->valid_map = 1;
		only_one_start(map, i);
		test = row_space_check(map, i, &check);
		if (test == 1)
			map->valid_map = 1;
		i++;
	}
	return (0);
}

int	row_space_check(t_map *map, int i, int *check)
{
	int	j;

	j = 0;
	while (map->map && map->map[i][j])
	{
		if (map->map[i][j] == REPLACE)
		{
			if (i == 0)
				*check = first_row(map, i, j);
			else if (i > 0 && i < map->map_height - 1)
				*check = middle_rows(map, i, j);
			else if (i == map->map_height - 1)
				*check = last_row(map, i, j);
		}
		else if (i == 0 && (map->map[i][j] != '1' && map->map[i][j] != REPLACE))
			return (1);
		else if (i == map->map_height - 1 && (map->map[i][j] != '1'
			&& map->map[i][j] != REPLACE))
			return (1);
		if (*check == 1)
			return (1);
		j++;
	}
	return (0);
}

int	first_row(t_map *map, int i, int j)
{
	if (map->map[i][j + 1] && (map->map[i][j + 1] != REPLACE && map->map[i][j
			+ 1] != '1'))
		return (1);
	if (map->map[i][j + 1] && (map->map[i + 1][j] != REPLACE && map->map[i
			+ 1][j] != '1'))
		return (1);
	if (j != 0 && (map->map[i][j + 1] && map->map[i][j - 1] != REPLACE
			&& map->map[i][j - 1] != '1'))
		return (1);
	return (0);
}

int	middle_rows(t_map *map, int i, int j)
{
	if (map->map[i][j + 1] && (map->map[i][j + 1] != REPLACE && map->map[i][j
			+ 1] != '1'))
		return (1);
	if (map->map[i + 1][j] && (map->map[i + 1][j] != REPLACE && map->map[i
			+ 1][j] != '1'))
		return (1);
	if (map->map[i - 1][j] && map->map[i - 1][j] != REPLACE && map->map[i
		- 1][j] != '1')
		return (1);
	if (j != 0 && (map->map[i][j - 1] != REPLACE && map->map[i][j - 1] != '1'))
		return (1);
	return (0);
}

int	last_row(t_map *map, int i, int j)
{
	if (map->map[i][j + 1] && (map->map[i][j + 1] != REPLACE && map->map[i][j
			+ 1] != '1'))
		return (1);
	if (map->map[i - 1][j] && (map->map[i - 1][j] != REPLACE && map->map[i
			- 1][j] != '1'))
		return (1);
	if (j != 0 && (map->map[i][j - 1] != REPLACE && map->map[i][j - 1] != '1'))
		return (1);
	return (0);
}
