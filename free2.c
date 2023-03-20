#include "cub3d.h"
#include "raycast.h"

void	free_map_struct(t_vars *vars)
{
	free_all(vars->map_struct);
	free_array(vars->map_copy);
}
