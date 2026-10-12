/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolitozer <akkolitozer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 21:35:19 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/10 03:45:23 by akkolitozer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

void	free_lines(char **lines)
{
	int	i;

	i = -1;
	while (lines[++i])
		free(lines[i]);
	free(lines);
}

void	free_all(char **lines, t_map *map)
{
	int	i;

	free_lines(lines);
	i = -1;
	while(++i < 4)
		free(map->texture_path[i]);
	if (!map->grid)
		return ;
	i = -1;
	while (map->grid[++i])
		free(map->grid[i]);
	free(map->grid);
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		free(map->texture_path[i]);
		map->texture_path[i] = NULL;
	}
	if (map->grid)
	{
		free_lines(map->grid);
		map->grid = NULL;
	}
}