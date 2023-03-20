#include "cub3d.h"

void	benes_idea(char *tmp, char **split, int *rgb, int i)
{
	tmp = ft_itoa(ft_atoi(split[i]));
	if (ft_strncmp(tmp, split[i], 3) == 0)
		rgb[i - 1] = ft_atoi(split[i]);
	free(tmp);
}

int	parse_map(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	map->map = ft_calloc(map->map_height + 1, sizeof(char *));
	line = get_next_line(fd);
	while (line)
	{
		if ((i > 0 && line[0] == '\n') || (ft_strcmp(line, "N\n") == 0
				|| ft_strcmp(line, "S\n") == 0 || ft_strcmp(line, "W\n") == 0
				|| ft_strcmp(line, "E\n") == 0))
			map->valid_map = 1;
		if (line && (line[0] == ' ' || line[0] == '\t' || line[0] == '1'
				|| line[0] == '0'))
			map->map[i++] = copy_into_array(line, map);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (0);
}

char	*copy_into_array(char *line, t_map *map)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = -1;
	new = NULL;
	new = copy_into_array_actual_part(line, map, &i, &j);
	while (j < map->map_width)
	{
		new[j] = REPLACE;
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*copy_into_array_actual_part(char *line, t_map *map, int *i, int *j)
{
	char	*new;

	new = ft_calloc(map->map_width + 1, sizeof(char));
	while (++(*j) < map->map_width)
	{
		if (line[*i] == ' ')
			new[*j] = REPLACE;
		else if (line[*i] == '\t')
			i_love_norm(new, j);
		else if (line[*i] == '1' || line[*i] == '0' || line[*i] == '2'
			|| line[*i] == 'N' || line[*i] == 'S'
			|| line[*i] == 'E' || line[*i] == 'W')
			new[*j] = line[*i];
		else if (line[*i] == '\n' || line[*i] == '\0')
		{
			new[*j] = REPLACE;
			break ;
		}
		(*i)++;
	}
	return (new);
}

char	*fill_texture(char *line)
{
	char	*new;
	char	*no_new_line;

	new = ft_strdup(line);
	no_new_line = cut_last_newline(new);
	free(new);
	return (no_new_line);
}
