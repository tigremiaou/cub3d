/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 02:31:06 by akkolitozer       #+#    #+#             */
/*   Updated: 2026/10/20 19:02:47 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

static void	init_ray(t_ray *r, t_player *p, int x)
{
	double	camera;

	camera = 2 * x / (double)WIN_W - 1;
	r->dir_x = p->dir_x + p->plane_x * camera;
	r->dir_y = p->dir_y + p->plane_y * camera;
	r->map_x = (int)p->pos_x;
	r->map_y = (int)p->pos_y;
	r->delta_x = 1e42;
	if (r->dir_x != 0)
		r->delta_x = fabs(1 / r->dir_x);
	r->delta_y = 1e42;
	if (r->dir_y != 0)
		r->delta_y = fabs(1 / r->dir_y);
}

static void	init_step(t_ray *r, t_player *p)
{
	r->step_x = 1;
	r->side_x = (r->map_x + 1.0 - p->pos_x) * r->delta_x;
	if (r->dir_x < 0)
	{
		r->step_x = -1;
		r->side_x = (p->pos_x - r->map_x) * r->delta_x;
	}
	r->step_y = 1;
	r->side_y = (r->map_y + 1.0 - p->pos_y) * r->delta_y;
	if (r->dir_y < 0)
	{
		r->step_y = -1;
		r->side_y = (p->pos_y - r->map_y) * r->delta_y;
	}
}

static void	dda(t_ray *r, t_game *g)
{
	while (1)
	{
		facer(r);
		if (is_wall(g, r->map_x, r->map_y))
			break ;
	}
	if (r->face == E || r->face == W)
		r->dist = r->side_x - r->delta_x;
	else
		r->dist = r->side_y - r->delta_y;
	if (r->dist <= 1e-6)
		r->dist = 1e-6;
}

static void	liner(t_ray *r)
{
	r->line_h = (int)(WIN_H / r->dist);
	r->draws = WIN_H / 2 - r->line_h / 2;
	if (r->draws < 0)
		r->draws = 0;
	r->drawe = WIN_H / 2 + r->line_h / 2;
	if (r->drawe >= WIN_H)
		r->drawe = WIN_H - 1;
}

void	raycaster(t_game *g, t_ray *r)
{
	int	x;

	x = -1;
	while(++x < WIN_W)
	{
		init_ray(r, &g->player, x);
		init_step(r, &g->player);
		dda(r, g);
		liner(r);
		columner(g, r, x);
	}
}
