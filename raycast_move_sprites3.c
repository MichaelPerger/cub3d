#include "cub3d.h"
#include "raycast.h"

void	up_down3(t_vars *vars, int i, int j, int *random)
{
	if (*random == 0)
	{
		if (vars->map[i + 1][j] == '0')
		{
			vars->map[i][j] = '0';
			vars->map[i + 1][j] = '3';
		}
		else
			(*random)++;
	}
	if (*random == 1)
	{
		if (vars->map[i - 1][j] == '0')
		{
			vars->map[i][j] = '0';
			vars->map[i - 1][j] = '3';
		}
		else
			(*random)++;
	}
	left_right3(vars, i, j, random);
}

void	left_right3(t_vars *vars, int i, int j, int *random)
{
	if (*random == 2)
	{
		if (vars->map[i][j + 1] == '0')
		{
			vars->map[i][j] = '0';
			vars->map[i][j + 1] = '3';
		}
		else
			(*random)++;
	}
	else if (*random == 3)
	{
		if (vars->map[i][j - 1] == '0')
		{
			vars->map[i][j] = '0';
			vars->map[i][j - 1] = '3';
		}
		else
		{
			*random = 0;
			up_down3(vars, i, j, random);
		}
	}
}

int	random_move_sprites3(t_vars *vars, int i, int j)
{
	int	random;

	random = rand() % 4;
	up_down3(vars, i, j, &random);
	return (0);
}
