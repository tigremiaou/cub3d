/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:52:38 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/12 19:56:15 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

static int	is_valid_char(char c)
{
	if (c != 'N'
		&& c != 'S'
		&& c != 'E'
		&& c != 'W'
		&& c != '0'
		&& c != '1'
		&& c != ' ')
		return (1);
	return (0);
}

static int	check_char(t_map *map, int i, int j, int *count)
{
	if (is_valid_char(map->grid[i][j]))
		return (ft_putendl_fd("Error\nInvalid character in map", 2), 1);
	if (map->grid[i][j] == 'N' || map->grid[i][j] == 'S'
		|| map->grid[i][j] == 'E' || map->grid[i][j] == 'W')
	{
		(*count)++;
		map->start_x = j;
		map->start_y = i;
		map->direction_player = map->grid[i][j];
	}
	return (0);
}

int	find_player(t_map *map)
{
	int	count;
	int	i;
	int	j;

	i = -1;
	count = 0;
	while (map->grid[++i])
	{
		j = -1;
		while (map->grid[i][++j])
		{
			if (check_char(map, i, j, &count))
				return (1);
		}
	}
	if (count != 1)
		return (ft_putendl_fd("Error\nInvalid number of"
				"player(s) in the map", 2), 1);
	return (0);
}

int	valid_map(t_map *map)
{
	if (find_player(map))
		return (0);
	return (1);
}
