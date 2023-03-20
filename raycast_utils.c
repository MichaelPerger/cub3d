#include "cub3d.h"
#include "raycast.h"

char	**copy_map(t_vars *vars, char **src)
{
	int		i;
	char	**dst;

	i = 0;
	if (!src)
		return (NULL);
	dst = malloc(sizeof(char *) * (vars->max_row + 1));
	if (!dst)
		return (NULL);
	while (i < vars->max_row)
	{
		dst[i] = ft_strdup(vars->map[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
