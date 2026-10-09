/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:51:23 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/09 16:28:59 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

static int	match_id(char *line, char *id)
{
	int	len;

	len = ft_strlen(id);
	if (ft_strncmp(line, id, len) != 0)
		return (0);
	if (line[len] == ' ' || line[len] == '\t')
		return (1);
	else
		return (0);
}

static char	*skip_space(char *line, int len_id)
{
	while (line[len_id] == ' ' || line[len_id] == '\t')
		len_id++;
	return (line + len_id);
}

static int	parse_color(char *str, int *dest)
{
	char	**rgb;
	int		i;

	rgb = ft_split(str, ',');
	if (!rgb)
		return (0);
	i = 0;
	while (i < 3 && rgb[i])
	{
		dest[i] = ft_atoi(rgb[i]);
		i++;
	}
	free_lines(rgb);
	return (1);
}

int	handle_id(char *lines, t_map *map)
{
	if (match_id(lines, "NO"))
		map->texture_path[0] = ft_strdup(skip_space(lines, 2));
	else if (match_id(lines, "SO"))
		map->texture_path[1] = ft_strdup(skip_space(lines, 2));
	else if (match_id(lines, "WE"))
		map->texture_path[2] = ft_strdup(skip_space(lines, 2));
	else if (match_id(lines, "EA"))
		map->texture_path[3] = ft_strdup(skip_space(lines, 2));
	else if (match_id(lines, "F"))
		parse_color(skip_space(lines, 1), map->floor_color);
	else if (match_id(lines, "C"))
		parse_color(skip_space(lines, 1), map->ceiling_color);
	else
		return (0);
	return (1);
}
