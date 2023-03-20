/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperger <mperger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:08:11 by mkoller           #+#    #+#             */
/*   Updated: 2023/03/08 10:20:06 by mperger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_input(char *file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nMap file path is invalid\n");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		check_input(line, map);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (0);
}

void	check_input(char *line, t_map *map)
{
	char	**split;

	split = ft_split_improved(line, ' ', ',');
	if (check_chars(split, map) != 0)
		return;
	if (split && ft_strncmp(split[0], "NO", 2) == 0 && split[1] && !split[2])
	{
		map->north = fill_texture(split[1]);
		map->no_count++;
	}
	else if (split && ft_strncmp(split[0], "SO", 2) == 0 && split[1]
		&& !split[2])
	{
		map->south = fill_texture(split[1]);
		map->so_count++;
	}
	else if (split && ft_strncmp(split[0], "WE", 2) == 0 && split[1]
		&& !split[2])
	{
		map->west = fill_texture(split[1]);
		map->we_count++;
	}
	else
		check_input_norm(line, map, split);
	free_array(split);
}

void	rgb_to_int(char **color, int *rgb)
{
	char	*last_minus_newline;
	char	*tmp;

	tmp = NULL;
	if (color[0] && color[1] && color[2] && color[3] && color[4] == NULL)
	{
		last_minus_newline = cut_last_newline(color[3]);
		benes_idea(tmp, color, rgb, 1);
		benes_idea(tmp, color, rgb, 2);
		if (last_minus_newline)
		{
			tmp = ft_itoa(ft_atoi(last_minus_newline));
			if (last_minus_newline && ft_strncmp(tmp, last_minus_newline,
					3) == 0)
				rgb[2] = ft_atoi(color[3]);
			free(tmp);
		}
		free(last_minus_newline);
	}
}

void	map_dimensions(char *line, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line && line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0'
			&& line[i] != '\n' && line[i] != '\t' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != '2')
			map->valid_map = 1;
		if (line[i] == ' ' || line[i] == '1' || line[i] == '0')
			j++;
		else if (line[i] == '\t')
			j += 4;
		i++;
	}
	if (j > map->map_width)
		map->map_width = j;
	if (j > 0)
		map->map_height++;
}

char	*cut_last_newline(char *str)
{
	int		i;
	char	*new;

	i = 0;
	new = NULL;
	while (str && str[i] != '\n' && str[i] != '\0')
		i++;
	if (i > 0)
	{
		new = (char *)malloc(sizeof(char) * (i + 1));
		if (!new)
			return (NULL);
		ft_strlcpy(new, str, i + 1);
	}
	return (new);
}
