/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 03:21:47 by akkolitozer       #+#    #+#             */
/*   Updated: 2026/10/21 22:49:23 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

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
	if (!init_texture(g))
		return (ft_putendl_fd("Error\ninitializing textures", 2), 1);
	mlx_hook(g->win, 2, (1L << 0), (void *)key_press, g);
	mlx_hook(g->win, 3, (1L << 1), (void *)key_release, &g->key);
	mlx_hook(g->win, 17, 0, closee, g);
	mlx_loop_hook(g->mlx, render, g);
	mlx_loop(g->mlx);
	return (0);
}

void	waller(t_game *g, int x, int y, int wh)
{
	
}

void	columner(t_game *g, t_ray *r, int x)
{
	int	y;
	int	wall;

	if (r->face == N)
		wall = 0xFF0000;
	else if (r->face == S)
		wall = 0x00FF00;
	else if (r->face == E)
		wall = 0x0000FF;
	else
		wall = 0xFFFF00;
	y = -1;
	while (++y < WIN_H)
	{
		if (y < r->draws)
			put_pixel_img(&g->screen, x, y, g->ceiling);
		else if (y > r->drawe)
			put_pixel_img(&g->screen, x, y, g->floor);
		else
		{
			waller(g, x, y, drawe - draws);
			y = drawe;
		}
	}
}

int	render(t_game *g)
{
	t_ray	r;

	if (get_ms() - g->last_frame < 1000 / FPS)
		return (0);
	mover(g);
	raycaster(g, &r);
	mlx_put_image_to_window(g->mlx, g->win, g->screen.img, 0, 0);
	g->last_frame = get_ms();
	return (0);
}
