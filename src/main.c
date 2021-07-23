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

void	init_window(t_state *state)
{
	state->mlx = mlx_init();
	//state->win = mlx_new_window(state->mlx, state->win_width, state->win_height, "adenhez's SOLONG");
	state->win = mlx_new_window(state->mlx, 500, 500, "adenhez's SOLONG");
	state->img.mlx_img = mlx_new_image(state->mlx, 500, 500);
	state->img.addr = (int*)mlx_get_data_addr(state->img.mlx_img, &state->img.bpp, &state->img.line_len, &state->img.endian);
}

int	move_p(int keycode, t_state *state)
{
	int x;
	int y;
	
	x = state->player_coord.x;
	y = state->player_coord.y;
	
	if (keycode == FORWARD && y - 1 >= 0)
		y -= 1 ;
	else if (keycode == BACK && state->map[y + 1])
		y += 1;
	else if (keycode == LEFT && x - 1 >= 0)
		x -= 1;
	else if (keycode == RIGHT && state->map[y][x + 1])
		x += 1;
	state->player_coord = (t_pos){x, y};
	//draw_map(state);
	
	printf("move_p(2) : X[%d]Y[%d] => {%d}\n", state->player_coord.x, state->player_coord.y, keycode);
	return (1);
}

int	move_p_2(t_state *state)
{
	int x;
	int y;
	//nanosleep(1);
	//mlx_destroy_image(state->mlx, state->img.mlx_img);
	x = state->player_coord.x;
	y = state->player_coord.y;

	if (state->key.forward && y - 1 >= 0)
		state->player_coord.y -= 1;
	else if (state->key.back && state->map[y + 1])
		state->player_coord.y += 1;
	else if (state->key.left && x - 1 >= 0)
		state->player_coord.x -= 1;
	else if (state->key.right && state->map[y][x + 1])
		state->player_coord.x += 1;
	


	printf("X[%d]Y[%d]\n", state->player_coord.x, state->player_coord.y);
	return (1);
}

int yolo(int keycode, t_state *state)
{
	(void)state;
	printf("=>{%d}<=\n", keycode);
	return 1;
}

int render_graphic(t_state *state)
{
	//mlx_destroy_image(state->mlx, state->img.mlx_img);
	draw_map(state);
	mlx_put_image_to_window(state->mlx, state->win, state->img.mlx_img, 0, 0);

	return (1);
}

void	process(t_state *state)
{
	mlx_hook(state->win, 17, 0, quit, state);
	//mlx_hook(state->win, 2, 1L << 1, &keypress, state);
	//mlx_hook(state->win, 3, 1L << 2, &keyrelease, state);
	//mlx_loop_hook(state->mlx, &move_p_2, state);
	
	//mlx_key_hook(state->win, yolo, &state);
	
	mlx_key_hook(state->win, move_p, state);
	//draw_map(state);
	mlx_loop_hook(state->mlx, &render_graphic, state);

	mlx_put_image_to_window(state->mlx, state->win, state->img.mlx_img, 0, 0);

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

	init_window(&state);
	process(&state);
	return (1);
}