/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:51:23 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/09 16:59:26 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

int	match_id(char *line, char *id)
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

char	*skip_space(char *line, int len_id)
{
	while (line[len_id] == ' ' || line[len_id] == '\t')
		len_id++;
	return (line + len_id);
}

static int	is_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	parse_color(char *str, int *dest)
{
	char	**rgb;
	int		i;

	rgb = ft_split(str, ',');
	if (!rgb)
		return (0);
	i = 0;
	while (i < 3 && rgb[i])
	{
		if (!is_number(rgb[i]))
			return (free_lines(rgb), 0);
		dest[i] = ft_atoi(rgb[i]);
		i++;
	}
	free_lines(rgb);
	if (i != 3)
		return (0);
	return (1);
}
