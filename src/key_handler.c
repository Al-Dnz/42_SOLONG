#include "solong.h"

int keypress(int keycode, t_state *state)
{
	printf("PRESSS %d\n", keycode);
	if (keycode == FORWARD || keycode == 126)
		state->key.forward = true;
	else if (keycode == BACK || keycode == 125)
		state->key.back = true;
	else if (keycode == LEFT || keycode == 123)
		state->key.left = true;
	else if (keycode == RIGHT || keycode == 124)
		state->key.right = true;
	else if (keycode == EXIT)
		exit_process(state, 0);
	return (1);
}

int keyrelease(int keycode, t_state *state)
{
	printf("RELEASE %d\n", keycode);
	if (keycode == FORWARD || keycode == 126)
		state->key.forward = false;
	else if (keycode == BACK || keycode == 125)
		state->key.back = false;
	else if (keycode == LEFT || keycode == 123)
		state->key.left = false;
	else if (keycode == RIGHT || keycode == 124)
		state->key.right = false;
	return (1);
}