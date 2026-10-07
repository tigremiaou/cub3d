/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:54:33 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/07 21:42:20 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

static int	find_start(char **lines)
{
	int	start;
	int	i;
	int	j;

	i = -1;
	start = -1;
	while (lines[++i])
	{
		j = 0;
		while (lines[i][j] == ' ' || lines[i][j] == '\t')
			j++;
		if (lines[i][j] == '1')
		{
			start = i;
			return (start);
		}
	}
	return (start);
}

int	create_map(char **lines, t_map *map)
{
	int	n_lines;
	int	start;
	int	i;

	start = find_start(lines);
	if (start == -1)
		return (0);
	n_lines = 0;
	while (lines[start + n_lines])
		n_lines++;
	map->grid = malloc(sizeof (char *) * (n_lines + 1));
	if (!map->grid)
		return (0);
	i = -1;
	while (lines[start])
	{
		map->grid[++i] = ft_strdup(lines[start]);
		if (!map->grid[i])
			return (free_lines(map->grid), 0);
		start++;
	}
	map->grid[n_lines] = NULL;
	i = -1;
	while(map->grid[++i])
		printf("%s", map->grid[i]);
	return (1);
}
