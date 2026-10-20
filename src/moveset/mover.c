/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:48:00 by hulescur          #+#    #+#             */
/*   Updated: 2026/10/20 21:05:27 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

/* static void	mover_arrow(t_game *g)
{
	if (g->key.lefta == TRUE)
	{

		
	}
	if (g->key.righta == TRUE)
	{

		
	}
} */

static void	verif_mover(t_game *g, double x, double y)
{
	double	new_x;
	double	new_y;

	new_x = g->player.pos_x + x;
	new_y = g->player.pos_y + y;
	if (!is_wall(g, (int)new_x, (int)g->player.pos_y))
		g->player.pos_x = new_x;
	if (!is_wall(g, (int)g->player.pos_x, (int)new_y))
		g->player.pos_y = new_y;
}

void	mover(t_game *g)
{
	if (g->key.w == TRUE)
		verif_mover(g, g->player.dir_x * SPEED, g->player.dir_y * SPEED);
	if (g->key.a == TRUE)
		verif_mover(g, g->player.dir_y * SPEED, g->player.dir_x * SPEED);
	if (g->key.s == TRUE)
		verif_mover(g, -g->player.dir_x * SPEED, -g->player.dir_y * SPEED);
	if (g->key.d == TRUE)
		verif_mover(g, -g->player.dir_y * SPEED, -g->player.dir_x * SPEED);
/* 	mover_arrow(g, p); */
}
