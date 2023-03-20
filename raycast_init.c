#include "cub3d.h"
#include "raycast.h"

int	initial_game_val(t_vars *vars, t_map *map)
{
	srand(time(NULL));
	vars->bonus_toggle = 0;
	vars->mlx = NULL;
	vars->win = NULL;
	vars->rays = NULL;
	vars->game.addr = NULL;
	vars->game.img = NULL;
	vars->win_height = WIN_HEIGHT;
	vars->win_width = WIN_WIDTH;
	vars->bmp_save = 1;
	vars->ceil_color = create_rgb(map->ceiling[0], map->ceiling[1],
			map->ceiling[2]);
	vars->floor_color = create_rgb(map->floor[0], map->floor[1], map->floor[2]);
	vars->player.x = map->player_x;
	vars->player.y = map->player_y;
	vars->ray_num = vars->win_width;
	vars->rays = ft_calloc(vars->win_width, sizeof(t_rays));
	vars->sprite_count = 0;
	vars->player_health = PLAYER_HEALTH;
	vars->random_enemy = rand() % 3;
	vars->end = 0;
	map_init(vars, map);
	perso_init(vars, map->player_dir);
	init_img(vars);
	return (0);
}

void	init_img(t_vars *m)
{
	m->text.north.img = NULL;
	m->text.south.img = NULL;
	m->text.east.img = NULL;
	m->text.west.img = NULL;
	m->text.minimap_wall.img = NULL;
	m->text.minimap_floor.img = NULL;
	m->text.player_up.img = NULL;
	m->text.player_down.img = NULL;
	m->text.player_left.img = NULL;
	m->text.player_right.img = NULL;
	m->text.sprite.img = NULL;
	m->text.sprite2.img = NULL;
	m->text.sprite3.img = NULL;
	m->text.sprite4.img = NULL;
	m->text.sprite_map.img = NULL;
	m->text.health.img = NULL;
	m->text.health_bar.img = NULL;
	m->text.end.img = NULL;
	m->text.win.img = NULL;
}

void	map_init(t_vars *vars, t_map *map)
{
	vars->map_struct = map;
	vars->max_row = map->map_height;
	vars->max_col = map->map_width;
	vars->map = map->map;
	vars->west = map->west;
	vars->north = map->north;
	vars->south = map->south;
	vars->east = map->east;
	vars->minimap_scale = 15;
	vars->map_copy = copy_map(vars, vars->map);
}

void	perso_init(t_vars *vars, char player_dir)
{
	float	angle;

	if (player_dir == 'N')
		angle = M_PI / 2 + 0.0;
	else if (player_dir == 'W')
		angle = M_PI + 0.0;
	else if (player_dir == 'S')
		angle = (3 * M_PI) / 2 + 0.0;
	else
		angle = 0.0;
	vars->player.angle = angle + 0.01;
	vars->player.x = TILE_SIZE * vars->player.x + TILE_SIZE / 2;
	vars->player.y = TILE_SIZE * vars->player.y + TILE_SIZE / 2;
	vars->move_speed = 0.5;
	vars->rot_speed = 1.8 * (M_PI / 180);
	vars->move_key = 0;
	vars->turn_key = 0;
	vars->mouse_x = 0;
	vars->old_mouse_x = 0;
}
