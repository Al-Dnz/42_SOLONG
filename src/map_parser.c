#include "solong.h"

void	map_floodfill(t_state *state, int x, int y)
{
	if (ft_find_index("0CPEF", state->map[y][x]) > -1)
	{
		if (ft_find_index("CPEF", state->map[y][x]) > -1)
			state->map[y][x] = ft_tolower(state->map[y][x]);
		if (state->map[y][x] == '0')
			state->map[y][x] = 'x';
		if (x < 1 || y < 1 || !state->map[y][x + 1] || !state->map[y + 1])
		{
			state->closed_map = false;
			return ;
		}
	}
	else if (ft_find_index("0CPEF", state->map[y][x]) == -1)
	{
		if (state->map[y][x] == ' ')
			state->closed_map = false;
		return ;
	}
	map_floodfill(state, x + 1, y);
	map_floodfill(state, x - 1, y);
	map_floodfill(state, x, y + 1);
	map_floodfill(state, x, y - 1);
}

t_bool	valid_symbol(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_find_index("01CEFP ", map[y][x]) == -1)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

t_bool	symbol_occurence(char **map, char symbol, int unique)
{
	int	x;
	int	y;
	int	occurence;

	y = 0;
	occurence = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == symbol)
				occurence++;
			x++;
		}
		y++;
	}
	if (occurence == 0)
		return (0);
	if (unique == 1 && occurence != 1)
		return (0);
	return (1);
}

int	rectangular_map(char **map)
{
	int	i;
	int	j;
	int	previous_width;
	int	width;

	previous_width = 0;
	j = 0;
	while (map[j])
	{
		i = -1;
		width = 0;
		while (map[j][++i])
		{
			if (j == 0)
				previous_width++;
			else if (j > 0)
				width++;
		}
		if (j > 0 && previous_width != width)
			return (false);
		if (j > 0)
			previous_width = width;
		j++;
	}
	return (true);
}

void	player_coord(t_state *state)
{
	int	x;
	int	y;

	y = 0;
	state->player_coord = (t_pos){0, 0};
	while (state->map[y])
	{
		x = 0;
		while (state->map[y][x])
		{
			if (state->map[y][x] == 'P')
			{
				state->player_coord = (t_pos){x, y};
				state->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}
