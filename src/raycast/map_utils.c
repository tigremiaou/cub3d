/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolitozer <akkolitozer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 03:53:11 by akkolitozer       #+#    #+#             */
/*   Updated: 2026/10/12 02:15:40 by akkolitozer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

int	count_h(char **grid)
{
	int	n;

	n = 0;
	while (grid[n])
		n++;
	return (n);
}

int	is_wall(t_game *g, int x, int y)
{
	char	*row;

	if (x < 0 || y < 0 || y >= g->map_h)
		return (1);
	row = g->map.grid[y];
	if (x >= (int)ft_strlen(row))
		return (1);
	return (row[x] == '1' || row[x] == ' ');
}
