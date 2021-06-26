
#include "solong.h"

void	map_analyzer(t_state *state)
{
	state->error = false;
	state->valid_symbol = valid_symbol(state->map);
	state->player_occur = symbol_occurence(state->map, 'P', 1);
	state->exit_occur = symbol_occurence(state->map, 'E', 1);
	state->collectible_occur = symbol_occurence(state->map, 'C', 0);
	state->foe_occur = symbol_occurence(state->map, 'F', 1);

	state->rectangular_map = rectangular_map(state->map);
	state->closed_map = true;
	map_floodfill(state, 1, 1);
}

void	map_diagnostic(t_state *state)
{
	int fd = 2;
	if (state->map == NULL)
		ft_putstr_fd("MAP IS EMPTY\n", fd);
	if (state->valid_symbol == false)
		ft_putstr_fd("WRONG(S) SYMBOL(S) IS/ARE SET IN MAP\n", fd);
	if (state->player_occur == false)
		ft_putstr_fd("PLAYER IS NOT CORRECTLY SET\n", fd);
	if (state->exit_occur == false)
		ft_putstr_fd("EXIT IS NOT CORRECTLY SET\n", fd);
	if (state->collectible_occur == false)
		ft_putstr_fd("COLLECTIBLE ARE NOT SET\n", fd);
	if (state->map && state->closed_map == false)
		ft_putstr_fd("MAP IS NOT CLOSED\n", fd);
	if (state->rectangular_map == false)
		ft_putstr_fd("MAP IS NOT RECTANGULAR\n", fd);
}



int		map_validation(t_state *state)
{

	return (1);
}
