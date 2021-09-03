#include "solong.h"

int	period_process(t_state *state)
{
	state->timer++;
	if (state->timer > state->sprite_period)
		state->timer = 0;
	if (!state->end_timer
		&& (state->timer == state->sprite_period / 2 || state->timer == 0))
	{
		foe_patrol(state);
		draw_map(state);
		special_checking(state);
	}
	return (0);
}

int	end_time(t_state *state)
{
	state->end_timer++;
	if (state->end_timer > 20000)
		quit(state, 0);
	return (0);
}
