#include "solong.h"

int	adj(int pos, t_state *state)
{
	return (pos * state->square_size + MAP_MARGIN);
}

void	fill_img_arr(t_state *state, t_img *img_arr)
{
	img_arr[0] = state->player;
	img_arr[1] = state->foe;
	img_arr[2] = state->collectible;
	img_arr[3] = state->exit;
	img_arr[4] = state->wall;
	img_arr[5] = state->praticable;
}

void	render_dynamic_obj(t_state *state)
{
	render_square_pic_evolved(state, state->foe, adj(state->foe_coord.x, state),
		adj(state->foe_coord.y, state));
	render_square_pic_rotation(state, state->player,
		adj(state->player_coord.x, state), adj(state->player_coord.y, state));
	score_displayer(state);
	mlx_put_image_to_window(state->mlx, state->win, state->img.mlx_img, 0, 0);
}

void	draw_map(t_state *state)
{
	int			x;
	int			y;
	t_img		pic;
	t_img		img_arr[6];
	static char	item[6] = {'P', 'f', 'c', 'e', '1', 'x'};

	fill_img_arr(state, img_arr);
	y = -1;
	while (state->map[++y])
	{
		x = -1;
		while (state->map[y][++x])
		{
			render_square_pic_evolved(state, state->praticable, adj(x, state),
				adj(y, state));
			pic = img_arr[ft_find_index(item, state->map[y][x])];
			if (state->map[y][x] == 'c')
				render_animated_sprite(state, pic, adj(x, state),
					adj(y, state));
			else
				render_square_pic_evolved(state, pic, adj(x, state),
					adj(y, state));
		}
	}
	render_dynamic_obj(state);
}

void	draw_map_end(t_state *state)
{
	int			x;
	int			y;
	t_img		pic;
	t_img		img_arr[6];
	static char	item[6] = {'P', 'f', 'c', 'e', '1', 'x'};

	fill_img_arr(state, img_arr);
	y = -1;
	while (state->map[++y])
	{
		x = -1;
		while (state->map[y][++x])
		{
			render_square_pic_evolved(state, state->praticable,
				adj(x, state), adj(y, state));
			if (state->map[y][x] == '1' || state->map[y][x] == 'e')
			{
				pic = img_arr[ft_find_index(item, state->map[y][x])];
				render_square_pic_evolved(state, pic, adj(x, state),
					adj(y, state));
			}
		}
	}
	mlx_put_image_to_window(state->mlx, state->win, state->img.mlx_img, 0, 0);
}
