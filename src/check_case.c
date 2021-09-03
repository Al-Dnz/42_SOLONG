#include "solong.h"

void	special_checking(t_state *state)
{
	int	x;
	int	y;

	x = state->player_coord.x;
	y = state->player_coord.y;
	if (state->map[y][x] == 'c')
	{
		state->map[y][x] = 'x';
		draw_map(state);
		state->score++;
		update_str_score(state);
	}
	if (state->map[y][x] == 'e'
			|| (x == state->foe_coord.x && y == state->foe_coord.y))
	{
		state->key_lock = 1;
		if (state->map[y][x] == 'e')
			ending_screen(state, state->win_screen, 0, 0);
		if (x == state->foe_coord.x && y == state->foe_coord.y)
			ending_screen(state, state->gameover_screen, 0, 0);
		mlx_loop_hook(state->mlx, &end_time, state);
	}
}
