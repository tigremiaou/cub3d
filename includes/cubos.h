/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubos.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolitozer <akkolitozer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:59:31 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/12 03:29:18 by akkolitozer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBOS_H
# define CUBOS_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include "math.h"

# define WIN_W 1280
# define WIN_H 720
# define KEY_ESC 65307

# define FOV 0.66

typedef struct	s_ray
{
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	double	side_x;
	double	side_y;
	int		line_h;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		draws;
	int		drawe;
	int		face;
	double	dist;
}	t_ray;

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
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct	s_img
{
	void	*img;
	char	*adr;
	int		bpp;
	int		linel;
	int		endian;
}	t_img;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		screen;
	t_map		map;
	t_player	player;
	int			floor;
	int			ceiling;
	int			map_h;
}	t_game;

void	raycaster(t_game *g, t_ray *r, int x);
int		create_map(char **lines, t_map *map);
void	init_player(t_player *p, t_map *map);
char	*skip_space(char *line, int len_id);
void	free_all(char **lines, t_map *map);
int		parse_color(char *str, int *dest);
int		handle_id(char *line, t_map *map);
int		is_wall(t_game *g, int x, int y);
int		match_id(char *line, char *id);
int		key_press(int key, t_game *g);
void	free_lines(char **lines);
char	**read_lines(char *path);
int		valid_map(t_map *map);
int		get_hex_rgb(int *rgb);
void	free_map(t_map *map);
int		count_h(char **grid);
int		init_mlx(t_game *g);
void	destroyy(t_game *g);
int		render(t_game *g);
int		closee(t_game *g);

#endif