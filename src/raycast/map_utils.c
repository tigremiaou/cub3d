/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 03:53:11 by akkolitozer       #+#    #+#             */
/*   Updated: 2026/10/21 21:18:50 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

int	count_h(char **grid)
{
	int	n;

	n = 0;
	while (grid[n])
		n++;
	return (n);
}

int	is_wall(t_game *g, int x, int y)
{
	char	*row;

	if (x < 0 || y < 0 || y >= g->map_h)
		return (1);
	row = g->map.grid[y];
	if (x >= (int)ft_strlen(row))
		return (1);
	return (row[x] == '1' || row[x] == ' ');
}

void	facer(t_ray *r)
{
	if (r->side_x < r->side_y)
	{
		r->side_x += r->delta_x;
		r->map_x += r->step_x;
		if (r->step_x < 0)
			r->face = W;
		else
			r->face = E;
	}
	else
	{
		r->side_y += r->delta_y;
		r->map_y += r->step_y;
		if (r->step_y < 0)
			r->face = N;
		else
			r->face = S;
	}
}

long	get_ms(void)
{
	struct timeval	time;
	int				error;

	error = gettimeofday(&time, NULL);
	if (error)
		return (0);
	return ((time.tv_sec * 1000L) + (time.tv_usec / 1000L));
}
