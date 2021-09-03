#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include "../libft/libft.h"
# include <mlx.h>

# include <stdio.h>

# define PI 3.14159265359

# define EXIT		53
# define ROT_LEFT	123
# define ROT_RIGHT	124
# define FORWARD	13
# define BACK		1
# define RIGHT		2
# define LEFT		0

# define MAP_MARGIN 10
# define GRID_UNIT_SIZE 15

# define HUD_HEIGHT 300

# define BLACK  0x000000
# define WHITE  0xFFFFFF
# define GREEN  0x00FF00
# define RED  0xFF0000
# define BLUE  0x3333ff
# define AZUR 0x0ae0f1
# define VIOLET 0xfa00e4

typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct s_key
{
	t_bool	forward;
	t_bool	back;
	t_bool	left;
	t_bool	right;
}			t_key;

typedef struct s_img
{
	void				*mlx_img;
	int					*addr;
	char				*addr_c;
	int					bpp;
	int					line_len;
	int					endian;
	int					width;
	int					height;
}			t_img;

typedef struct s_state
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;

	t_img	img;
	t_img	wall;
	t_img	floor;
	t_img	collectible;
	t_img	player;
	t_img	exit;
	t_img	foe;
	t_img	praticable;
	t_img	win_screen;
	t_img	gameover_screen;
	t_img	number_img[10];

	char	**map;
	int		map_width;
	int		map_height;

	t_bool	error;
	t_bool	valid_symbol;
	t_bool	player_occur;
	t_bool	collectible_occur;
	t_bool	exit_occur;
	t_bool	foe_occur;
	t_bool	closed_map;
	t_bool	rectangular_map;

	t_pos	player_coord;
	t_pos	foe_coord;
	t_pos	exit_coord;

	t_key	key;
	int		key_lock;

	int		player_up;
	int		player_right;
	char	player_dir;
	int		square_size;
	int		score;
	char	*str_score;
	int		step_n;

	int		timer;
	int		sprite_period;
	int		sprite_sens;

}				t_state;

int		quit(t_state *state, int error);
void	exit_process(t_state *state, int error);

int		extension_error(char **argv);
int		arg_error(char argc, char **argv);

int		map_height(char *path);
int		map_width(char *path);
char	**array_generator(int width, int height);
void	fill_map(char **map, char *path, int i, int j);

void	map_floodfill(t_state *state, int x, int y);
t_bool	valid_symbol(char **map);
t_bool	symbol_occurence(char **map, char symbol, int unique);
int		rectangular_map(char **map);
void	player_coord(t_state *state);

void	display_map(char **arr);
void	free_map(char **arr);

void	map_analyzer(t_state *state);
void	map_diagnostic(t_state *state);
int		map_validation(t_state *state);

void	draw_pix(t_img *img, int x, int y, int color);
void	verline(t_state *state, t_pos pos, int size, int color);
void	draw_square(t_state *state, t_pos pos, int size, int color);
void	draw_square_outline(t_state *state, t_pos pos, int size, int color);
void	draw_circle(t_state *state, t_pos pos, int size, int color);

void	draw_map(t_state *state);
void	draw_map_end(t_state *state);

int		keypress(int keycode, t_state *state);
int		keyrelease(int keycode, t_state *state);

void	special_checking(t_state *state);

int		move_p(int keycode, t_state *state);

void	set_parse_flag(t_state *state);
void	set_game_flag(t_state *state);
void	set_main_texture(t_state *state);
void	init_window(t_state *state);

int		adj(int pos, t_state *state);
void	render_square_pic(t_state *state, t_img img, int x, int y);
void	render_square_pic_evolved(t_state *state, t_img img, int x, int y);
void	render_square_pic_rotation(t_state *state, t_img img, int x, int y);

int		period_process(t_state *state);
int		end_time(t_state *state);

void	render_animated_sprite(t_state *state, t_img img, int x, int y);

void	foe_coord(t_state *state);
void	foe_patrol(t_state *state);

void	update_str_score(t_state *state);
void	set_number_img(t_state *state);
void	score_displayer(t_state *state);

void	ending_screen(t_state *state, t_img img, int x, int y);

void	upgrade_square(t_state *state, int x, int y);
void	upgrade_map(t_state *state);

#endif
