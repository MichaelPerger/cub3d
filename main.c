#include "cub3d.h"
#include "raycast.h"

int	go_again(t_map *map, char **av)
{
	init_all(map);
	parse_input(av[1], map);
	parse_map(av[1], map);
	check_map_validity(map);
	check_input_validity(map);
	check_input_validity2(map);
	return (0);
}

int	input_check(t_map *map, char **av)
{
	if (parse_input(av[1], map) == 1)
		return (1);
	if (parse_map(av[1], map) == 1)
		return (2);
	if (check_map_validity(map) == 1)
		return (3);
	if (check_input_validity(map) == 1)
		return (4);
	if (check_input_validity2(map) == 1)
		return (5);
	return (0);
}

int cub_check(char *file)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(file);
	if (len < 5)
		return (1);
	while (file[i] != '.')
		i++;
	if (ft_strncmp(&file[i], ".cub\0", 5) != 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2 || cub_check(av[1]) != 0)
	{
		printf("Usage: ./cub3d map_of_your_choice.cub\n");
		return (1);
	}
	init_all(&map);
	if (input_check(&map, av) != 0)
	{
		free_all(&map);
		return (1);
	}
	while (raycaster(&map) == 1)
		go_again(&map, av);
	return (0);
}
