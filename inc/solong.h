#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft/libft.h"

# include <stdio.h>

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

typedef struct	s_state
{
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

}				t_state;

void	quit(t_state *state, int error);

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

void	display_map(char **arr);
void	free_map(char **arr);

void	map_analyzer(t_state *state);
void	map_diagnostic(t_state *state);








#endif