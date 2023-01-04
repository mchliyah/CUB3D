/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 01:55:47 by mchliyah          #+#    #+#             */
/*   Updated: 2023/01/04 22:35:35 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/cub.h"

double	normalize_angle(double angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	else if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

void	a_d_events(t_cub *cub)
{
	if (cub->player.move[0] == D_KEY)
	{
		if (!colision(cub, D_KEY))
		{
			cub->player.y += cub->player.speed_mov
				* sin(cub->player.rot_angle + M_PI_2);
			cub->player.x += cub->player.speed_mov
				* cos(cub->player.rot_angle + M_PI_2);
		}
	}
	else if (cub->player.move[0] == A_KEY)
	{
		if (!colision(cub, A_KEY))
		{
			cub->player.y += cub->player.speed_mov
				* sin(cub->player.rot_angle - M_PI_2);
			cub->player.x += cub->player.speed_mov
				* cos(cub->player.rot_angle - M_PI_2);
		}
	}
}

void	s_w_events(t_cub *cub)
{
	if (cub->player.move[1] == S_KEY || cub->player.move[1] == DOWN_KEY)
	{
		if (!colision(cub, S_KEY))
		{
			cub->player.y -= cub->player.speed_mov * sin(cub->player.rot_angle);
			cub->player.x -= cub->player.speed_mov * cos(cub->player.rot_angle);
		}
	}
	else if (cub->player.move[1] == W_KEY || cub->player.move[1] == UP_KEY)
	{
		if (!colision(cub, W_KEY))
		{
			cub->player.y += cub->player.speed_mov * sin(cub->player.rot_angle);
			cub->player.x += cub->player.speed_mov * cos(cub->player.rot_angle);
		}
	}
}

void	events(t_cub *cub)
{
	if (cub->player.move[0] == D_KEY || cub->player.move[0] == A_KEY)
		a_d_events(cub);
	if (cub->player.move[1] == S_KEY || cub->player.move[1] == W_KEY
		|| cub->player.move[1] == UP_KEY || cub->player.move[1] == DOWN_KEY)
		s_w_events(cub);
	if (cub->player.move[2] == LEFT_KEY)
	{
		cub->player.rot_angle -= cub->player.speed_rot;
		cub->player.rot_angle = normalize_angle(cub->player.rot_angle);
	}
	else if (cub->player.move[2] == RIGHT_KEY)
	{
		cub->player.rot_angle += cub->player.speed_rot;
		cub->player.rot_angle = normalize_angle(cub->player.rot_angle);
	}
}

int	mouse_event(int x, int y, t_cub *cub)
{
	(void)y;
	if (x > cub->player.mouse_x)
	{
		cub->player.move[2] = RIGHT_KEY;
		cub->player.turn_key = false;
	}
	else if (x < cub->player.mouse_x)
	{
		cub->player.move[2] = LEFT_KEY;
		cub->player.turn_key = false;
	}
	cub->player.mouse_x = x;
	if (x < 0 || x > X || y < 0 || y > Y)
		mlx_mouse_move(cub->window.win, X / 2, Y / 2);
	return (0);
}
