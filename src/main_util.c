/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:45:42 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/22 23:09:25 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int		extension_error(char **argv)
{
	char	**tab;
	int		i;
	int		output;

	output = 0;
	i = 0;
	tab = ft_split(argv[1], ".");
	while (tab[i])
		i++;
	if (ft_strcmp(tab[i - 1], "ber"))
		output = 1;
	ft_free_tab(tab);
	return (output);
}

int		arg_error(char argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nWRONG ARGUMENTS NUMBER\n", 1);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nPATH TO MAP FILE IS INVALID\n", 1);
		exit(0);
	}
	close(fd);
	if (extension_error(argv))
	{
		ft_putstr_fd("Error\nEXTENSION OF MAP FILE IS INVALID\n", 1);
		exit(0);
	}
	return (1);
}

