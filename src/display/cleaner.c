/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolitozer <akkolitozer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 03:40:08 by akkolitozer       #+#    #+#             */
/*   Updated: 2026/10/11 03:22:07 by akkolitozer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

void	destroyy(t_game *g)
{
	if (g->screen.img)
		mlx_destroy_image(g->mlx, g->screen.img);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	free_map(&g->map);
}

int	closee(t_game *g)
{
	destroyy(g);
	exit(0);
	return (0);
}

int	key_press(int key, t_game *g)
{
	if (key == KEY_ESC)
		closee(g);
	return (0);
}
