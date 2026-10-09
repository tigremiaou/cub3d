/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:37:11 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/09 17:36:50 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

int	main(int ac, char **av)
{
	t_map	map;
	char	**lines;

	ft_bzero(&map, sizeof(t_map));
	if (ac != 2)
		return (printf("Error\nWrong number of arguments\n"), 1);
	lines = read_lines(av[1]);
	if (!lines)
		return (printf("Error\nInitializing lines\n"), 1);
	if (!create_map(lines, &map) || !valid_map(&map))
		return (free_all(lines, &map), 1);
	free_all(lines, &map);
	return (0);
}
