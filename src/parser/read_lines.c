/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:20:15 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/07 15:45:22 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

static int	count_lines(char *path)
{
	char	*line;
	int		count;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		count++;
	}
	close(fd);
	return (count);
}

char	**read_lines(char *path)
{
	char	**lines;
	char	*line_gnl;
	int		count;
	int		fd;
	int		i;

	i = 0;
	count = count_lines(path);
	if (!count)
		return NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return NULL;
	lines = malloc(sizeof(char *) * (count + 1));
	if (!lines)
		return (close(fd), NULL);
	while ((line_gnl = get_next_line(fd)) != NULL)
	{
		lines[i] = line_gnl;
		i++;
	}
	lines[i] = NULL;
	close(fd);
	return (lines);
}
