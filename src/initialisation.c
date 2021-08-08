#include "solong.h"

void	set_parse_flag(t_state *state)
{
	state->map = NULL;
	state->player_occur = false;
	state->collectible_occur = false;
	state->exit_occur = false;
	state->foe_occur = false;
	state->closed_map = false;
	state->rectangular_map = false;
	state->player_coord = (t_pos){0, 0};
	state->exit_coord = (t_pos){0, 0};
	state->foe_coord = (t_pos){0, 0};
}

void	set_dimension(t_state *state)
{
	state->win_width = 2000;
	state->win_height = 2000;
	state->player_dir = 'E';
	state->player_up = 1;
	state->player_right = 1;
	state->square_size = 50;
}

void	set_texture(t_state *state)
{
	state->player.mlx_img = mlx_xpm_file_to_image(state->mlx, "./textures/mole.xpm", &(state->player.width), &(state->player.height));
	state->player.addr = (int*)mlx_get_data_addr(state->player.mlx_img,&(state->player.bpp), &(state->player.line_len),&(state->player.endian));

	state->floor.mlx_img = mlx_xpm_file_to_image(state->mlx, "./textures/floor.xpm", &(state->floor.width), &(state->floor.height));
	state->floor.addr = (int*)mlx_get_data_addr(state->floor.mlx_img,&(state->floor.bpp), &(state->floor.line_len),&(state->floor.endian));

	state->exit.mlx_img = mlx_xpm_file_to_image(state->mlx, "./textures/exit.xpm", &(state->exit.width), &(state->exit.height));
	state->exit.addr = (int*)mlx_get_data_addr(state->exit.mlx_img,&(state->exit.bpp), &(state->exit.line_len),&(state->exit.endian));

	state->praticable.mlx_img = mlx_xpm_file_to_image(state->mlx, "./textures/clay.xpm", &(state->praticable.width), &(state->praticable.height));
	state->praticable.addr = (int*)mlx_get_data_addr(state->praticable.mlx_img,&(state->praticable.bpp), &(state->praticable.line_len),&(state->praticable.endian));

	state->wall.mlx_img = mlx_xpm_file_to_image(state->mlx, "./textures/stone.xpm", &(state->wall.width), &(state->wall.height));
	state->wall.addr = (int*)mlx_get_data_addr(state->wall.mlx_img,&(state->wall.bpp), &(state->wall.line_len),&(state->wall.endian));

	state->collectible.mlx_img = mlx_xpm_file_to_image(state->mlx, "./textures/carot.xpm", &(state->collectible.width), &(state->collectible.height));
	state->collectible.addr = (int*)mlx_get_data_addr(state->collectible.mlx_img,&(state->collectible.bpp), &(state->collectible.line_len),&(state->collectible.endian));

	state->foe.mlx_img = mlx_xpm_file_to_image(state->mlx, "./textures/spider.xpm", &(state->foe.width), &(state->foe.height));
	state->foe.addr = (int*)mlx_get_data_addr(state->foe.mlx_img,&(state->foe.bpp), &(state->foe.line_len),&(state->foe.endian));

	printf("[KAROTT]\n%d\n", state->collectible.addr[0]);
	printf("[PLAYER]\n%d\n", state->player.addr[0]);
	printf("[EXIT]\n%d\n", state->exit.addr[0]);

	printf("[FLOOR]\n%d\n", state->floor.addr[0]);
}

void	init_window(t_state *state)
{
	state->mlx = mlx_init();
	//state->win = mlx_new_window(state->mlx, state->win_width, state->win_height, "adenhez's SOLONG");
	state->win = mlx_new_window(state->mlx, state->win_width, state->win_height, "adenhez's SOLONG");
	//state->img.mlx_img = mlx_new_image(state->mlx, state->win_width, state->win_height);
	//state->img.addr = (int*)mlx_get_data_addr(state->img.mlx_img, &state->img.bpp, &state->img.line_len, &state->img.endian);	
}