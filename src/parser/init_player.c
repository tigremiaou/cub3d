/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 03:16:14 by akkolitozer       #+#    #+#             */
/*   Updated: 2026/10/12 19:56:30 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

void	set_dir(t_player *p, double dx, double dy)
{
	p->dir_x = dx;
	p->dir_y = dy;
	p->plane_x = -dy * FOV;
	p->plane_y = dx * FOV;
}

void	init_player(t_player *p, t_map *map)
{
	p->pos_x = map->start_x + 0.5;
	p->pos_y = map->start_y + 0.5;
	if (map->direction_player == 'N')
		set_dir(p, 0, -1);
	else if (map->direction_player == 'S')
		set_dir(p, 0, 1);
	else if (map->direction_player == 'E')
		set_dir(p, 1, 0);
	else
		set_dir(p, -1, 0);
	map->grid[map->start_y][map->start_x] = '0';
}
