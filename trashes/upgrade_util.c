#include "solong.h"

void	upgrade_square(t_state *state, int x, int y)
{
	int i;
	int	j;
	t_img img[3] = {state->wall, state->collectible, state->exit};

	j = -1;
	while (j <= 1)
	{
		i = -1;
		while (i <= 1)
		{
			render_square_pic_evolved(state, state->praticable, x + i, y + j);
			if (ft_find_index("1ce", state->map[y + j][x + i]) > -1)
				render_square_pic_evolved(state, img[ ft_find_index("1ce", state->map[y + j][x + i]) ], x + i, y + j);
			if (state->player_coord.x == x + i && state->player_coord.y == y + j)
				render_square_pic_rotation(state, state->player, adj(state->player_coord.x, state) ,adj(state->player_coord.y ,state));	
			if (state->foe_coord.x == x + i && state->foe_coord.y == y + j)
				render_square_pic_evolved(state, state->foe, adj(state->foe_coord.x, state) ,adj(state->foe_coord.y ,state));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(state->mlx, state->win, state->img.mlx_img, 0, 0);
}

void	upgrade_map(t_state *state)
{
	int	x;
	int	y;

	y = 0;
	while (state->map[y])
	{
		x = 0;
		while (state->map[y][x])
		{
			if (state->map[y][x] == 'c' || (state->player_coord.x == x && state->player_coord.y == y) || (state->foe_coord.x == x && state->foe_coord.y == y))
				upgrade_square(state, x, y);
			x++;
		}
		y++;
	}
}