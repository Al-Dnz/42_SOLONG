#include "solong.h"

void	set_main_texture_1(t_state *state)
{
	state->player.mlx_img = mlx_xpm_file_to_image(state->mlx,
			"./textures/mole.xpm", &(state->player.width),
			&(state->player.height));
	state->player.addr = (int *)mlx_get_data_addr(state->player.mlx_img,
			&(state->player.bpp),
			&(state->player.line_len), &(state->player.endian));
	state->exit.mlx_img = mlx_xpm_file_to_image(state->mlx,
			"./textures/motte.xpm",
			&(state->exit.width), &(state->exit.height));
	state->exit.addr = (int *)mlx_get_data_addr(state->exit.mlx_img,
			&(state->exit.bpp), &(state->exit.line_len), &(state->exit.endian));
}

void	set_main_texture_2(t_state *state)
{
	state->praticable.mlx_img = mlx_xpm_file_to_image(state->mlx,
			"./textures/grass.xpm", &(state->praticable.width),
			&(state->praticable.height));
	state->praticable.addr = (int *)mlx_get_data_addr(state->praticable.mlx_img,
			&(state->praticable.bpp),
			&(state->praticable.line_len), &(state->praticable.endian));
	state->wall.mlx_img = mlx_xpm_file_to_image(state->mlx,
			"./textures/rock.xpm",
			&(state->wall.width), &(state->wall.height));
	state->wall.addr = (int *)mlx_get_data_addr(state->wall.mlx_img,
			&(state->wall.bpp), &(state->wall.line_len), &(state->wall.endian));
	state->collectible.mlx_img = mlx_xpm_file_to_image(state->mlx,
			"./textures/carot.xpm", &(state->collectible.width),
			&(state->collectible.height));
	state->collectible.addr
		= (int *)mlx_get_data_addr(state->collectible.mlx_img,
			&(state->collectible.bpp),
			&(state->collectible.line_len), &(state->collectible.endian));
}

void	set_main_texture_3(t_state *state)
{
	state->foe.mlx_img = mlx_xpm_file_to_image(state->mlx,
			"./textures/fox.xpm", &(state->foe.width),
			&(state->foe.height));
	state->foe.addr = (int *)mlx_get_data_addr(state->foe.mlx_img,
			&(state->foe.bpp), &(state->foe.line_len), &(state->foe.endian));
	state->win_screen.mlx_img = mlx_xpm_file_to_image(state->mlx,
			"./textures/you_win.xpm", &(state->win_screen.width),
			&(state->win_screen.height));
	state->win_screen.addr = (int *)mlx_get_data_addr(state->win_screen.mlx_img,
			&(state->win_screen.bpp),
			&(state->win_screen.line_len), &(state->win_screen.endian));
	state->gameover_screen.mlx_img = mlx_xpm_file_to_image(state->mlx,
			"./textures/game_over.xpm", &(state->gameover_screen.width),
			&(state->gameover_screen.height));
	state->gameover_screen.addr
		= (int *)mlx_get_data_addr(state->gameover_screen.mlx_img,
			&(state->gameover_screen.bpp), &(state->gameover_screen.line_len),
			&(state->gameover_screen.endian));
}

void	set_main_texture(t_state *state)
{
	set_main_texture_1(state);
	set_main_texture_2(state);
	set_main_texture_3(state);
	set_number_img(state);
}
