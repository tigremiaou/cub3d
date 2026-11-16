/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolito <akkolito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 18:16:03 by akkolito          #+#    #+#             */
/*   Updated: 2026/11/02 18:38:01 by akkolito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

int	door_cond(char **grid, int i, int j)
{
	if ((grid[i - 1][j] != grid[i + 1][j] || grid[i][j - 1] != grid[i][j + 1])
		|| grid[i - 1][j] == grid[i][j - 1])
		return (1);
	return (0);
}

int	check_door(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->grid[++i])
	{
		j = -1;
		while (map->grid[i][++j])
		{
			if (map->grid[i][j] == 'D' && door_cond(map->grid, i, j))
				return (1);
		}
	}
	return (0);
}