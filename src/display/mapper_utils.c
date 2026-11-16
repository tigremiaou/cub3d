/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolito <akkolito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 01:10:15 by akkolito          #+#    #+#             */
/*   Updated: 2026/11/02 17:29:57 by akkolito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

void	get_map_size(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map.grid[++i])
	{
		j = -1;
		while (g->map.grid[i][++j])
			if (j + 1 > g->map.map_w)
				g->map.map_w = j + 1;
	}
	g->map.map_h = i;
}

void	ray_line(t_game *g, double hx, double hy)
{
	double	len;
	double	t;

	len = hypot((hx - g->player.pos_x) * 10, (hy - g->player.pos_y) * 10);
	if (len < 1)
		return ;
	t = 0;
	while (t <= 1)
	{
		put_pixel_img(&g->screen,
			(g->player.pos_x + (hx - g->player.pos_x) * t) * 10,
			(g->player.pos_y + (hy - g->player.pos_y) * t) * 10,
			0xEEEE44);
		t += 1 / len;
	}
}
