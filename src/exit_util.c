#include "solong.h"

void	quit(t_state *state, int error)
{
	int	fd;

	fd = 1;
	free_map(state->map);
	ft_putstr_fd("EXIT\n", fd);
	exit(error);
}
