#include "solong.h"

void	draw_map_init(t_state *state)
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
			{
				draw_square(state, x * state->square_size + MAP_MARGIN, y * state->square_size + MAP_MARGIN, state->square_size, WHITE);	
			}
			x++;
		}
		y++;
	}
	draw_circle(state, (state->player_coord.x + 0.5) * state->square_size + MAP_MARGIN, (state->player_coord.y + 0.5) * state->square_size + MAP_MARGIN, state->square_size / 4, AZUR);
	mlx_put_image_to_window(state->mlx, state->win, state->img.mlx_img, 0, 0);
}