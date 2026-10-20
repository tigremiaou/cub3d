/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 03:40:08 by akkolitozer       #+#    #+#             */
/*   Updated: 2026/10/20 16:04:37 by hulescur         ###   ########.fr       */
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
