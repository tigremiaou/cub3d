/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:03:31 by hulescur          #+#    #+#             */
/*   Updated: 2026/10/20 19:59:34 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

int	key_press(int key, void *param)
{
	t_key	*k;

	k = (t_key *) param;
	if (key == KEY_W)
		k->w = TRUE;
	if (key == KEY_A)
		k->a = TRUE;
	if (key == KEY_S)
		k->s = TRUE;
	if (key == KEY_D)
		k->d = TRUE;
	if (key == LEFT_ARR)
		k->lefta = TRUE;
	if (key == RIGHT_ARR)
		k->righta = TRUE;
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
