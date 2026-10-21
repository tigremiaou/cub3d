/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 03:40:08 by akkolitozer       #+#    #+#             */
/*   Updated: 2026/10/21 21:14:00 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

void	destroyy(t_game *g)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (g->textures[i].img)
			mlx_destroy_image(g->mlx, g->textures[i].img);
	free_map(&g->map);
	if (g->screen.img)
		mlx_destroy_image(g->mlx, g->screen.img);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
}

int	closee(t_game *g)
{
	destroyy(g);
	exit(0);
	return (0);
}
