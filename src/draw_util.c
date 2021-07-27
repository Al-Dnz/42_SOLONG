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
