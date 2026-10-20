/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:03:31 by hulescur          #+#    #+#             */
/*   Updated: 2026/10/20 17:45:29 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

int	key_press(int key, void *param)
{
	t_key *k;

	k = (t_key *) param;
	if (key == KEY_W)
		k->w = true;
	if (key == KEY_A)
		k->a = true;
	if (key == KEY_S)
		k->s = true;
	if (key == KEY_D)
		k->d = true;
	if (key == LEFT_ARR)
		k->lefta = true;
	if (key == RIGHT_ARR)
		k->righta = true;
	return (0);
}

int	key_release(int key, void *param)
{
	t_key *k;

	k = (t_key *) param;
	if (key == KEY_W)
		k->w = false;
	if (key == KEY_A)
		k->a = false;
	if (key == KEY_S)
		k->s = false;
	if (key == KEY_D)
		k->d = false;
	if (key == LEFT_ARR)
		k->lefta = false;
	if (key == RIGHT_ARR)
		k->righta = false;
	return (0);
}
