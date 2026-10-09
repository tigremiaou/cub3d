/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:51:53 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/09 17:09:08 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

static int	handle_color(char *lines, t_map *map)
{
	if (match_id(lines, "F"))
	{
		if (!parse_color(skip_space(lines, 1), map->floor_color))
			return (-1);
	}
	else if (match_id(lines, "C"))
	{
		if (!parse_color(skip_space(lines, 1), map->ceiling_color))
			return (-1);
	}
	else
		return (0);
	return (1);
}

static int	handle_texture(char *lines, t_map *map)
{
	if (match_id(lines, "NO"))
	{
		free(map->texture_path[0]);
		map->texture_path[0] = ft_strdup(skip_space(lines, 2));
	}
	else if (match_id(lines, "SO"))
	{
		free(map->texture_path[1]);
		map->texture_path[1] = ft_strdup(skip_space(lines, 2));
	}
	else if (match_id(lines, "WE"))
	{
		free(map->texture_path[2]);
		map->texture_path[2] = ft_strdup(skip_space(lines, 2));
	}
	else if (match_id(lines, "EA"))
	{
		free(map->texture_path[3]);
		map->texture_path[3] = ft_strdup(skip_space(lines, 2));
	}
	else
		return (0);
	return (1);
}

int	handle_id(char *lines, t_map *map)
{
	int	ret;

	ret = handle_texture(lines, map);
	if (ret)
		return (ret);
	ret = handle_color(lines, map);
	if (ret)
		return (ret);
	return (0);
}
