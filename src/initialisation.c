#include "solong.h"

void	set_parse_flag(t_state *state)
{
	state->map = NULL;
	state->player_occur = false;
	state->collectible_occur = false;
	state->exit_occur = false;
	state->foe_occur = false;
	state->closed_map = false;
	state->rectangular_map = false;
	state->player_coord = (t_pos){0, 0};
	state->exit_coord = (t_pos){0, 0};
	state->foe_coord = (t_pos){-1, -1};
}

void	set_dimension(t_state *state)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(state->mlx, &screen_width, &screen_height);
	if (state->map_height >= state->map_width)
		state->square_size = ((3 * screen_height / 4)
				- (2 * MAP_MARGIN)) / (state->map_height);
	else
		state->square_size = ((3 * screen_width / 4)
				- (2 * MAP_MARGIN)) / (state->map_width);
	if (state->square_size > 50)
		state->square_size = 50;
	state->win_width = (state->map_width * state->square_size)
		+ (2 * MAP_MARGIN);
	state->win_height = (state->map_height * state->square_size)
		+ (2 * MAP_MARGIN);
}

void	set_game_flag(t_state *state)
{
	set_dimension(state);
	state->player_dir = 'E';
	state->player_up = 1;
	state->player_right = 1;
	state->score = 0;
	state->str_score = ft_itoa(state->score);
	state->step_n = 0;
	state->timer = 0;
	state->sprite_period = 10000;
	state->sprite_sens = 0;
	state->key_lock = 0;
	foe_coord(state);
}

void	init_window(t_state *state)
{
	state->mlx = mlx_init();
	state->win = mlx_new_window(state->mlx, state->win_width,
			state->win_height, "adenhez's SOLONG");
	state->img.mlx_img = mlx_new_image(state->mlx,
			state->win_width, state->win_height);
	state->img.addr = (int *)mlx_get_data_addr(state->img.mlx_img,
			&state->img.bpp, &state->img.line_len, &state->img.endian);
}
