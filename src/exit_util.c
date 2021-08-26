#include "solong.h"

int	quit(t_state *state, int error)
{
	int	fd;

	fd = 1;
	free_map(state->map);
	ft_strclr(&state->str_score);
	ft_putstr_fd("EXIT\n", fd);
	exit(error);
	return (error);
}

void exit_process(t_state *state, int error)
{
	(void)state;
	(void)error;
}
