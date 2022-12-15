/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:27:59 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/15 22:18:47 by mchliyah         ###   ########.fr       */
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

# define TILESIZE 64

# define X 1000
# define Y 1000

#define wall '1'
#define empty '0'

#define green 0x0000FF00
#define red 0x00FF0000
#define blue 0x000000FF

# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

# define ESC 53
# define SPACE 49

# define A_KEY 0
# define D_KEY 2
# define S_KEY 1
# define W_KEY 13

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

static char map[5][10] = {{'1','1','1','1','1'}
				 		,{'1','0','0','0','0','1'}
				 		,{'1','S','1','0','0','1'}
				 		,{'1','0','1','0','0','1'}
				 		,{'1','1','1','1','1'}
};

typedef struct s_map
{
	const int rows;
	const int cols;
	char	**textr;
	char	**colrs;
	char	**map;

}	t_map;

typedef struct	s_ax
{
	int	x;
	int	y;
}				t_ax;

typedef struct s_player
{
	char 	symbol;
	double	x; //start position
	double	y;
	double	dir_turn;//diriction initial 
	double	dir_walk;
	double	angle; //2d raycaster version camera plane 
	double	speed_mv;
	double	speed_rt;
}	t_player;

typedef	struct	s_window
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

typedef struct s_cub
{
	t_window	window;
	t_map		map;
	t_player	player;
}t_cub;

//map handling
bool	get_map(t_map *map, char **av);
int		key_press(int key, t_cub *cub);
int		t_close(t_cub *cub);
void	render(t_cub *cub);
int		ft_strlen1(char *str);
void	get_player_pos(t_cub *cub);

#endif