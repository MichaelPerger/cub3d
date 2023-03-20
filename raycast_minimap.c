#include "cub3d.h"
#include "raycast.h"

typedef struct s_index
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	check;

}		t_index;

void	draw_pixel_square(t_vars *vars, int x, int y, int color)
{
	int	i;
	int	j;
	int	new_x;
	int	new_y;

	i = 0;
	while (i < vars->minimap_scale)
	{
		j = 0;
		while (j < vars->minimap_scale)
		{
			new_x = x + i;
			new_y = y + j;
			my_mlx_pixel_put(vars, new_x, new_y, color);
			j++;
		}
		i++;
	}
}

void	inner_loop(t_vars *vars, int player_x, int player_y, t_index *index)
{
	while (index->j < vars->max_col)
	{
		if (index->j > player_x - 5 && index->j < player_x + 5
			&& index->i > player_y - 5 && index->i < player_y + 5)
		{
			if (vars->map[index->i][index->j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->text.minimap_wall.img, index->x, index->y);
			if (vars->map[index->i][index->j] == '2'
				|| vars->map[index->i][index->j] == '3')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->text.sprite_map.img, index->x, index->y);
			else if (vars->map[index->i][index->j] == '0'
					|| vars->map[index->i][index->j] == 'N'
					|| vars->map[index->i][index->j] == 'S'
					|| vars->map[index->i][index->j] == 'E'
					|| vars->map[index->i][index->j] == 'W')
				draw_pixel_square(vars, index->x, index->y, 0x808080);
			index->x += vars->minimap_scale;
			index->check = 1;
		}
		index->j++;
	}
}

void	mini_map_around_player(t_vars *vars, int player_x, int player_y)
{
	t_index	index;

	index.i = 0;
	index.x = vars->win_width * 0.035 + vars->minimap_scale;
	index.y = vars->win_height * 0.75 + vars->minimap_scale;
	while (index.i < vars->max_row)
	{
		index.j = 0;
		index.check = 0;
		inner_loop(vars, player_x, player_y, &index);
		index.x = vars->win_width * 0.035 + vars->minimap_scale;
		if (index.check == 1)
			index.y += vars->minimap_scale;
		index.i++;
	}
}

void	mini_map(t_vars *vars)
{
	int	actual_x_player;
	int	actual_y_player;

	actual_x_player = (vars->player.x / TILE_SIZE);
	actual_y_player = (vars->player.y / TILE_SIZE);
	mini_map_around_player(vars, actual_x_player, actual_y_player);
	mini_map_player(vars, actual_x_player, actual_y_player);
}
