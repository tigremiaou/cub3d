/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolito <akkolito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by akkolito          #+#    #+#             */
/*   Updated: 2026/11/02 17:30:22 by akkolito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

void	backer(t_game *g)
{
	int	x;
	int	y;
	
	x = -1;
	while (++x < g->map.map_w * 10)
	{
		y = -1;
		while (++y < g->map.map_h * 10)
			put_pixel_img(&g->screen, x, y, 0x000000);
	}
}

void	grider(t_game *g)
{
	int	x;
	int	y;
	
	x = -1;
	while (++x < g->map.map_w * 10)
	{
		y = -1;
		while (++y < g->map.map_h * 10)
		{
			if (x / 10 >= (int)ft_strlen(g->map.grid[y / 10]))
				continue ;
			if (g->map.grid[y / 10][x / 10] == '1')
				put_pixel_img(&g->screen, x, y, 0xFF0000);
			else if (g->map.grid[y / 10][x / 10] == '0')
				put_pixel_img(&g->screen, x, y, 0xCCCCCC);
			else if (g->map.grid[y / 10][x / 10] == 'D'
					|| g->map.grid[y / 10][x / 10] == 'P')
				put_pixel_img(&g->screen, x, y, 0x0000DD);
			if (y % 10 == 0 || x % 10 == 0)
				put_pixel_img(&g->screen, x, y, 0x000000);
		}
	}
}

void	player(t_game *g)
{
	int	x;
	int	y;
	
	x = g->player.pos_x * 10 - 3;
	while (++x < g->player.pos_x * 10 + 3)
	{
		y = g->player.pos_y * 10 - 3;
		while (++y < g->player.pos_y * 10 + 3)
		{
			if (fabs(x - (g->player.pos_x) * 10) <= 2 || fabs(y - (g->player.pos_y) * 10) <= 2)
				put_pixel_img(&g->screen, x, y, 0x0000EE);
		}
	}
}

void	coner(t_game *g)
{
	int	n = 0;
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		ray_line(g, g->hit_x[x], g->hit_y[x]);
		n++;
		x += 1;
	}
}

void	mapper(t_game *g)
{
	get_map_size(g);
	backer(g);
	grider(g);
	coner(g);
	player(g);
}
