/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 22:42:49 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/25 20:56:25 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	has_wall_at(t_cub *cub, double x, double y)
{
	int	x1;
	int	y1;

	(void)cub;
	x1 = (int)(x / TILESIZE);
	y1 = (int)(y / TILESIZE);
	if (x1 < 0 || x1 >= mapWidth || y1 < 0 || y1 >= mapHeight)
		return (true);
	if (map[y1][x1] == wall)
		return (true);
	return (false);
}

// void	ray_facing_up(t_cub *cub, int i)
// {
// 	if (cub->ray->angle > 0 && cub->ray->angle < M_PI)
// 	{
// 		cub->ray[i].is_facing_up = true;
// 		cub->ray[i].is_facing_down = false;
// 		cub->ray[i].y_intercept = floor(cub->player.y / TILESIZE) * TILESIZE;
// 		cub->ray[i].y_intercept -= 1;
// 		cub->ray[i].x_intercept = cub->player.x + (cub->player.y
// 				- cub->ray->y_intercept) / tan(cub->ray->angle);
// 		cub->ray->y_step = -TILESIZE;
// 		cub->ray->x_step = -TILESIZE / tan(cub->ray->angle);
// 	}
// }

void	draw_line(double x1, double y1, double x2, double y2, t_cub *cub)
{
	double	delta_x;
	double	delta_y;
	double	step;
	double	x;
	double	y;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	if (fabs(delta_x) > fabs(delta_y))
		step = fabs(delta_x);
	else
		step = fabs(delta_y);
	delta_x /= step;
	delta_y /= step;
	x = x1;
	y = y1;
	if (step > 1000)
		step = 1000;
	while (step > 0)
	{
		my_mlx_pixel_put(&cub->window, x, y, red);
		x += delta_x;
		y += delta_y;
		step--;
	}
}

void	first_up_intercept(t_cub *cub, double x_step, double y_interc, int i)
{
	cub->ray[i].y_step = -TILESIZE;
	if (!cub->ray[i].is_facing_left)
	{
		cub->ray[i].x_step = x_step;
		cub->ray[i].y_intercept = y_interc + TILESIZE;
		cub->ray[i].x_intercept = cub->player.x + (cub->player.y
				- cub->ray[i].y_intercept) / tan(cub->ray[i].angle);
	}
	else if (cub->ray[i].is_facing_left)
	{
		cub->ray[i].x_step = -x_step;
		cub->ray[i].y_intercept = y_interc - TILESIZE;
		cub->ray[i].x_intercept = cub->player.x + (cub->player.y
				- cub->ray[i].y_intercept) / tan(cub->ray[i].angle);
	}
}

void	first_down_intercept(t_cub *cub, double x_step, double y_interc, int i)
{
	cub->ray[i].y_step = TILESIZE;
	if (!cub->ray[i].is_facing_left)
	{
		cub->ray[i].x_step = x_step;
		cub->ray[i].y_intercept = y_interc + TILESIZE;
		cub->ray[i].x_intercept = cub->player.x + (cub->player.y
				- cub->ray[i].y_intercept) / tan(cub->ray[i].angle);
	}
	else if (cub->ray[i].is_facing_left)
	{
		cub->ray[i].x_step = -x_step;
		cub->ray[i].y_intercept = y_interc + TILESIZE;
		cub->ray[i].x_intercept = cub->player.x + (cub->player.y
				- cub->ray[i].y_intercept) / tan(cub->ray[i].angle);
	}
}

void	cast_ray(t_cub *cub, int i)
{
	double	x_step;
	double	y_intercept;

	x_step = TILESIZE / tan(cub->ray[i].angle);
	y_intercept = floor(cub->player.y / TILESIZE) * TILESIZE;
	if (cub->ray[i].is_facing_up)
		first_up_intercept(cub, x_step, y_intercept, i);
	else
		first_down_intercept(cub, x_step, y_intercept, i);
	cub->ray[i].next_vert_x = cub->ray[i].x_intercept;
	cub->ray[i].next_vert_y = cub->ray[i].y_intercept;

	cub->ray[i].wall_hit_x = cub->ray[i].next_vert_x;
	cub->ray[i].wall_hit_y = cub->ray[i].next_vert_y;
	// while (!cub->ray[i].hit_vert_wall)
	// {
	// 	if (has_wall_at(cub, cub->ray[i].next_vert_x, cub->ray[i].next_vert_y))
	// 	{
	// 		cub->ray[i].hit_vert_wall = true;
	// 		cub->ray[i].wall_hit_x = cub->ray[i].next_vert_x;
	// 		cub->ray[i].wall_hit_y = cub->ray[i].next_vert_y;
	// 	}
	// 	else
	// 	{
	// 		cub->ray[i].next_vert_x += cub->ray[i].x_step;
	// 		cub->ray[i].next_vert_y += cub->ray[i].y_step;
	// 	}
	// }
	draw_line(cub->player.x, cub->player.y, cub->ray[i].wall_hit_x,
		cub->ray[i].wall_hit_y, cub);
}

void	ray_derection(t_cub *cub, int i)
{
	cub->ray[i].is_facing_up = false;
	cub->ray[i].is_facing_left = false;
	if (cub->ray[i].angle < M_PI_2 || cub->ray[i].angle >= 3 * M_PI_2)
		cub->ray[i].is_facing_left = true;
	if (cub->ray[i].angle > 0 && cub->ray[i].angle <= M_PI)
		cub->ray[i].is_facing_up = true;
}

void	cast_rays(t_cub *cub)
{
	int	i;

	cub->ray[0].angle = cub->player.rot_angle - (M_PI / 6);
	cub->ray[0].angle = normalize_angle(cub->ray[0].angle);
	cub->ray[0].hit_vert_wall = false;
	cub->ray[0].hit_horz_wall = false;
	ray_derection(cub, 0);
	i = 0;
	// while (++i < X)
	// {
	// 	cub->ray[i].angle = cub->ray[i - 1].angle + cub->player.fov / X;
	// 	cub->ray[i].angle = normalize_angle(cub->ray[i].angle);
	// 	cub->ray[i].hit_vert_wall = false;
	// 	cub->ray[i].hit_horz_wall = false;
	// 	ray_derection(cub, i);
	// }
	// i = -1;
	// while (++i < X)
		cast_ray(cub, i);
}
