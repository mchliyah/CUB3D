/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 01:56:32 by mchliyah          #+#    #+#             */
/*   Updated: 2023/01/04 10:51:20 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/cub.h"

t_ax	s_w_colision(t_cub *cub, int key)
{
	t_ax	pos;

	if (key == S_KEY || key == DOWN_KEY)
	{
		pos.x = cub->player.x - cub->player.speed_mov
			* cos(cub->player.rot_angle);
		pos.y = cub->player.y - cub->player.speed_mov
			* sin(cub->player.rot_angle);
	}
	if (key == W_KEY || key == UP_KEY)
	{
		pos.x = cub->player.x + cub->player.speed_mov
			* cos(cub->player.rot_angle);
		pos.y = cub->player.y + cub->player.speed_mov
			* sin(cub->player.rot_angle);
	}
	return (pos);
}

t_ax	a_d_colision(t_cub *cub, int key)
{
	t_ax	pos;

	if (key == A_KEY)
	{
		pos.x = cub->player.x + cub->player.speed_mov
			* cos(cub->player.rot_angle - M_PI_2);
		pos.y = cub->player.y + cub->player.speed_mov
			* sin(cub->player.rot_angle - M_PI_2);
	}
	if (key == D_KEY)
	{
		pos.x = cub->player.x + cub->player.speed_mov
			* cos(cub->player.rot_angle + M_PI_2);
		pos.y = cub->player.y + cub->player.speed_mov
			* sin(cub->player.rot_angle + M_PI_2);
	}
	return (pos);
}

bool	is_wall(t_cub *cub, int x[2], int y[2])
{
	if (cub->map.parsing[y[0]][x[0]] == WALL
		|| cub->map.parsing[y[1]][x[0]] == WALL
		|| cub->map.parsing[y[0]][x[1]] == WALL
		|| cub->map.parsing[y[1]][x[1]] == WALL)
		return (true);
	return (false);
}

bool	colision(t_cub *cub, int key)
{
	t_ax	pos_start;
	t_ax	pos;
	int		x[2];
	int		y[2];

	pos_start.x = cub->player.x;
	pos_start.y = cub->player.y;
	if (key == S_KEY || key == W_KEY
		|| key == UP_KEY || key == DOWN_KEY)
		pos = s_w_colision(cub, key);
	if (key == A_KEY || key == D_KEY)
		pos = a_d_colision(cub, key);
	x[0] = pos.x + 6;
	x[1] = pos.x - 6;
	y[0] = pos.y + 6;
	y[1] = pos.y - 6;
	x[0] = (int)(x[0] / TILESIZE);
	y[0] = (int)(y[0] / TILESIZE);
	x[1] = (int)(x[1] / TILESIZE);
	y[1] = (int)(y[1] / TILESIZE);
	return (is_wall(cub, x, y));
}
