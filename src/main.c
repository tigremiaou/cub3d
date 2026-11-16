/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolito <akkolito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:37:11 by nmeunier          #+#    #+#             */
/*   Updated: 2026/11/02 18:40:56 by akkolito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

int	main(int ac, char **av)
{
	t_game	g;
	char	**lines;

	parser(av[1], ac, &lines);
	ft_bzero(&g, sizeof(t_game));
	g.key.shift = 1.0;
	if (create_map(lines, &g.map) || valid_map(&g))
		return (ft_putendl_fd("Error\nInvalid map", 2),
			free_all(lines, &g.map), 1);
	free_lines(lines);
	init_player(&g.player, &g.map);
	g.map_h = count_h(g.map.grid);
	g.floor = get_hex_rgb(g.map.floor_color);
	g.ceiling = get_hex_rgb(g.map.ceiling_color);
	if (init_mlx(&g))
		return (destroyy(&g), 1);
	return (0);
}
