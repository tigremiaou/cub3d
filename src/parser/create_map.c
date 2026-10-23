/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:54:33 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/23 20:20:56 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubos.h"

static int	find_start(char **lines, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->count_texture = 0;
	map->count_color = 0;
	while (++i < 3)
	{
		map->floor_color[i] = -1;
		map->ceiling_color[i] = -1;
	}
	i = -1;
	while (lines[++i])
	{
		j = 0;
		while (lines[i][j] == ' ' || lines[i][j] == '\t')
			j++;
		if (lines[i][j] == '\0')
			continue ;
		if (!handle_id((lines[i] + j), map))
			return (i);
	}
	return (ft_putendl_fd("Error\nNo valid map grid found", 2), -1);
}

static int	complete(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (!map->texture_path[i] || !map->texture_path[i][0])
			return (ft_putendl_fd("Error\nMissing texture", 2), 0);
	i = -1;
	while (++i < 3)
	{
		if (map->floor_color[i] < 0 || map->ceiling_color[i] < 0)
			return (ft_putendl_fd("Error\n"
					"Missing parameters for colors", 2), 0);
		if (map->floor_color[i] > 255 || map->ceiling_color[i] > 255)
			return (ft_putendl_fd("Error\n"
					"RGB out of range", 2), 0);
	}
	if (map->count_texture > 4)
		return (ft_putendl_fd("Error\n"
				"Multiple paths for same texture", 2), 0);
	if (map->count_color > 2)
		return (ft_putendl_fd("Error\n"
				"Multiple paths for same color", 2), 0);
	return (1);
}

void	parser(char *av, int ac, char ***lines)
{
	if (ac != 2)
	{
		ft_putendl_fd("Error\nWrong number of arguments", 2);
		exit(2);
	}
	check_cub(av, ".cub");
	*lines = read_lines(av);
	if (!*lines)
	{
		ft_putendl_fd("Error\nInvalid map", 2);
		exit(2);
	}
}

void	check_oob(char ***line, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->grid[++i])
	{
		j = -1;
		while (map->grid[i][++j])
		{
			if (map->grid[i][j] == '0')
			{
				if (!map->grid[i + 1] || i <= 0 || j <= 0
					|| map->grid[i + 1][j] == ' ' || !map->grid[i + 1][j]
					|| map->grid[i - 1][j] == ' ' || !map->grid[i - 1][j]
					|| map->grid[i][j + 1] == ' ' || !map->grid[i][j + 1]
					|| map->grid[i][j - 1] == ' ' || !map->grid[i][j - 1])
				{
					ft_putendl_fd("Error\nOut of bounds detected", 2);
					free_all(*line, map);
					exit(2);
				}
			}
		}
	}
}

int	create_map(char **lines, t_map *map)
{
	int	n_lines;
	int	start;
	int	i;

	start = find_start(lines, map);
	if (start == -1 || !complete(map))
		return (1);
	n_lines = 0;
	while (lines[start + n_lines])
		n_lines++;
	map->grid = malloc(sizeof (char *) * (n_lines + 1));
	if (!map->grid)
		return (ft_putendl_fd("Error\nMalloc failed", 2), 1);
	i = -1;
	while (lines[start])
	{
		map->grid[++i] = ft_strdup(lines[start]);
		if (!map->grid[i])
			return (ft_putendl_fd("Error\nInitializing data went wrong", 2),
				map->grid[i] = NULL, free_lines(map->grid), 1);
		start++;
	}
	map->grid[n_lines] = NULL;
	check_oob(&lines, map);
	return (0);
}
