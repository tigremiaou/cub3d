/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolitozer <akkolitozer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 03:21:47 by akkolitozer       #+#    #+#             */
/*   Updated: 2026/10/22 03:07:44 by akkolitozer      ###   ########.fr       */
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

void	waller(t_game *g, int x, int y)
{
	t_img	*tex;
	double	step;
	double	pos;
	int		tex_y;

	tex = get_tex(g);
	if (!tex)
		return ;
	step = (double)tex->height / g->ray.line_h;
	pos = (g->ray.draws - WIN_H / 2 + g->ray.line_h / 2) * step;
	while (y < g->ray.drawe)
	{
		tex_y = (int) pos;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		pos += step;
		put_pixel_img(&g->screen, x, y, get_pixel(tex, g->ray.tex_x, tex_y));
		y++;
	}
}

void	columner(t_game *g, t_ray *r, int x)
{
	int	y;

	y = -1;
	while (++y < WIN_H)
	{
		if (y < r->draws)
			put_pixel_img(&g->screen, x, y, g->ceiling);
		else if (y > r->drawe)
			put_pixel_img(&g->screen, x, y, g->floor);
		else
		{
			waller(g, x, y);
			y = r->drawe;
		}
	}
}

int	render(t_game *g)
{
	if (get_ms() - g->last_frame < 1000 / FPS)
		return (0);
	mover(g);
	raycaster(g, &g->ray);
	mlx_put_image_to_window(g->mlx, g->win, g->screen.img, 0, 0);
	g->last_frame = get_ms();
	return (0);
}
