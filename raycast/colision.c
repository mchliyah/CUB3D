/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 01:56:32 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/19 15:26:09 by mchliyah         ###   ########.fr       */
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
	t_ax	pos_start;
	t_ax	pos;

	pos_start.x = cub->player.x;
	pos_start.y = cub->player.y;
	if (key == S_KEY || key == W_KEY)
		pos = s_w_colision(cub, key);
	if (key == A_KEY || key == D_KEY)
		pos = a_d_colision(cub, key);
	if (map[pos.y / (TILESIZE)][pos.x / (TILESIZE)] == wall)
		return (true);
	if (map[pos_start.y / (TILESIZE)][pos.x / (TILESIZE)] == wall || map[pos.y
			/ (TILESIZE)][pos_start.x / (TILESIZE)] == wall)
		return (true);
	return (false);
}
