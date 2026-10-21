/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:48:00 by hulescur          #+#    #+#             */
/*   Updated: 2026/10/21 16:49:28 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

static void	mover_lefta(t_game *g)
{
	double	tempx;

	tempx = g->player.dir_x;
	g->player.dir_x = tempx * cos(ROT) + g->player.dir_y * sin(ROT);
	g->player.dir_y = -tempx * sin(ROT) + g->player.dir_y * cos(ROT);
	g->player.plane_x = -g->player.dir_y * FOV;
	g->player.plane_y = g->player.dir_x * FOV;
}

static void	mover_righta(t_game *g)
{
	double	tempx;

	tempx = g->player.dir_x;
	g->player.dir_x = tempx * cos(ROT) - g->player.dir_y * sin(ROT);
	g->player.dir_y = tempx * sin(ROT) + g->player.dir_y * cos(ROT);
	g->player.plane_x = -g->player.dir_y * FOV;
	g->player.plane_y = g->player.dir_x * FOV;
}

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
		verif_mover(g, g->player.dir_y * SPEED, -g->player.dir_x * SPEED);
	if (g->key.s == TRUE)
		verif_mover(g, -g->player.dir_x * SPEED, -g->player.dir_y * SPEED);
	if (g->key.d == TRUE)
		verif_mover(g, -g->player.dir_y * SPEED, g->player.dir_x * SPEED);
	if (g->key.lefta == TRUE)
		mover_lefta(g);
	if (g->key.righta == TRUE)
		mover_righta(g);
}
