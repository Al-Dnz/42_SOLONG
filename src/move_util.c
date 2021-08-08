#include "solong.h"

int	move_p(int keycode, t_state *state)
{
	int x;
	int y;
	
	x = state->player_coord.x;
	y = state->player_coord.y;
	if (keycode == FORWARD)
	{
		state->player_dir = 'N';
		state->player_up = 1;
		if (y - 1 >= 0 && state->map[y - 1][x] != '1')
			y -= 1 ;
	}
	else if (keycode == BACK)
	{
		state->player_dir = 'S';
		state->player_up = -1;
		if (state->map[y + 1] && state->map[y + 1][x] != '1')
			y += 1;
	}
	else if (keycode == LEFT)
	{
		state->player_dir = 'E';
		state->player_right = -1;
		if (x - 1 >= 0 && state->map[y][x - 1] != '1')
			x -= 1;
	}
	else if (keycode == RIGHT)
	{
		state->player_dir = 'W';
		state->player_right = 1;
		if (state->map[y][x + 1] && state->map[y][x + 1] != '1')
			x += 1;
	}
	state->player_coord = (t_pos){x, y};
	printf("move_p(2) : X[%d]Y[%d] => {%d}\n", state->player_coord.x, state->player_coord.y, keycode);
	//draw_map(state);
	return (1);
}