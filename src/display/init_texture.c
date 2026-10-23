/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:37:01 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/23 19:38:17 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

void	display_texture(t_game *g)
{
	if (g->ray.face == N || g->ray.face == S)
		g->ray.wall_x = g->player.pos_x + g->ray.dist * g->ray.dir_x;
	if (g->ray.face == E || g->ray.face == W)
		g->ray.wall_x = g->player.pos_y + g->ray.dist * g->ray.dir_y;
	g->ray.wall_x -= (int)g->ray.wall_x;
	if (g->ray.face == S || g->ray.face == W)
		g->ray.wall_x = 1 - g->ray.wall_x;
	g->ray.tex_x = g->ray.wall_x * g->textures[0].width;
}

int	init_texture(t_game *g)
{
	int	i;
	int	w;
	int	h;

	i = -1;
	while (++i < 4)
	{
		g->textures[i].img = mlx_xpm_file_to_image(g->mlx,
				g->map.texture_path[i], &w, &h);
		if (!g->textures[i].img)
			return (0);
		g->textures[i].width = w;
		g->textures[i].height = h;
		g->textures[i].adr = mlx_get_data_addr(g->textures[i].img,
				&g->textures[i].bpp, &g->textures[i].linel,
				&g->textures[i].endian);
	}
	return (1);
}
