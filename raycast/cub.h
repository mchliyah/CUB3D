/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:27:59 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/13 18:28:50 by mchliyah         ###   ########.fr       */
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

# define X 1000
# define Y 800

char map[5][5] = {{'1','1','1','1','1'}
				 ,{'1','0','0','0','1'}
				 ,{'1','0','N','0','1'}
				 ,{'1','0','0','0','1'}
				 ,{'1','1','1','1','1'}
};

typedef struct s_map
{
	char	**textr;
	char	**colrs;
	char	**map;

}	t_map;

typedef struct	s_ax
{
	double	x;
	double	y;
}				t_ax;

typedef struct s_player
{
	double	posX; //start position
	double	posY;
	double	dirX;//diriction initial 
	double	dirY;
	double	planeX; //2d raycaster version camera plane 
	double	planeY;
}	t_player;

typedef	struct	s_window
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_adrs;
	int		bpp;
	int		len;
	int		size_line;
	int		endian;
	t_ax	size;
	t_ax	midl;
}	t_window;

typedef struct s_cub
{
	t_window	window;
	t_map		map;
}t_cub;

//map handling
bool	get_map(t_map *map, char **av);

#endif