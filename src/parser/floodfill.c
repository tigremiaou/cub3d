/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 16:53:58 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/20 20:57:17 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

static int	floodfill(char **visited, int x, int y)
{
	if (y < 0 || visited[y] == NULL)
		return (1);
	if (x < 0 || x >= ft_strlen(visited[y]))
		return (1);
	if (visited[y][x] == ' ')
		return (1);
	if (visited[y][x] == '1')
		return (0);
	visited[y][x] = '1';
	if (floodfill(visited, x - 1, y) == 1)
		return (1);
	if (floodfill(visited, x + 1, y) == 1)
		return (1);
	if (floodfill(visited, x, y - 1) == 1)
		return (1);
	if (floodfill(visited, x, y + 1) == 1)
		return (1);
	return (0);
}

int	count_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static char	**alloc_visited(t_map *map)
{
	char	**visited;
	int		i;

	visited = malloc(sizeof(char *) * (count_height(map->grid) + 1));
	if (!visited)
		return (NULL);
	i = -1;
	while (++i < count_height(map->grid))
	{
		visited[i] = ft_strdup(map->grid[i]);
		if (!visited[i])
			return (NULL);
	}
	visited[count_height(map->grid)] = NULL;
	return (visited);
}

int	check_map(t_map *map)
{
	char	**visited;
	int		result;

	visited = alloc_visited(map);
	if (!visited)
		return (ft_putendl_fd("Error\n"
				"Problem while initializing visited", 2), 1);
	result = floodfill(visited, map->start_x, map->start_y);
	free_lines(visited);
	if (result)
		return (ft_putendl_fd("Error\nInvalid map", 2), 1);
	return (0);
}
