/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:52:38 by nmeunier          #+#    #+#             */
/*   Updated: 2026/11/16 18:45:46 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

static int	is_valid_char(t_game *g, char c)
{
	if (c == 'D')
		g->map.door = 1;
	if (c != 'N'
		&& c != 'S'
		&& c != 'E'
		&& c != 'W'
		&& c != '0'
		&& c != '1'
		&& c != 'D'
		&& c != ' ')
		return (0);
	return (1);
}

static int	check_char(t_game *g, int i, int j, int *count)
{
	if (!is_valid_char(g, g->map.grid[i][j]))
		return (ft_putendl_fd("Error\nInvalid character", 2), 1);
	if (g->map.grid[i][j] == 'N' || g->map.grid[i][j] == 'S'
		|| g->map.grid[i][j] == 'E' || g->map.grid[i][j] == 'W')
	{
		(*count)++;
		g->map.start_x = j;
		g->map.start_y = i;
		g->map.direction_player = g->map.grid[i][j];
	}
	return (0);
}

int	find_player(t_game *g)
{
	int	count;
	int	i;
	int	j;

	i = -1;
	count = 0;
	while (g->map.grid[++i])
	{
		j = -1;
		while (g->map.grid[i][++j])
		{
			if (check_char(g, i, j, &count))
				return (1);
		}
	}
	if (count != 1)
		return (ft_putendl_fd("Error\nInvalid number of players", 2), 1);
	return (0);
}

int	valid_map(t_game *g)
{
	if (find_player(g) || check_map(&g->map) || check_door(&g->map))
		return (1);
	return (0);
}

int	border(char **grid, int i, int j)
{
	if (i < 0 || j < 0 || !grid[i]
		|| j >= ft_strlen(grid[i]) || grid[i][j] == ' ')
		return (1);
	return (0);
}
