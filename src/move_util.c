#include "solong.h"

void	ending_screen(t_state *state, t_img img, int x, int y)
{
	int	i;
	int	j;
	int	ratio;
	int	size;

	draw_map_end(state);
	size = ft_min(state->win_height,state->win_width);
	ratio = img.width / size;
	x = (state->win_width - (img.width / ratio)) / 2;
	y = (state->win_height - (img.height / ratio)) / 2;
	j = -1;
	while (++j < img.height)
	{
		i = -1;
		while (++i < img.width)
			state->img.addr[(y + (j / ratio)) * state->img.line_len / 4 + (x + (i / ratio))] = img.addr[j * img.line_len / 4 + i];
	}
}

void	special_checking(t_state *state)
{
	int	x;
	int	y;

	x = state->player_coord.x;
	y = state->player_coord.y;
	if (state->map[y][x] == 'c')
	{
		state->map[y][x] = 'x';
		draw_map(state);
		state->score++;
		update_str_score(state);
	}
	if (state->map[y][x] == 'e')
	{
		printf("++++++++=>YOU WIN<=++++++++\n");
		state->key_lock = 1;
		ending_screen(state, state->win_screen, 0, 0);
		mlx_loop_hook(state->mlx, &end_time, state);
	}
	if (x == state->foe_coord.x && y == state->foe_coord.y)
	{
		printf("++++++++=>GAME OVER<=++++++++\n");
		state->key_lock = 1;
		ending_screen(state, state->gameover_screen, 0, 0);
		mlx_loop_hook(state->mlx, &end_time, state);
	}
}

int	move_p(int keycode, t_state *state)
{
	int x;
	int y;
	
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
	
	printf("move_p(2) : X[%d]Y[%d] => {%d}\n", state->player_coord.x, state->player_coord.y, keycode);
	//draw_map(state);
	special_checking(state);
	return (1);
}