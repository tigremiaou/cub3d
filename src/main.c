/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:37:11 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/14 16:48:23 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

int	main(int ac, char **av)
{
	t_game	g;
	char	**lines;

	ft_bzero(&g, sizeof(t_game));
	if (ac != 2)
		return (printf("Error\nWrong number of arguments\n"), 1);
	lines = read_lines(av[1]);
	if (!lines)
		return (printf("Error\nInitializing lines\n"), 1);
	if (create_map(lines, &g.map) || valid_map(&g.map))
		return (free_all(lines, &g.map), 1);
	free_lines(lines);
	init_player(&g.player, &g.map);
	g.map_h = count_h(g.map.grid);
	g.floor = get_hex_rgb(g.map.floor_color);
	g.ceiling = get_hex_rgb(g.map.ceiling_color);
	if (init_mlx(&g))
		return (destroyy(&g), 1);
	mlx_hook(g.win, 2, 1L << 0, key_press, &g);
	mlx_hook(g.win, 17, 0, closee, &g);
	mlx_loop_hook(g.mlx, render, &g);
	mlx_loop(g.mlx);
	return (0);
}
