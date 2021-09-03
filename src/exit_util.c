#include "solong.h"

void	free_img(t_state *state)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (state->number_img[i].mlx_img)
			mlx_destroy_image(state->mlx, state->number_img[i].mlx_img);
		i++;
	}
	if (state->wall.mlx_img)
		mlx_destroy_image(state->mlx, state->wall.mlx_img);
	if (state->collectible.mlx_img)
		mlx_destroy_image(state->mlx, state->collectible.mlx_img);
	if (state->player.mlx_img)
		mlx_destroy_image(state->mlx, state->player.mlx_img);
	if (state->exit.mlx_img)
		mlx_destroy_image(state->mlx, state->exit.mlx_img);
	if (state->foe.mlx_img)
		mlx_destroy_image(state->mlx, state->foe.mlx_img);
	if (state->praticable.mlx_img)
		mlx_destroy_image(state->mlx, state->praticable.mlx_img);
	if (state->win_screen.mlx_img)
		mlx_destroy_image(state->mlx, state->win_screen.mlx_img);
	if (state->gameover_screen.mlx_img)
		mlx_destroy_image(state->mlx, state->gameover_screen.mlx_img);
}

int	quit(t_state *state, int error)
{
	int	fd;

	fd = 1;
	mlx_destroy_image(state->mlx, state->img.mlx_img);
	mlx_clear_window(state->mlx, state->win);
	mlx_destroy_window(state->mlx, state->win);
	free_map(state->map);
	ft_strclr(&state->str_score);
	ft_putstr_fd("EXIT\n", fd);
	ft_putnbr_fd(state->step_n, fd);
	exit(error);
	return (error);
}
