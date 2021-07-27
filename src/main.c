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
	state->square_size = 50;
}

void	set_texture(t_state *state)
{
	state->meluch.mlx_img = mlx_xpm_file_to_image(state->mlx, "./textures/melanchon.xpm", &(state->meluch.width), &(state->meluch.height));
	state->meluch.addr = (int*)mlx_get_data_addr(state->meluch.mlx_img,&(state->meluch.bpp), &(state->meluch.line_len),&(state->meluch.endian));
}

void	init_window(t_state *state)
{
	state->mlx = mlx_init();
	//state->win = mlx_new_window(state->mlx, state->win_width, state->win_height, "adenhez's SOLONG");
	state->win = mlx_new_window(state->mlx, state->win_width, state->win_height, "adenhez's SOLONG");
	state->img.mlx_img = mlx_new_image(state->mlx, state->win_width, state->win_height);
	state->img.addr = (int*)mlx_get_data_addr(state->img.mlx_img, &state->img.bpp, &state->img.line_len, &state->img.endian);	
}

int render_graphic(t_state *state)
{
	//draw_map(state);
	//mlx_destroy_image(state->mlx, state->img.mlx_img);
	draw_square(state, 5 * state->square_size + MAP_MARGIN, 3 * state->square_size + MAP_MARGIN, state->square_size, RED);
	sleep(1);
	draw_square(state, 5 * state->square_size + MAP_MARGIN, 3 * state->square_size + MAP_MARGIN, state->square_size, VIOLET);

	mlx_put_image_to_window(state->mlx, state->win, state->img.mlx_img, 0, 0);
	return (1);
}
 
void	process(t_state *state)
{
	mlx_hook(state->win, 17, 0, quit, state);
	mlx_hook(state->win, 2, 1L << 1, &keypress, state);
	mlx_key_hook(state->win, move_p, state);
	//mlx_loop_hook(state->mlx, &render_graphic, state);
	mlx_loop(state->mlx);
}

int		main(int argc, char **argv)
{
	char	*path;
	t_state	state;

	set_parse_flag(&state);
	path = argv[1];
	arg_error(argc, argv);
	state.map_width = map_width(path);
	state.map_height = map_height(path);
	printf("MAP : width = [%d] height = [%d]\n", state.map_width, state.map_height);
	state.map = array_generator(state.map_width, state.map_height);
	fill_map(state.map, path, 0, 0);
	map_analyzer(&state);
	map_diagnostic(&state);
	if (map_validation(&state) == 0)
		quit(&state, state.error);
	else
		ft_putstr_fd("=>OK<=\n", 1);
	display_map(state.map);
	printf("player : X[%d]Y[%d]\n", state.player_coord.x, state.player_coord.y);
	set_dimension(&state);
	init_window(&state);
	set_texture(&state);
	process(&state);
	return (1);
}