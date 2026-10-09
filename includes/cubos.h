/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubos.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:59:31 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/09 18:07:44 by nmeunier         ###   ########.fr       */
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
	char	*texture_path[4]; /*0=NO 1="SO" 2="WE" 3="EA"*/
	int		floor_color[3];
	int		start_x;
	int		start_y;
	char	**grid;
}	t_map;

typedef struct s_player
{
	char	dir_player;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}	t_player;

int		create_map(char **lines, t_map *map);
char	*skip_space(char *line, int len_id);
char	*skip_space(char *line, int len_id);
void	free_all(char **lines, t_map *map);
int		parse_color(char *str, int *dest);
int		handle_id(char *line, t_map *map);
int		match_id(char *line, char *id);
void	free_lines(char **lines);
char	**read_lines(char *path);
int		valid_map(t_map *map);

#endif