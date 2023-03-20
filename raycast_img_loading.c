#include "cub3d.h"
#include "raycast.h"

int	text_loading(t_vars *vars)
{
	if (load_wall_textures(vars) != 0 || load_other_textures(vars) != 0
		|| load_more_textures(vars) != 0 || load_even_more_texture(vars) != 0)
	{
		free_all_ray(vars);
		return (1);
	}
	return (0);
}

int	load_wall_textures(t_vars *m)
{
	m->text.north.img = mlx_xpm_file_to_image(m->mlx, m->north,
			&m->text.north.width, &m->text.north.height);
	m->text.east.img = mlx_xpm_file_to_image(m->mlx, m->east,
			&m->text.east.width, &m->text.east.height);
	m->text.south.img = mlx_xpm_file_to_image(m->mlx, m->south,
			&m->text.south.width, &m->text.south.height);
	m->text.west.img = mlx_xpm_file_to_image(m->mlx, m->west,
			&m->text.west.width, &m->text.west.height);
	if (!m->text.north.img || !m->text.east.img || !m->text.south.img
		|| !m->text.west.img)
		return (ft_printf("Error\nCouldn't load all wall-image files\n"));
	m->text.north.addr = mlx_get_data_addr(m->text.north.img,
			&m->text.north.bpp, &m->text.north.line_len,
			&m->text.north.endian);
	m->text.east.addr = mlx_get_data_addr(m->text.east.img, &m->text.east.bpp,
			&m->text.east.line_len, &m->text.east.endian);
	m->text.south.addr = mlx_get_data_addr(m->text.south.img,
			&m->text.south.bpp, &m->text.south.line_len,
			&m->text.south.endian);
	m->text.west.addr = mlx_get_data_addr(m->text.west.img, &m->text.west.bpp,
			&m->text.west.line_len, &m->text.west.endian);
	return (0);
}

int	load_other_textures(t_vars *vars)
{
	vars->text.sprite.img = mlx_xpm_file_to_image(vars->mlx, SPRITE,
			&vars->text.sprite.width, &vars->text.sprite.height);
	vars->text.minimap_wall.img = mlx_xpm_file_to_image(vars->mlx, MINIMAP_WALL,
			&vars->text.minimap_wall.width, &vars->text.minimap_wall.height);
	vars->text.minimap_floor.img = mlx_xpm_file_to_image(vars->mlx,
			MINIMAP_FLOOR, &vars->text.minimap_floor.width,
			&vars->text.minimap_floor.height);
	vars->text.player_up.img = mlx_xpm_file_to_image(vars->mlx, PLAYER_UP,
			&vars->text.player_up.width, &vars->text.player_up.height);
	vars->text.player_down.img = mlx_xpm_file_to_image(vars->mlx, PLAYER_DOWN,
			&vars->text.player_down.width, &vars->text.player_down.height);
	vars->text.player_left.img = mlx_xpm_file_to_image(vars->mlx, PLAYER_LEFT,
			&vars->text.player_left.width, &vars->text.player_left.height);
	vars->text.player_right.img = mlx_xpm_file_to_image(vars->mlx, PLAYER_RIGHT,
			&vars->text.player_right.width, &vars->text.player_right.height);
	if (!vars->text.minimap_wall.img || !vars->text.minimap_floor.img
		|| !vars->text.player_up.img || !vars->text.player_down.img
		|| !vars->text.player_left.img || !vars->text.player_right.img
		|| !vars->text.sprite.img)
		return (ft_printf("Error\nCouldn't load all additional image files\n"));
	vars->text.sprite.addr = mlx_get_data_addr(vars->text.sprite.img,
			&vars->text.sprite.bpp, &vars->text.sprite.line_len,
			&vars->text.sprite.endian);
	return (0);
}

int	load_more_textures(t_vars *vars)
{
	vars->text.sprite_map.img = mlx_xpm_file_to_image(vars->mlx, SPRITE_MAP,
			&vars->text.sprite_map.width, &vars->text.sprite_map.height);
	vars->text.health.img = mlx_xpm_file_to_image(vars->mlx, HEALTH_TEX,
			&vars->text.health.width, &vars->text.health.height);
	vars->text.health_bar.img = mlx_xpm_file_to_image(vars->mlx, HEALTH_BAR,
			&vars->text.health_bar.width, &vars->text.health_bar.height);
	vars->text.end.img = mlx_xpm_file_to_image(vars->mlx, END,
			&vars->text.end.width, &vars->text.end.height);
	vars->text.win.img = mlx_xpm_file_to_image(vars->mlx, WIN,
			&vars->text.win.width, &vars->text.win.height);
	vars->text.sprite2.img = mlx_xpm_file_to_image(vars->mlx, SPRITE2,
			&vars->text.sprite2.width, &vars->text.sprite2.height);
	vars->text.sprite3.img = mlx_xpm_file_to_image(vars->mlx, SPRITE3,
			&vars->text.sprite3.width, &vars->text.sprite3.height);
	vars->text.sprite4.img = mlx_xpm_file_to_image(vars->mlx, SPRITE4,
			&vars->text.sprite4.width, &vars->text.sprite4.height);
	if (!vars->text.sprite_map.img || !vars->text.health.img
		|| !vars->text.health_bar.img || !vars->text.end.img
		|| !vars->text.sprite2.img || !vars->text.sprite3.img
		|| !vars->text.sprite4.img || !vars->text.win.img)
		return (ft_printf("Error\nCouldn't load all additional image files\n"));
	return (0);
}

int	load_even_more_texture(t_vars *vars)
{
	vars->text.sprite2.addr = mlx_get_data_addr(vars->text.sprite2.img,
			&vars->text.sprite2.bpp, &vars->text.sprite2.line_len,
			&vars->text.sprite2.endian);
	vars->text.sprite3.addr = mlx_get_data_addr(vars->text.sprite3.img,
			&vars->text.sprite3.bpp, &vars->text.sprite3.line_len,
			&vars->text.sprite3.endian);
	vars->text.sprite4.addr = mlx_get_data_addr(vars->text.sprite4.img,
			&vars->text.sprite4.bpp, &vars->text.sprite4.line_len,
			&vars->text.sprite4.endian);
	return (0);
}
