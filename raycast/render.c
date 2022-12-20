/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:21:26 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/20 02:17:33 by mchliyah         ###   ########.fr       */
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

void	calulat_dx_dy(t_cub *cub)
{
	cub->ray.dx = fabs(1 / cos(cub->player.fov));
	cub->ray.dy = fabs(1 / sin(cub->player.fov));
	cub->ray.sx = cos(cub->player.fov) < 0 ? -1 : 1;
	cub->ray.sy = sin(cub->player.fov) < 0 ? -1 : 1;
}

double	dda(t_cub *cub)
{
	calulat_dx_dy(cub);
	while (1)
	{
		if (cub->ray.dx < cub->ray.dy)
		{
			cub->ray.dx += cub->ray.dx;
			cub->ray.x_start += cub->ray.sx;
		}
		else
		{
			cub->ray.dy += cub->ray.dy;
			cub->ray.y_start += cub->ray.sy;
		}
		if (map[(int)cub->ray.y_start / TILESIZE][(int)cub->ray.x_start / TILESIZE] == wall)
			break ;
	}
	return (cub->ray.len);
}

void	get_cordinates(t_cub *cub)
{
	cub->ray.x_start = cub->player.x;
	cub->ray.y_start = cub->player.y;
	dda(cub);
	cub->ray.x_end = cub->player.x
		+ (cub->ray.len * cos(cub->player.fov));
	cub->ray.y_end = cub->player.y
		+ (cub->ray.len * sin(cub->player.fov));
	cub->ray.dx = abs(cub->ray.x_end - cub->ray.x_start);
	cub->ray.dy = abs(cub->ray.y_end - cub->ray.y_start);
	if (cub->ray.x_start < cub->ray.x_end)
		cub->ray.sx = 1;
	else
		cub->ray.sx = -1;
	if (cub->ray.y_start < cub->ray.y_end)
		cub->ray.sy = 1;
	else
		cub->ray.sy = -1;
	if (cub->ray.dx > cub->ray.dy)
		cub->ray.err = cub->ray.dx / 2;
	else
		cub->ray.err = -cub->ray.dy / 2;
}

void	render_ray(t_cub *cub)
{
	get_cordinates(cub);
	while (1)
	{
		my_mlx_pixel_put(&cub->window, cub->ray.x_start,
			cub->ray.y_start, red);
		if (cub->ray.x_start == cub->ray.x_end
			&& cub->ray.y_start == cub->ray.y_end)
			break ;
		cub->ray.e2 = cub->ray.err;
		if (cub->ray.e2 > -cub->ray.dx)
		{
			cub->ray.err -= cub->ray.dy;
			cub->ray.x_start += cub->ray.sx;
		}
		if (cub->ray.e2 < cub->ray.dy)
		{
			cub->ray.err += cub->ray.dx;
			cub->ray.y_start += cub->ray.sy;
		}
	}
}

void	ray_casting(t_cub *cub)
{
	while (cub->player.fov < cub->player.rot_angle + M_PI / 6)
	{
		render_ray(cub);
		cub->player.fov += M_PI / 180;
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
	ray_casting(cub);
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
