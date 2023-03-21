/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperger <mperger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:06:47 by mkoller           #+#    #+#             */
/*   Updated: 2023/03/21 15:05:41 by mperger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H
# include "cub3d.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# define FOV 90.0
# define TRUE 1
# define FALSE 0
# define TILE_SIZE 10.0
# define FORWARD 119
# define RIGHT 97
# define BACK 115
# define LEFT 100
# define EXIT 65307
# define BONUS 98
# define ROT_RIGHT 65363
# define ROT_LEFT 65361

# define WIN_HEIGHT 700
# define WIN_WIDTH 1366

# define SIGHT_RANGE 5
# define PLAYER_HEALTH 100
# define SPRITE_MOVE 60

# define MINIMAP_WALL "textures/minimap_wall.xpm"
# define MINIMAP_FLOOR "textures/minimap_floor.xpm"
# define PLAYER_UP "textures/player_up.xpm"
# define PLAYER_DOWN "textures/player_down.xpm"
# define PLAYER_LEFT "textures/player_left.xpm"
# define PLAYER_RIGHT "textures/player_right.xpm"
# define SPRITE "textures/sprite.xpm"
# define SPRITE2 "textures/sprite2.xpm"
# define SPRITE3 "textures/sprite3.xpm"
# define SPRITE4 "textures/sprite4.xpm"
# define SPRITE_MAP "textures/sprite_map.xpm"
# define HEALTH_TEX "textures/health.xpm"
# define HEALTH_BAR "textures/healthbar.xpm"
# define END "textures/end.xpm"
# define WIN "textures/win.xpm"

typedef struct s_inter
{
	float		x_step;
	float		y_step;
	float		x_inter;
	float		y_inter;
	float		next_x;
	float		next_y;
	float		wallhitx;
	float		wallhity;
	float		distance;
}				t_inter;

typedef struct s_rays
{
	float		angle;
	float		wallhitx;
	float		wallhity;
	float		distance;
	float		wallheight;
	float		wall_start;
	float		wall_end;
	float		fixed_dist;
	int			hitisvertical;
	int			rayisup;
	int			rayisdown;
	int			rayisleft;
	int			rayisright;
}				t_rays;

typedef struct s_perso
{
	float		x;
	float		y;
	float		angle;
}				t_perso;

typedef struct s_img
{
	void		*img;
	void		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_text
{
	t_img		north;
	t_img		south;
	t_img		west;
	t_img		east;
	t_img		minimap_wall;
	t_img		minimap_floor;
	t_img		player_up;
	t_img		player_down;
	t_img		player_left;
	t_img		player_right;
	t_img		sprite;
	t_img		sprite2;
	t_img		sprite3;
	t_img		sprite4;
	t_img		sprite_map;
	t_img		health;
	t_img		health_bar;
	t_img		end;
	t_img		win;
}				t_text;

typedef struct s_sprite
{
	float		x;
	float		y;
	float		angle;
	float		top_y;
	float		bottom_y;
	float		left_x;
	float		right_x;
	float		dist;
	float		height;
	float		width;
	int			type;

}				t_sprite;

typedef struct s_vars
{
	int			bonus_toggle;
	t_img		game;
	t_perso		player;
	t_rays		*rays;
	t_text		text;
	t_map		*map_struct;
	t_sprite	*sprites;
	float		tile_height;
	float		tile_width;
	float		move_speed;
	float		rot_speed;
	int			bmp_save;
	int			ceil_color;
	int			floor_color;
	int			ray_num;
	int			win_height;
	int			win_width;
	char		**map;
	char		**map_copy;
	int			max_row;
	int			max_col;
	void		*mlx;
	void		*win;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	float		x_text;
	int			move_key;
	int			turn_key;
	int			minimap_scale;
	int			mouse_x;
	int			old_mouse_x;
	int			sprite_count;
	int			player_health;
	int			random_enemy;
	int			end;
}				t_vars;

// raycast_init.c
int				initial_game_val(t_vars *vars, t_map *map);
void			perso_init(t_vars *vars, char player_dir);
void			map_init(t_vars *vars, t_map *map);
void			init_img(t_vars *m);

// raycast_limits.c
int				is_wall(float x, float y, t_vars *vars);
int				is_maplimit(float x, float y, t_vars *vars);
void			find_vert_wallhit(t_vars *vars, t_rays *ray, t_inter *vert);
void			find_horz_wallhit(t_vars *vars, t_rays *ray, t_inter *horz);

// raycast_maths.c
float			radconvert(float degree);
float			within_twopi(float rad);
float			get_distance(float x1, float y1, float x2, float y2);
unsigned int	create_rgb(int r, int g, int b);

// raycast_move.c
int				key_press(int keycode, t_vars *vars);
int				key_release(int keycode, t_vars *vars);
int				player_move(t_vars *vars);
float			new_x(float x, t_vars *vars);
float			new_y(float y, t_vars *vars);

//raycast_wall_collision.c
int				not_valid_step(float x, float y, t_vars *vars);
void			calc_mouse_move(t_vars *vars);

// raycast.c
int				raycaster(t_map *map);
int				update_screen(t_vars *vars);
void			cast_all_rays(t_vars *vars);
float			get_x_text(t_vars *vars, t_rays ray);
void			render_walls(t_vars *vars, t_rays ray, int x);

// raycast_set.c
void			set_rayprojection_val(t_rays *ray, float screen_dist,
					t_vars *vars);
void			set_ray_wallhit(t_rays *ray, t_vars *vars);
void			set_vert_hit(t_inter *vert, t_vars *vars, t_rays *ray);
void			set_horz_hit(t_inter *horz, t_vars *vars, t_rays *ray);
void			set_ray_angle(t_rays *ray, float ray_angle);

// raycast_pixel.c
void			my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void			xpm_wall_pixel_put(t_vars *vars, t_rays ray, int x, int *y);
unsigned int	color_geter(t_vars *vars, t_rays *ray, int y_text);
int				get_image_pixel(t_img *text, int x, int y);

// raycast_img_loading.c
int				text_loading(t_vars *vars);
int				load_wall_textures(t_vars *m);
int				load_other_textures(t_vars *vars);
int				load_more_textures(t_vars *vars);
int				load_even_more_texture(t_vars *vars);

// raycast_minimap.c
void			mini_map(t_vars *vars);
void			draw_pixel_square(t_vars *vars, int x, int y, int color);
void			mini_map_around_player(t_vars *vars, int player_x,
					int player_y);

// raycast_minimap_player.c
void			mini_map_player(t_vars *vars, int player_x, int player_y);
void			draw_square(t_vars *vars, int x, int y);
int				put_gunsight(t_vars *vars, int x, int y);

// free
void			free_raycast(t_vars *vars);
void			free_raycast2(t_vars *vars);
void			free_all_ray(t_vars *vars);

// free2.c
void			free_map_struct(t_vars *vars);

//raycast_sprite.c
int				sprite_count(t_vars *vars);
int				init_sprite(t_vars *vars);
int				init_sprite_inner(int i, int j, t_vars *vars, int count);
void			choose_good_guy(t_vars *vars);

// raycast_sprite2.c
int				render_sprites(t_vars *vars, t_sprite *sprite);
void			draw_sprite(t_vars *vars, t_sprite *sprite, int x_offset,
					int y_offset);
int				cast_sprites(t_vars *vars);

// raycast_sprite_special.c
void			draw_sprite_special(t_vars *vars, t_sprite *sprite,
					int x_offset, int y_offset);
int				sprite_color_geter_special(t_vars *vars, t_sprite *sprite,
					int x, int y);

// raycast_fps.c
int				fps_putter(t_vars *vars);
int				bonus_putter(t_vars *vars);

// raycast_health.c
int				health(t_vars *vars);
int				health_putter(t_vars *vars);
int				health_checker(t_vars *vars);

// raycast_utils.c
char			**copy_map(t_vars *vars, char **src);

// raycast_move_sprites.c
int				move_sprites(t_vars *vars);
int				map_changer(t_vars *vars);
int				random_move_sprites(t_vars *vars, int i, int j);
void			up_down(t_vars *vars, int i, int j, int *random);
void			left_right(t_vars *vars, int i, int j, int *random);

// raycast_move_sprites3.c
int				random_move_sprites3(t_vars *vars, int i, int j);
void			up_down3(t_vars *vars, int i, int j, int *random);
void			left_right3(t_vars *vars, int i, int j, int *random);

// raycast_win.c
int				win(t_vars *vars);
int				you_won(t_vars *vars);

//raycast_sort
int				sprite_wrapper(t_vars *vars);
void			sort_sprites(t_vars *vars);
void			swap1(t_sprite *min_idx, t_sprite *i);
void			swap2(t_sprite *min_idx, t_sprite *i);

#endif