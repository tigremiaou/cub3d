/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:37:01 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/21 22:25:59 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

void	display_texture(t_game *g, t_ray *r)
{
	if (r->face == N || r->face == S)
		g->screen.wall_x = g->player.pos_x + r->dist * r->dir_x;
	if (r->face == E || r->face == W)
		g->screen.wall_x = g->player.pos_y + r->dist * r->dir_y;
	g->screen.wall_x -= (int)g->screen.wall_x;
	if (r->face == S || r->face == W)
		g->screen.wall_x = 1 - g->screen.wall_x;
	g->screen.col_tex = g->screen.wall_x * 64;
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
