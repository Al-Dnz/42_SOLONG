/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 02:26:23 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/23 19:18:25 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		main(int argc, char **argv)
{
	char	*path;
	t_state state;


	set_parse_flag(&state);
	path = argv[1];
	arg_error(argc, argv);
	
	state.map_width = map_width(path);
	state.map_height = map_height(path);

	//printf("[%d][%d]", state.map_width, state.map_height);
	state.map = array_generator(state.map_width, state.map_height);
	fill_map(state.map, path, 0, 0);
	display_map(state.map);

	map_analyzer(&state);
	map_diagnostic(&state);

	//if (!map_validation(state.map, &state))
	//	exit_parse(&state, 1, "INVALID MAP\n");
	return (1);
}
