/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:27:59 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/30 14:29:00 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <math.h>
# include <limits.h>
# include <stdbool.h>
# include "parse.h"

# define TILESIZE 64
# define SCL 0.1

# define X 1600
# define Y 800

# define WALL '1'
# define EMPTY '0'

# define GREEN 0x0000FF00
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define GRAY 0x00A9A9A9
# define YELLOW 0x00FFFF00
# define ORANGE 0x00FFA500
# define PURPLE 0x00800080
# define BROWN 0x00A52A2A
# define AQUA 0x0000FFFF
//keycodes

# define ESC 53
# define SPACE 49
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17 
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define W_KEY 13

typedef struct s_ax
{
	double	x;
	double	y;
}				t_ax;

typedef struct s_int_ax
{
	int	x;
	int	y;
}				t_int_ax;

typedef struct s_player
{
	char	symbol;
	double	x;
	double	y;
	double	fov;
	double	speed_mov;
	double	speed_rot;
	double	rot_angle;
	int		move[3];
	bool	facing_up;
	bool	facing_right;
}	t_player;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_adrs;
	int		bits_per_pixel;
	int		line_length;
	int		size_line;
	int		endian;
}	t_window;

typedef struct s_ray
{
	double	angle;
	double	x_step;
	double	y_step;
	double	wall_hit_x;
	double	wall_hit_y;
	double	x_intercept;
	double	y_intercept;
	double	next_vert_x;
	double	next_vert_y;
	double	next_horz_x;
	double	next_horz_y;
	double	horz_hit_x;
	double	horz_hit_y;
	double	vert_hit_x;
	double	vert_hit_y;
	double	h_distance;
	double	v_distance;
	double	distance;
	bool	is_facing_up;
	bool	is_facing_right;
	bool	hit_vert;
	bool	hit_horz;
}	t_ray;

// typedef struct s_textur
// {
// 	int		f_color;
// 	int		c_color;
// 	void	*no;
// 	void	*so;
// 	void	*we;
// 	void	*ea;
// }	t_textur;

typedef struct s_wall
{
	int		color;
	double	distance;
	double	correct_dist;
	double	height;
	double	top;
	double	bottom;
}	t_wall;

typedef struct s_cub
{
	t_window	window;
	t_map		map;
	t_player	player;
	t_ray		ray[X];
	// t_textur	textur;
}t_cub;

//init
bool	init_mlx(t_cub *cub);
bool	init_player(t_cub *cub);
void	get_player_pos(t_cub *cub);
void	init_ray(t_ray *ray);

//map handling
bool	get_map(t_map *map, char **av);

//render && mlx
int		render(t_cub *cub);
void	my_mlx_pixel_put(t_window *data, int x, int y, unsigned int color);
//events
void	keyhook_loop(t_cub *cub);
int		key_press(int key, t_cub *cub);
int		t_close(t_cub *cub);
int		buttons(int key, t_cub *cub);
void	events(t_cub *cub);
bool	colision(t_cub *cub, int key);

//raycasting
void	cast_rays(t_cub *cub);
void	horizontal_intersection(t_cub *cub, t_player *player, t_ray *ray);
void	vertical_intersection(t_cub *cub, t_player *player, t_ray *ray);
//utils
int		ft_strlen1(char *str);

double	normalize_angle(double angle);
void	player_update(t_cub *cub);

void	draw_line(double x1, double y1, t_ax pos_end, t_cub *cub);
void	render_square(t_cub *cub, t_ax pos, unsigned int color);
void	render_player(t_cub *cub);
#endif