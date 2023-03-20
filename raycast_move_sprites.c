#include "cub3d.h"
#include "raycast.h"

void	up_down(t_vars *vars, int i, int j, int *random)
{
	if (*random == 0)
	{
		if (vars->map[i + 1][j] == '0')
		{
			vars->map[i][j] = '0';
			vars->map[i + 1][j] = '2';
		}
		else
			(*random)++;
	}
	if (*random == 1)
	{
		if (vars->map[i - 1][j] == '0')
		{
			vars->map[i][j] = '0';
			vars->map[i - 1][j] = '2';
		}
		else
			(*random)++;
	}
	left_right(vars, i, j, random);
}

void	left_right(t_vars *vars, int i, int j, int *random)
{
	if (*random == 2)
	{
		if (vars->map[i][j + 1] == '0')
		{
			vars->map[i][j] = '0';
			vars->map[i][j + 1] = '2';
		}
		else
			(*random)++;
	}
	else if (*random == 3)
	{
		if (vars->map[i][j - 1] == '0')
		{
			vars->map[i][j] = '0';
			vars->map[i][j - 1] = '2';
		}
		else
		{
			*random = 0;
			up_down(vars, i, j, random);
		}
	}
}

int	random_move_sprites(t_vars *vars, int i, int j)
{
	int	random;

	random = rand() % 4;
	up_down(vars, i, j, &random);
	return (0);
}

int	map_changer(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	free_array(vars->map_copy);
	vars->map_copy = copy_map(vars, vars->map);
	while (i < vars->max_row)
	{
		j = 0;
		while (j < vars->max_col)
		{
			if (vars->map_copy[i][j] == '2')
				random_move_sprites(vars, i, j);
			else if (vars->map_copy[i][j] == '3')
				random_move_sprites3(vars, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	move_sprites(t_vars *vars)
{
	static int	i = 0;

	if (i == SPRITE_MOVE)
	{
		map_changer(vars);
		free(vars->sprites);
		init_sprite(vars);
		cast_sprites(vars);
		i = 0;
	}
	else
	{
		cast_sprites(vars);
		i++;
	}
	return (0);
}
