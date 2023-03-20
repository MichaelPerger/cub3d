#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define REPLACE ' '

typedef struct s_map
{
	char	**map;
	int		valid_map;
	int		map_width;
	int		map_height;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		fd_textures[4];
	int		floor[3];
	int		ceiling[3];
	int		player_x;
	int		player_y;
	char	player_dir;
	int		no_count;
	int		so_count;
	int		we_count;
	int		ea_count;
	int		f_count;
	int		c_count;
}			t_map;

// main.c
int			main(int ac, char **av);
int			cub_check(char *file);
int			input_check(t_map *map, char **av);
int			go_again(t_map *map, char **av);

// init.c
void		init_all(t_map *map);
void		init_more(t_map *map);

// free.c
void		free_all(t_map *map);
void		free_array(char **split);

// parse_input.c
int			parse_input(char *file, t_map *map);
void		check_input(char *line, t_map *map);
void		map_dimensions(char *line, t_map *map);
void		rgb_to_int(char **color, int *rgb);
char		*cut_last_newline(char *str);

//parse_input1.c
void		benes_idea(char *tmp, char **split, int *rgb, int i);
int			parse_map(char *file, t_map *map);
char		*copy_into_array(char *line, t_map *map);
char		*copy_into_array_actual_part(char *line, t_map *map, int *i,
				int *j);
char		*fill_texture(char *line);

// parse_input2.c
void		i_love_norm(char *new, int *j);
void		check_input_norm(char *line, t_map *map, char **split);
int			check_chars(char **split, t_map *map);

// check_validity.c
int			check_map_validity(t_map *map);
int			row_space_check(t_map *map, int i, int *check);
int			first_row(t_map *map, int i, int j);
int			middle_rows(t_map *map, int i, int j);
int			last_row(t_map *map, int i, int j);

// check_validity1.c
int			check_input_validity(t_map *map);
int			empty_line_check(t_map *map, int i);
int			only_one_start(t_map *map, int i);
int			access_textures_check(t_map *map);
void		get_player_dir(t_map *map, int i, int j);

// check_validity2.c
int			check_input_validity2(t_map *map);
#endif
