/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:54:33 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/12 20:19:45 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

static int	find_start(char **lines, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->count_texture = 0;
	while (++i < 3)
	{
		map->floor_color[i] = -1;
		map->ceiling_color[i] = -1;
	}
	i = -1;
	while (lines[++i])
	{
		j = 0;
		while (lines[i][j] == ' ' || lines[i][j] == '\t')
			j++;
		if (lines[i][j] == '\0')
			continue ;
		if (!handle_id((lines[i] + j), map))
			return (i);
	}
	return (ft_putendl_fd("Error\nNo valid map grid found", 2), -1);
}

static int	complete(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (!map->texture_path[i] || !map->texture_path[i][0])
			return (ft_putendl_fd("Error\nMissing texture", 2), 0);
	i = -1;
	while (++i < 3)
	{
		if (map->floor_color[i] < 0 || map->ceiling_color[i] < 0)
			return (ft_putendl_fd("Error\n"
					"Missing parameters for colors", 2), 0);
		if (map->floor_color[i] > 255 || map->ceiling_color[i] > 255)
			return (ft_putendl_fd("Error\n"
					"RGB out of range", 2), 0);
	}
	if (map->count_texture != 4)
		return (ft_putendl_fd("Error\n"
				"Multiple paths for same texture", 2), 0);
	return (1);
}

int	create_map(char **lines, t_map *map)
{
	int	n_lines;
	int	start;
	int	i;

	start = find_start(lines, map);
	if (start == -1 || !complete(map))
		return (1);
	n_lines = 0;
	while (lines[start + n_lines])
		n_lines++;
	map->grid = malloc(sizeof (char *) * (n_lines + 1));
	if (!map->grid)
		return (ft_putendl_fd("Error\nMalloc failed", 2), 1);
	i = -1;
	while (lines[start])
	{
		map->grid[++i] = ft_strdup(lines[start]);
		if (!map->grid[i])
			return (ft_putendl_fd("Error\nInitializing data went wrong", 2),
				map->grid[i] = NULL, free_lines(map->grid), 1);
		start++;
	}
	map->grid[n_lines] = NULL;
	return (0);
}
