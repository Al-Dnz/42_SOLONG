#include "solong.h"

void	draw_meluch(t_state *state, t_img mel, int x, int y)
{
	int	i;
	int	j;
	int	ratio;
	int	size;

	size = ft_min(mel.height, mel.width);
	ratio = size / state->square_size;
	j = -1;
	while (++j < size)
	{
		i = -1;
		while (++i < size)
			state->img.addr[(y + j / ratio)*state->img.line_len / 4 + (x + i / ratio)]
				= mel.addr[j * mel.line_len / 4 + i];
	}
}

void	draw_map(t_state *state)
{
	int			x;
	int			y;
	int 		color;
	static int	color_arr[6] = {BLUE, RED, GREEN, VIOLET, WHITE, BLACK};
	static char	item[6] = {'P', 'f', 'c', 'e', '1', 'x'};

	y = 0;
	while (state->map[y])
	{
		x = 0;
		while (state->map[y][x])
		{
			color = color_arr[ft_find_index(item, state->map[y][x])];
			if (state->map[y][x] != '1')
			{
				draw_square(state, x * state->square_size + MAP_MARGIN, y * state->square_size + MAP_MARGIN, state->square_size, color);
				draw_square_outline(state, x * state->square_size + MAP_MARGIN, y * state->square_size + MAP_MARGIN, state->square_size, BLACK);
			}
			else
				draw_meluch(state, state->meluch, x * state->square_size + MAP_MARGIN, y * state->square_size + MAP_MARGIN);
			
			x++;
		}
		y++;
	}
	draw_circle(state, (state->player_coord.x + 0.5) * state->square_size + MAP_MARGIN, (state->player_coord.y + 0.5) * state->square_size + MAP_MARGIN, state->square_size / 4, AZUR);
}
