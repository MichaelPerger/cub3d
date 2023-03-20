#include "cub3d.h"
#include "raycast.h"

typedef struct s_index
{
	int	i;
	int	j;
	int	random;
	int	count;
}		t_index;

int	sprite_count(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map[i])
	{
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == '2' || vars->map[i][j] == '3')
				vars->sprite_count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	init_sprite_inner(int i, int j, t_vars *vars, int count)
{
	if (vars->map[i][j] == '2' || vars->map[i][j] == '3')
	{
		vars->sprites[count].x = j * TILE_SIZE + (TILE_SIZE / 2);
		vars->sprites[count].y = i * TILE_SIZE + (TILE_SIZE / 2);
		count++;
	}
	if (vars->map[i][j] == '2')
		vars->sprites[count - 1].type = 2;
	else if (vars->map[i][j] == '3')
		vars->sprites[count - 1].type = 3;
	return (count);
}

int	init_sprite(t_vars *vars)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	vars->sprites = malloc(sizeof(t_sprite) * vars->sprite_count);
	if (vars->sprites == NULL)
		return (1);
	while (vars->map[i] && count < vars->sprite_count)
	{
		j = 0;
		while (vars->map[i][j])
		{
			count = init_sprite_inner(i, j, vars, count);
			j++;
		}
		i++;
	}
	return (0);
}

void	choose_good_guy(t_vars *vars)
{
	t_index	index;

	index.i = 0;
	index.j = 0;
	index.count = 0;
	srand(time(NULL));
	index.random = rand() % vars->sprite_count;
	while (vars->map[index.i])
	{
		index.j = 0;
		while (vars->map[index.i][index.j])
		{
			if (vars->map[index.i][index.j] == '2')
			{
				if (index.count == index.random)
				{
					vars->sprites[index.count].type = 3;
					vars->map[index.i][index.j] = '3';
				}
				index.count++;
			}
			index.j++;
		}
		index.i++;
	}
}
