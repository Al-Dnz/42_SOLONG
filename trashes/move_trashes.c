#include "solong.h"

int	move_p_init(int keycode, t_state *state)
{
	int	x;
	int	y;

	if (state->key_lock == 1)
		return (0);
	x = state->player_coord.x;
	y = state->player_coord.y;
	if (keycode == FORWARD)
	{
		state->player_dir = 'N';
		state->player_up = 1;
		if (y - 1 >= 0 && state->map[y - 1][x] != '1')
		{
			y -= 1 ;
			state->step_n++;
		}		
	}
	else if (keycode == BACK)
	{
		state->player_dir = 'S';
		state->player_up = -1;
		if (state->map[y + 1] && state->map[y + 1][x] != '1')
		{
			y += 1;
			state->step_n++;
		}		
	}
	else if (keycode == LEFT)
	{
		state->player_dir = 'E';
		state->player_right = -1;
		if (x - 1 >= 0 && state->map[y][x - 1] != '1')
		{
			x -= 1;
			state->step_n++;
		}		
	}
	else if (keycode == RIGHT)
	{
		state->player_dir = 'W';
		state->player_right = 1;
		if (state->map[y][x + 1] && state->map[y][x + 1] != '1')
		{
			x += 1;
			state->step_n++;
		}		
	}
	state->player_coord = (t_pos){x, y};
	special_checking(state);
	return (1);
}
