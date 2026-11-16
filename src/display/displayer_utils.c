/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolito <akkolito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 22:37:35 by nmeunier          #+#    #+#             */
/*   Updated: 2026/11/02 17:39:01 by akkolito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

int	get_hex_rgb(int *rgb)
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	put_pixel_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_W || y >= WIN_H)
		return ;
	dst = img->adr + y * img->linel + x * (img->bpp / 8);
	*(unsigned int *)dst = color;
}

int	get_pixel(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->adr + y * img->linel + x * (img->bpp / 8);
	return (*(int *)dst);
}

t_img	*get_tex(t_game *g)
{
	if (g->ray.type == 2)
		return (&g->door_tex);
	if (g->ray.face == N)
		return (&g->textures[0]);
	if (g->ray.face == S)
		return (&g->textures[1]);
	if (g->ray.face == E)
		return (&g->textures[2]);
	if (g->ray.face == W)
		return (&g->textures[3]);
	return (NULL);
}
