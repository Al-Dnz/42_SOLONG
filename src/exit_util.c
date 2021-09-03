#include "solong.h"

void	free_img(t_state *state)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (state->number_img[i].mlx_img)
			free(state->number_img[i].mlx_img);
		i++;
	}
	if (state->wall.mlx_img)
		free(state->wall.mlx_img);
	if (state->collectible.mlx_img)
		free(state->collectible.mlx_img);
	if (state->player.mlx_img)
		free(state->player.mlx_img);
	if (state->exit.mlx_img)
		free(state->exit.mlx_img);
	if (state->foe.mlx_img)
		free(state->foe.mlx_img);
	if (state->praticable.mlx_img)
		free(state->praticable.mlx_img);
	if (state->win_screen.mlx_img)
		free(state->win_screen.mlx_img);
	if (state->gameover_screen.mlx_img)
		free(state->gameover_screen.mlx_img);
}

int	quit(t_state *state, int error)
{
	int	fd;

	fd = 1;
	if (state->mlx)
		mlx_destroy_image(state->mlx, state->img.mlx_img);
	free_img(state);
	free_map(state->map);
	ft_strclr(&state->str_score);
	ft_putstr_fd("EXIT\n", fd);
	ft_putnbr_fd(state->step_n, fd);
	exit(error);
	return (error);
}
