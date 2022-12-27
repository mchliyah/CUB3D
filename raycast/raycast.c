/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 22:42:49 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/27 02:52:18 by mchliyah         ###   ########.fr       */
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

double	distance(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	horizontal_intersection(t_player *player, t_ray *ray)
{
	ray->y_intercept = floor(player->y / TILESIZE) * TILESIZE;
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
			ray->horz_hit_x = ray->next_horz_x;
			ray->horz_hit_y = ray->next_horz_y;
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

void	vertical_intersection(t_player *player, t_ray *ray)
{
	ray->x_intercept = floor(player->x / TILESIZE) * TILESIZE;
	if (ray->is_facing_right)
		ray->x_intercept += TILESIZE;
	ray->y_intercept = player->y
		+ (ray->x_intercept - player->x) * tan(ray->angle);
	ray->x_step = TILESIZE;
	if (!ray->is_facing_right)
		ray->x_step *= -1;
	ray->y_step = TILESIZE * tan(ray->angle);
	if ((ray->is_facing_up && ray->y_step > 0)
		|| (!ray->is_facing_up && ray->y_step < 0))
		ray->y_step *= -1;
	ray->next_vert_x = ray->x_intercept;
	ray->next_vert_y = ray->y_intercept;
	if (!ray->is_facing_right)
		ray->next_vert_x--;
	else
		ray->next_vert_x++;
	while (ray->next_vert_x >= 0 && ray->next_vert_x <= mapWidth * TILESIZE	&& ray->next_vert_y >= 0 && ray->next_vert_y <= mapHeight * TILESIZE)
	{
		if (has_wall_at(ray->next_vert_x, ray->next_vert_y))
		{
			ray->vert_hit_x = ray->next_vert_x;
			ray->vert_hit_y = ray->next_vert_y;
			ray->hit_vert = true;
			break ;
		}
		else
		{
			ray->next_vert_x += ray->x_step;
			ray->next_vert_y += ray->y_step;
		}
	}
}

void	cast_rays(t_cub *cub)
{
	t_ray		ray;
	t_player	player;
	int			i;
	double		h_distance;
	double		v_distance;

	player = cub->player;
	ray = cub->ray;
	init_ray(&ray, &player);
	i = 0;
	while (i < 50)
	{
		ray.hit_horz = false;
		ray.hit_vert = false;
		horizontal_intersection(&player, &ray);
		h_distance = distance(player.x, player.y, ray.horz_hit_x, ray.horz_hit_y);
		vertical_intersection(&player, &ray);
		v_distance = distance(player.x, player.y, ray.vert_hit_x, ray.vert_hit_y);
		if (h_distance < v_distance)
			draw_line(player.x, player.y, ray.horz_hit_x, ray.horz_hit_y, cub);
		else
			draw_line(player.x, player.y, ray.vert_hit_x, ray.vert_hit_y, cub);
		ray.angle += player.fov / 50;
		ray.angle = normalize_angle(ray.angle);
		i++;
	}
}
