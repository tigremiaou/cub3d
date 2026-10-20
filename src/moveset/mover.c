/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:48:00 by hulescur          #+#    #+#             */
/*   Updated: 2026/10/20 20:53:26 by nmeunier         ###   ########.fr       */
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

void	mover(t_game *g)
{
	if (g->key.w == TRUE)
	{
		g->player.pos_x += g->player.dir_x * SPEED;
		g->player.pos_y += g->player.dir_y * SPEED;
	}
	if (g->key.a == TRUE)
	{
		g->player.pos_x += g->player.dir_y * SPEED;
		g->player.pos_y += g->player.dir_x * SPEED;
	}
	if (g->key.s == TRUE)
	{
		g->player.pos_x -= g->player.dir_x * SPEED;
		g->player.pos_y -= g->player.dir_y * SPEED;
	}
	if (g->key.d == TRUE)
	{
		g->player.pos_x -= g->player.dir_y * SPEED;
		g->player.pos_y -= g->player.dir_x * SPEED;
	}
/* 	mover_arrow(g, p); */
}
