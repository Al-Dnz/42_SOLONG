#include "solong.h"

int		period_process(t_state *state)
{
	state->timer++;
	if (state->timer > state->sprite_period)
		state->timer = 0;
	if (state->timer == state->sprite_period / 2 || state->timer == 0)
		draw_map(state);
	//printf("[PERIOD][%d]\n", state->timer);
	return (0);
}

int		end_time(t_state *state)
{
	state->timer++;
	if (state->timer > 20000)
		quit(state, 0);
	return (0);
}