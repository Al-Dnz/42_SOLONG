#include "solong.h"

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
	printf("move_p(2) : X[%d]Y[%d] => {%d}\n", state->player_coord.x, state->player_coord.y, keycode);
	return (1);
}