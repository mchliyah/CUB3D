/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:27:59 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/24 22:57:27 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdbool.h>
# include "../get_next_line/get_next_line.h"

# define TILESIZE 32

# define X 1200
# define Y 800

# define wall '1'
# define empty '0'

# define green 0x0000FF00
# define red 0x00FF0000
# define blue 0x000000FF
# define white 0x00FFFFFF
# define black 0x00000000
#define gray 0x00C0C0C0

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

# define mapWidth 24
# define mapHeight 15

static char map[mapHeight][mapWidth]=
{
  {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
  {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
  {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
  {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
  {'1','0','0','0','0','0','1','1','1','1','1','S','0','0','0','1','0','1','0','1','0','0','0','1'},
  {'1','0','0','0','0','0','1','0','0','0','1','0','1','0','0','0','0','0','0','0','0','0','0','1'},
  {'1','0','0','0','0','0','1','0','0','0','1','1','0','0','0','1','0','1','0','1','0','0','0','1'},
  {'1','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','0','1'},
  {'1','0','0','0','0','0','1','1','0','1','0','0','0','0','0','1','0','1','0','1','0','0','0','1'},
  {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
  {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
  {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
  {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
  {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
  {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
};

typedef struct s_map
{
	const int	rows;
	const int	cols;
	char		**textr;
	char		**colrs;
	char		**map;

}	t_map;

typedef struct s_ax
{
	int	x;
	int	y;
}				t_ax;

typedef struct s_player
{
	char	symbol;
	int		move[3];
	double	fov;
	double	x; //start position
	double	y;
	double	speed_mov;
	double	speed_rot;
	double	rot_angle;
}	t_player;

typedef	struct s_window
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_adrs;
	int		bits_per_pixel;
	int		line_length;
	int		size_line;
	int		endian;
	t_ax	size;
	t_ax	midl;
}	t_window;

typedef struct s_ray
{
	double	angle;
	int		x_start;
	int		y_start;
	int		x_end;
	int		y_end;
	int		dx;
	int		dy;
	int		x_step;
	int		y_step;
	double	wall_hit_x;
	double	wall_hit_y;
	double	x_intercept;
	double	y_intercept;
	bool	was_hit_vertical;
	bool	was_hit_horizontal;
	bool	is_facing_right;
	bool	is_facing_left;
	bool	is_facing_up;
	bool	is_facing_down;
}	t_ray;

typedef struct s_cub
{
	t_window	window;
	t_map		map;
	t_player	player;
	t_ray		ray[X];
}t_cub;

//init
bool	init_player(t_cub *cub);
void	get_player_pos(t_cub *cub);
bool	init_mlx(t_cub *cub);

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

//utils
int		ft_strlen1(char *str);

void	cast_rays(t_cub *cub);
#endif