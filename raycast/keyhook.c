/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:20:14 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/17 22:42:57 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	t_close(t_cub *cub)
{
	mlx_destroy_image(cub->window.mlx, cub->window.img);
	mlx_destroy_window(cub->window.mlx, cub->window.win);
	exit(0);
	return (0);
}

void direction_move(int key, t_cub *cub)
{
	if (key == W_KEY || key == S_KEY)
		cub->player.move[1] = key;
	if(key == D_KEY || key == A_KEY)
		cub->player.move[0] = key;
	if (key == LEFT_KEY || key == RIGHT_KEY)
		cub->player.move[2] = key;
}
int	buttons_down(int key, t_cub *cub)
{
	if (key == 53)
		t_close(cub);
	direction_move(key, cub);
	return (0);
}

int	buttons_up(int key, t_cub *cub)
{
	if (key == A_KEY || key == D_KEY)
		cub->player.move[0] = -1;
	if (key == W_KEY || key == S_KEY)
		cub->player.move[1] = -1;
	if (key == LEFT_KEY || key == RIGHT_KEY)
		cub->player.move[2] = -1;
	return (0);
}

void keyhook_loop(t_cub *cub)
{
	mlx_hook(cub->window.win, ON_KEYDOWN, 1L << 0, buttons_down, cub);
	mlx_hook(cub->window.win, ON_KEYUP, 1L << 1, buttons_up, cub);
	mlx_hook(cub->window.win, ON_DESTROY, 1L << 17, t_close, cub);
	mlx_loop_hook(cub->window.mlx, render, cub);
	mlx_loop(cub->window.mlx);
}