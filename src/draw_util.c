#include "solong.h"

void	verline(t_state *state, int x, int y, int size, int color)
{
	int i;

	i = -1;
	while (++i <= size)
		draw_pix(&state->img, x, y + i, color);
}

void	draw_circle(t_state *state, int x, int y, int size, int color)
{
	int	i;
	int	a;

	a = 0;
	while (a <= 360)
	{
		i = 0;
		while (i++ <= size)
			draw_pix(&state->img, x + i * sin(PI * a / 180), y - i * cos(PI * a / 180), color);
		a++;
	}
}

void	draw_square(t_state *state, int x, int y, int size, int color)
{
	int	i;

	i = -1;
	while (++i < size)
		verline(state, x + i, y, size, color);
}

void	draw_square_outline(t_state *state, int x, int y, int size, int color)
{
	int	i;

	i = -1;
	while (++i < size)
		draw_pix(&state->img, x + i, y, color);
	i = -1;
	while (++i < size)
		draw_pix(&state->img, x + i, y + size, color);
	verline(state, x, y, size, color);
	verline(state, x + size, y, size, color);
}

void	draw_map(t_state *state)
{
	int	x;
	int	y;
	int color;
	static int color_arr[6] = {BLUE, RED, GREEN, VIOLET, WHITE, BLACK};
	static char	item[6] = {'P', 'f', 'c', 'e', '1', 'x'};


	y = 0;
	while (state->map[y])
	{
		x = 0;
		while (state->map[y][x])
		{
			color = color_arr[ft_find_index(item, state->map[y][x])];
			draw_square(state, x * GRID_UNIT_SIZE + MAP_MARGIN, y * GRID_UNIT_SIZE + MAP_MARGIN, GRID_UNIT_SIZE, color);
			draw_square_outline(state, x * GRID_UNIT_SIZE + MAP_MARGIN, y * GRID_UNIT_SIZE + MAP_MARGIN, GRID_UNIT_SIZE, BLACK);
			x++;
		}
		
		y++;
	}
	draw_circle(state, (state->player_coord.x + 0.5) * GRID_UNIT_SIZE + MAP_MARGIN, (state->player_coord.y + 0.5) * GRID_UNIT_SIZE + MAP_MARGIN, GRID_UNIT_SIZE / 4, AZUR);

}