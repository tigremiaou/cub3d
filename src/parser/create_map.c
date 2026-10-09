/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:54:33 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/09 17:54:37 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

static int	find_start(char **lines, t_map *map)
{
	int	i;
	int	j;

	i = -1;
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
	return (printf("Error\nNo valid map grid found\n"), -1);
}

static int	complete(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (!map->texture_path[i] || !map->texture_path[i][0])
			return (printf("Error\nMissing texture\n"), 0);
	i = -1;
	while (++i < 3)
		if (map->floor_color[i] < 0 || map->ceiling_color[i] < 0)
			return (printf("Error\nMissing parameters for colors\n"), 0);
	return (1);
}

int	create_map(char **lines, t_map *map)
{
	int	n_lines;
	int	start;
	int	i;

	start = find_start(lines, map);
	if (start == -1 || !complete(map))
		return (0);
	n_lines = 0;
	while (lines[start + n_lines])
		n_lines++;
	map->grid = malloc(sizeof (char *) * (n_lines + 1));
	if (!map->grid)
		return (printf("Error\nMalloc failed\n"), 0);
	i = -1;
	while (lines[start])
	{
		map->grid[++i] = ft_strdup(lines[start]);
		if (!map->grid[i])
			return (printf("Error\nInitializing data went wrong\n"),
				map->grid[i] = NULL, free_lines(map->grid), 0);
		start++;
	}
	map->grid[n_lines] = NULL;
	return (1);
}
