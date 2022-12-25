/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 22:42:49 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/26 00:55:30 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	has_wall_at(double x, double y)
{
	int	x1;
	int	y1;

	x1 = (int)(x / TILESIZE);
	y1 = (int)(y / TILESIZE);
	if (x1 < 0 || x1 >= mapWidth || y1 < 0 || y1 >= mapHeight)
		return (true);
	if (map[y1][x1] == wall)
		return (true);
	return (false);
}

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

void	horizontal_intersection(t_player *player, t_ray *ray)
{
	ray->y_intercept = floor(player->y / TILESIZE) * TILESIZE - 1;
	if (!ray->is_facing_up)
		ray->y_intercept += TILESIZE;
	ray->x_intercept = player->x
		+ (ray->y_intercept - player->y) / tan(ray->angle);
	ray->y_step = TILESIZE;
	if (ray->is_facing_up)
		ray->y_step *= -1;
	ray->x_step = TILESIZE / tan(ray->angle);
	if ((ray->is_facing_right && ray->x_step < 0)
		|| (!ray->is_facing_right && ray->x_step > 0))
		ray->x_step *= -1;
	ray->next_horz_x = ray->x_intercept;
	ray->next_horz_y = ray->y_intercept;
	if (ray->is_facing_up)
		ray->next_horz_y--;
	else
		ray->next_horz_y++;
	while (ray->next_horz_x >= 0 && ray->next_horz_x <= mapWidth * TILESIZE	&& ray->next_horz_y >= 0 && ray->next_horz_y <= mapHeight * TILESIZE)
	{
		if (has_wall_at(ray->next_horz_x, ray->next_horz_y))
		{
			ray->horz_wall_hit_x = ray->next_horz_x;
			ray->horz_wall_hit_y = ray->next_horz_y;
			ray->hit_horz = true;
			break ;
		}
		else
		{
			ray->next_horz_x += ray->x_step;
			ray->next_horz_y += ray->y_step;
		}
	}
}

void	cast_rays(t_cub *cub)
{
	t_ray		ray;
	t_player	player;

	player = cub->player;
	ray = cub->ray;
	ray.angle = player.rot_angle - player.fov / 2;
	ray.angle = normalize_angle(ray.angle);
	printf("ray.rot_angle = %f\n", ray.angle);
	if (ray.angle >= 0 && ray.angle < M_PI)
		ray.is_facing_up = false;
	else
		ray.is_facing_up = true;
	if (ray.angle <= (M_PI / 2) || ray.angle > (3 * M_PI / 2))
		ray.is_facing_right = true;
	else
		ray.is_facing_right = false;
	ray.distance = 0;
	horizontal_intersection(&player, &ray);
	// printf("ray is facing up: %d\n", ray.is_facing_up);
	// printf("raay is facing right: %d\n", ray.is_facing_right);
	draw_line(player.x, player.y, ray.horz_wall_hit_x, ray.horz_wall_hit_y, cub);
	// cast_ray(cub, i);
}
