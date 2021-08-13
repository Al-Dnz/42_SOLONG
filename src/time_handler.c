#include "solong.h"

int		period_process(t_state *state)
{
	state->timer++;
	if (state->timer > state->sprite_period)
		state->timer = 0;
	//printf("[PERIOD][%d]\n", state->timer);
	return (0);
}

int		increment_time(t_state *state)
{
	state->timer++;
	if (state->timer > 20000)
		quit(state, 0);
	return (0);
}