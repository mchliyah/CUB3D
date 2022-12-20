/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:21:26 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/20 20:56:33 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	render_square(t_cub *cub, t_ax pos, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < TILESIZE - 1)
	{
		j = -1;
		while (++j < TILESIZE - 1)
			my_mlx_pixel_put(&cub->window, pos.x * TILESIZE
				+ j, pos.y * TILESIZE + i, color);
		i++;
	}
}

bool	is_wall(t_cub *cub, double x, double y)
{
	int	x_start;
	int	y_start;
	int	x_end;
	int	y_end;

	x_start = (int)(x / TILESIZE);
	y_start = (int)(y / TILESIZE);
	x_end = (int)((x + cos(cub->player.fov) * 0.1) / TILESIZE);
	y_end = (int)((y + sin(cub->player.fov) * 0.1) / TILESIZE);
	if (map[y_start][x_start] == wall)
		return (true);
	if (map[y_start][x_end] == wall || map[y_end][x_start] == wall)
		return (true);
	return (false);
}

void	render_ray(t_cub *cub)
{
	double	x;
	double	y;

	x = cub->player.x;
	y = cub->player.y;
	while (!is_wall(cub, x, y))
	{
		x += cos(cub->player.fov) * 0.1;
		y += sin(cub->player.fov) * 0.1;
		my_mlx_pixel_put(&cub->window, x, y, red);
	}
}

void	render_player(t_cub *cub)
{
	double	i;
	double	j;

	j = cub->player.y - 2;
	cub->player.fov = cub->player.rot_angle - M_PI / 6;
	while (j < cub->player.y + 2)
	{
		i = cub->player.x - 2;
		while (i < cub->player.x + 2)
		{
			my_mlx_pixel_put(&cub->window, i, j, blue);
			i++;
		}
		j++;
	}
	while (cub->player.fov < cub->player.rot_angle + M_PI / 6)
	{
		render_ray(cub);
		cub->player.fov += M_PI / 200;
	}
}

int	render(t_cub *cub)
{
	t_ax	pos;

	pos.x = 0;
	pos.y = 0;
	while (pos.y < mapHeight)
	{
		pos.x = 0;
		while (pos.x < mapWidth)
		{
			if (map[pos.y][pos.x] == wall)
				render_square(cub, pos, gray);
			else if (map[pos.y][pos.x] == empty
				|| map[pos.y][pos.x] == cub->player.symbol)
				render_square(cub, pos, white);
			pos.x++;
		}
		pos.y++;
	}
	render_player(cub);
	events(cub);
	mlx_put_image_to_window(cub->window.mlx,
		cub->window.win, cub->window.img, 0, 0);
	return (0);
}
