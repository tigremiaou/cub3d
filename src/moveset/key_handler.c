/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolitozer <akkolitozer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:03:31 by hulescur          #+#    #+#             */
/*   Updated: 2026/10/21 00:46:01 by akkolitozer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

int	key_press(int key, void *param)
{
	t_game	*g;

	g = (t_game *) param;
	if (key == KEY_W)
		g->key.w = TRUE;
	if (key == KEY_A)
		g->key.a = TRUE;
	if (key == KEY_S)
		g->key.s = TRUE;
	if (key == KEY_D)
		g->key.d = TRUE;
	if (key == LEFT_ARR)
		g->key.lefta = TRUE;
	if (key == RIGHT_ARR)
		g->key.righta = TRUE;
	if (key == KEY_ESC)
		closee(g);
	return (0);
}

int	key_release(int key, void *param)
{
	t_key	*k;

	k = (t_key *) param;
	if (key == KEY_W)
		k->w = FALSE;
	if (key == KEY_A)
		k->a = FALSE;
	if (key == KEY_S)
		k->s = FALSE;
	if (key == KEY_D)
		k->d = FALSE;
	if (key == LEFT_ARR)
		k->lefta = FALSE;
	if (key == RIGHT_ARR)
		k->righta = FALSE;
	return (0);
}
