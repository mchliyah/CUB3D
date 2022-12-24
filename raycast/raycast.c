/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 22:42:49 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/25 00:51:42 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// bool	is_wall(t_cub *cub, double x, double y)
// {
// 	int	x_start;
// 	int	y_start;
// 	int	x_end;
// 	int	y_end;

// 	x_start = (int)(x / TILESIZE);
// 	y_start = (int)(y / TILESIZE);
// 	x_end = (int)((x + cos(cub->ray->angle) * 0.1) / TILESIZE);
// 	y_end = (int)((y + sin(cub->ray->angle) * 0.1) / TILESIZE);
// 	if (map[y_start][x_start] == wall)
// 		return (true);
// 	if (map[y_start][x_end] == wall || map[y_end][x_start] == wall)
// 		return (true);
// 	return (false);
// }

void	ray_is_facing_up(t_cub *cub, int i)
{
	if (cub->ray->angle > 0 && cub->ray->angle < M_PI)
	{
		cub->ray[i].is_facing_up = true;
		cub->ray[i].is_facing_down = false;
		cub->ray[i].y_intercept = floor(cub->player.y / TILESIZE) * TILESIZE;
		cub->ray[i].y_intercept -= 1;
		cub->ray[i].x_intercept = cub->player.x + (cub->player.y
				- cub->ray->y_intercept) / tan(cub->ray->angle);
		cub->ray->y_step = -TILESIZE;
		cub->ray->x_step = -TILESIZE / tan(cub->ray->angle);
	}
}

void	get_intersept(t_cub *cub, int i)
{
    if (cub->ray[i].angle > 0 && cub->ray[i].angle < M_PI_2)
	    ray_is_facing_down(cub, i);
    if (cub->ray[i].angle > M_PI_2 && cub->ray[i].angle < M_PI)
        ray_is_facing_up(cub, i);
    if (cub->ray[i].angle > M_PI && cub->ray[i].angle < 3 * M_PI_2)
        ray_is_facing_up(cub, i);
    if (cub->ray[i].angle > 3 * M_PI_2 && cub->ray[i].angle < 2 * M_PI)
        ray_is_facing_down(cub, i);
		ray_is_facing_left(cub, i);
		ray_is_facing_right(cub, i);
	horizontal_intersection(cub, i);
	vertical_intersection(cub, i);
}

void	cast_ray(t_cub *cub, int i)
{
	get_intersept(cub, i);
	// double	x;
	// double	y;
	// // double	ray_dist;

	// x = cub->player.x;
	// y = cub->player.y;
	// (void)i;
	// while (!is_wall(cub, x, y))
	// {
	// 	x += cos(cub->ray->angle) * 0.1;
	// 	y += sin(cub->ray->angle) * 0.1;
	// 	my_mlx_pixel_put(&cub->window, x, y, red);
	// }
}

void	cast_rays(t_cub *cub)
{
	int	i;

	cub->ray[0].angle = cub->player.rot_angle - M_PI / 6;
    i = 0;
    while (++i < X)
		cub->ray[i].angle = cub->ray[i - 1].angle + cub->player.fov / X;
	i = -1;
	while (++i < X)
		cast_ray(cub, i);
}
