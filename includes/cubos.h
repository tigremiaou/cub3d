/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubos.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:59:31 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/07 15:16:20 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBOS_H
# define CUBOS_H

# include "get_next_line.h"
# include "libft.h"

typedef struct s_map
{
	int		ceiling_color[3];
	char	direction_player;
	char	*texture_path[4];
	int		floor_color[3];
	char	**map;
}	t_map;

typedef struct s_player
{
	char	dir_player;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}	t_player;

#endif