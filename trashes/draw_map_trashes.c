#include "solong.h"

void	draw_floor_map(t_state *state)
{
	int	x;
	int	y;

	y = 0;
	while (state->map[y])
	{
		x = 0;
		while (state->map[y][x])
		{
			render_square_pic_evolved(state, state->praticable,
				adj(x, state), adj(y, state));
			if (state->map[y][x] == 'e')
				render_square_pic_evolved(state, state->exit,
					adj(x, state), adj(y, state));
			else if (state->map[y][x] == '1')
				render_square_pic_evolved(state, state->wall,
					adj(x, state), adj(y, state));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(state->mlx, state->win, state->img.mlx_img, 0, 0);
}