/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:20:14 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/16 20:58:26 by mchliyah         ###   ########.fr       */
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

void move(int key, t_cub *cub)
{
	if (key == A_KEY)
		cub->player.x -= cub->player.speed_mov;
	if (key == D_KEY)
		cub->player.x += cub->player.speed_mov;
	if (key == W_KEY)
		cub->player.y -= cub->player.speed_mov;
	if (key == S_KEY)
		cub->player.y += cub->player.speed_mov;
}

void rotat(int key, t_cub *cub)
{
	if (key == LEFT_KEY)
	{
		cub->player.rot_angle -= 0.2;
		cub->player.dir_x = cos(cub->player.rot_angle) * 5;
		cub->player.dir_y = sin(cub->player.rot_angle) * 5;
	}
	if (key == RIGHT_KEY)
		cub->player.rot_angle += cub->player.speed_rot;
}

int	buttons(int key, t_cub *cub)
{
	if (key == 53)
		t_close(cub);
	move(key, cub);
	rotat(key, cub);
	mlx_destroy_image(cub->window.mlx, cub->window.img);
	cub->window.img = mlx_new_image(cub->window.mlx, X, Y);
	cub->window.img_adrs = mlx_get_data_addr(cub->window.img, &cub->window.bits_per_pixel, &cub->window.line_length, &cub->window.endian);
	render(cub);
	mlx_put_image_to_window(cub->window.mlx, cub->window.win, cub->window.img, 0, 0);
	return (0);
}