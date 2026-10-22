/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubos.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolitozer <akkolitozer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:59:31 by nmeunier          #+#    #+#             */
/*   Updated: 2026/10/22 03:06:51 by akkolitozer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBOS_H
# define CUBOS_H

# include "get_next_line.h"
# include <sys/time.h>
# include "libft.h"
# include "math.h"
# include "mlx.h"

# define WIN_W 1280
# define WIN_H 720
# define KEY_ESC 65307
# define LEFT_ARR 65361
# define RIGHT_ARR 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define SHIFT 65505
# define N 0
# define S 1
# define E 2
# define W 3
# define FALSE 0
# define TRUE 1

# define FOV 0.8
# define FPS 60
# define SPEED 0.05
# define ROT 0.06
# define SPRINT 1.7

typedef struct s_ray
{
	double	delta_x;
	double	delta_y;
	double	wall_x;
	int		step_x;
	int		step_y;
	double	side_x;
	double	side_y;
	int		line_h;
	int		tex_x;
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
	int		count_texture;
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

typedef struct s_img
{
	int			endian;
	int			height;
	int			linel;
	int			width;
	void		*img;
	char		*adr;
	int			bpp;
}	t_img;

typedef struct s_key
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			lefta;
	int			righta;
	double		shift;
}				t_key;

typedef struct s_game
{
	t_img		textures[4];
	long		last_frame;
	int			ceiling;
	t_img		screen;
	t_player	player;
	t_ray		ray;
	int			floor;
	int			map_h;
	void		*mlx;
	void		*win;
	t_map		map;
	t_key		key;
}	t_game;

void	put_pixel_img(t_img *img, int x, int y, int color);
int		create_map(char **lines, t_map *map);
void	init_player(t_player *p, t_map *map);
void	columner(t_game *g, t_ray *r, int x);
char	*skip_space(char *line, int len_id);
int		get_pixel(t_img *img, int x, int y);
void	free_all(char **lines, t_map *map);
int		parse_color(char *str, int *dest);
int		handle_id(char *line, t_map *map);
int		key_release(int key, void *param);
int		is_wall(t_game *g, int x, int y);
int		key_press(int key, void *param);
void	raycaster(t_game *g, t_ray *r);
int		match_id(char *line, char *id);
void	display_texture(t_game *g);
void	free_lines(char **lines);
char	**read_lines(char *path);
int		init_texture(t_game *g);
int		valid_map(t_map *map);
int		check_map(t_map *map);
int		get_hex_rgb(int *rgb);
void	free_map(t_map *map);
int		count_h(char **grid);
t_img	*get_tex(t_game *g);
int		init_mlx(t_game *g);
void	destroyy(t_game *g);
int		render(t_game *g);
int		closee(t_game *g);
void	mover(t_game *g);
void	facer(t_ray *r);
long	get_ms(void);

#endif