#include "solong.h"

void	quit(t_state *state, int error)
{
	free_map(state->map);
	exit(error);
}