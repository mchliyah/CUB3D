/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 01:56:32 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/28 22:44:09 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_ax	s_w_colision(t_cub *cub, int key)
{
	t_ax	pos;

	if (key == S_KEY)
	{
		pos.x = cub->player.x - cub->player.speed_mov
			* cos(cub->player.rot_angle);
		pos.y = cub->player.y - cub->player.speed_mov
			* sin(cub->player.rot_angle);
	}
	if (key == W_KEY)
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

bool	colision(t_cub *cub, int key)
{
	t_ax		pos_start;
	t_ax		pos;
	t_int_ax	check;

	pos_start.x = cub->player.x;
	pos_start.y = cub->player.y;
	if (key == S_KEY || key == W_KEY)
		pos = s_w_colision(cub, key);
	if (key == A_KEY || key == D_KEY)
		pos = a_d_colision(cub, key);
	if (cub->player.rot_angle > 0 && cub->player.rot_angle < M_PI)
		check.y = (pos.y + 6) / TILESIZE;
	else
		check.y = (pos.y - 6) / TILESIZE;
	if (cub->player.rot_angle > M_PI_2 && cub->player.rot_angle < 3 * M_PI_2)
		check.x = (pos.x - 6) / TILESIZE;
	else
		check.x = (pos.x + 6) / TILESIZE;
	if (map[check.y][check.x] == WALL)
		return (true);
	if (map[((int)(pos_start.y / TILESIZE))][(check.x)] == WALL
		|| map[(check.y)][(int)(pos_start.x / TILESIZE)] == WALL)
		return (true);
	return (false);
}
