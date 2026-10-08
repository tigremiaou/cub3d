/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:20:15 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/08 16:45:54 by nmeunier         ###   ########.fr       */
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
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		count++;
		line = get_next_line(fd);

	}
	close(fd);
	return (count);
}

char	**read_lines(char *path)
{
	char	**lines;
	int		count;
	int		fd;
	int		i;

	i = 0;
	count = count_lines(path);
	if (!count)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = malloc(sizeof(char *) * (count + 1));
	if (!lines)
		return (close(fd), NULL);
	lines[i] = get_next_line(fd);
	while (lines[i++] != NULL)
		lines[i] = get_next_line(fd);
	lines[i] = NULL;
	close(fd);
	return (lines);
}
