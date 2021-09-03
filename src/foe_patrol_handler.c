#include "solong.h"

void	foe_coord(t_state *state)
{
	int	x;
	int	y;

	y = 0;
	state->foe_coord = (t_pos){0, 0};
	while (state->map[y])
	{
		x = 0;
		while (state->map[y][x])
		{
			if (state->map[y][x] == 'f')
			{
				state->foe_coord = (t_pos){x, y};
				state->map[y][x] = 'x';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	foe_patrol(t_state *state)
{
	static int	sens;
	int			x;
	int			y;

	x = state->foe_coord.x;
	y = state->foe_coord.y;
	if (sens == 1 && state->map[y][x + 1])
	{
		if (state->map[y][x + 1] == 'x')
			state->foe_coord.x += 1;
		else if (state->map[y][x + 1] == '1')
			sens = 0;
	}
	if (sens == 0 && state->map[y][x - 1])
	{
		if (state->map[y][x - 1] == 'x')
			state->foe_coord.x -= 1;
		else if (state->map[y][x - 1] == '1')
			sens = 1;
	}
}
