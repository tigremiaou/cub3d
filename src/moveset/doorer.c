/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doorer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:39:40 by akkolito          #+#    #+#             */
/*   Updated: 2026/11/16 18:03:35 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

void	doorer(t_game *g)
{
	int		x;
	int		y;
	char	*cell;

	x = (int)(g->player.pos_x + g->player.dir_x);
	y = (int)(g->player.pos_y + g->player.dir_y);
	if (y < 0 || y >= g->map_h || x < 0 || x >= (int)ft_strlen(g->map.grid[y]))
		return ;
	cell = &g->map.grid[y][x];
	if (*cell == 'D')
		*cell = 'P';
	else if (*cell == 'P'
		&& !((int)g->player.pos_x == x && (int)g->player.pos_y == y))
		*cell = 'D';
}
