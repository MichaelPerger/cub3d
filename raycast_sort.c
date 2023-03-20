#include "cub3d.h"
#include "raycast.h"

void	swap2(t_sprite *min_idx, t_sprite *i)
{
	float	tmp;

	tmp = min_idx->left_x;
	min_idx->left_x = i->left_x;
	i->left_x = tmp;
	tmp = min_idx->right_x;
	min_idx->right_x = i->right_x;
	i->right_x = tmp;
	tmp = min_idx->dist;
	min_idx->dist = i->dist;
	i->dist = tmp;
	tmp = min_idx->height;
	min_idx->height = i->height;
	i->height = tmp;
	tmp = min_idx->width;
	min_idx->width = i->width;
	i->width = tmp;
}

void	swap1(t_sprite *min_idx, t_sprite *i)
{
	float	tmp;

	tmp = min_idx->x;
	min_idx->x = i->x;
	i->x = tmp;
	tmp = min_idx->y;
	min_idx->y = i->y;
	i->y = tmp;
	tmp = min_idx->angle;
	min_idx->angle = i->angle;
	i->angle = tmp;
	tmp = min_idx->top_y;
	min_idx->top_y = i->top_y;
	i->top_y = tmp;
	tmp = min_idx->bottom_y;
	min_idx->bottom_y = i->bottom_y;
	i->bottom_y = tmp;
	swap2(min_idx, i);
}

void	sort_sprites(t_vars *vars)
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	j = 0;
	min_idx = 0;
	while (i < vars->sprite_count - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < vars->sprite_count)
		{
			if (vars->sprites[j].dist > vars->sprites[min_idx].dist)
				min_idx = j;
			j++;
		}
		swap1(&vars->sprites[min_idx], &vars->sprites[i]);
		i++;
	}
}

int	sprite_wrapper(t_vars *vars)
{
	sprite_count(vars);
	init_sprite(vars);
	if (vars->sprite_count == 0)
		return (1);
	choose_good_guy(vars);
	return (0);
}
