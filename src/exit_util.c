#include "solong.h"

int	quit(t_state *state, int error)
{
	int	fd;

	fd = 1;
	if (state->mlx)
		mlx_destroy_image(state->mlx, state->img.mlx_img);
	free_map(state->map);
	ft_strclr(&state->str_score);
	ft_putstr_fd("EXIT\n", fd);
	ft_putnbr_fd(state->step_n, fd);
	exit(error);
	return (error);
}

void	exit_process(t_state *state, int error)
{
	(void)state;
	(void)error;
}
