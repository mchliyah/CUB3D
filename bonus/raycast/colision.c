/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 01:56:32 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/30 13:54:58 by mchliyah         ###   ########.fr       */
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

bool	colision(t_cub *cub, int key)
{
	t_ax		pos_start;
	t_ax		pos;
	t_int_ax	check;

	pos_start.x = cub->player.x;
	pos_start.y = cub->player.y;
	if (key == S_KEY || key == W_KEY
		|| key == UP_KEY || key == DOWN_KEY)
		pos = s_w_colision(cub, key);
	if (key == A_KEY || key == D_KEY)
		pos = a_d_colision(cub, key);
	check.x = (int)(pos.x / TILESIZE);
	check.y = (int)(pos.y / TILESIZE);
	if (cub->map.parsing[check.y][check.x] == WALL)
		return (true);
	if (cub->map.parsing[((int)(pos_start.y / TILESIZE))][(check.x)] == WALL
		|| cub->map.parsing[(check.y)][(int)(pos_start.x / TILESIZE)] == WALL)
		return (true);
	return (false);
}
