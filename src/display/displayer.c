/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolitozer <akkolitozer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 03:21:47 by akkolitozer       #+#    #+#             */
/*   Updated: 2026/10/12 03:24:14 by akkolitozer      ###   ########.fr       */
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

	dst = img->adr + y * img->linel + x * (img->bpp / 8);
	*(unsigned int *)dst = color;
}

int	init_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		return (ft_putendl_fd("Error\ninitializing mlx", 2), 1);
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "cub3d");
	if (!g->win)
		return (ft_putendl_fd("Error\ncreating window", 2), 1);
	g->screen.img = mlx_new_image(g->mlx, WIN_W, WIN_H);
	if (!g->screen.img)
		return (ft_putendl_fd("Error\ncreating image", 2), 1);
	g->screen.adr = mlx_get_data_addr(g->screen.img, &g->screen.bpp,
			&g->screen.linel, &g->screen.endian);
	return (0);
}

void	columner(t_game *g, t_ray *r, int x)
{
	int y;
	int wall;

	wall = 0xB0B0B0;
	if (r->face == 1)
		wall = 0x707070;
	y = -1;
	while (++y < WIN_H)
	{
		if (y < r->draws)
			put_pixel_img(&g->screen, x, y, g->ceiling);
		else if (y > r->drawe)
			put_pixel_img(&g->screen, x, y, g->floor);
		else
			put_pixel_img(&g->screen, x, y, wall);
	}
}

int	render(t_game *g)
{
	t_ray	r;
	int		x;
	
	x = -1;
	while (++x < WIN_W)
	{
		raycaster(g, &r, x);
		columner(g, &r, x);
	}
	mlx_put_image_to_window(g->mlx, g->win, g->screen.img, 0, 0);
	return (0);
}
