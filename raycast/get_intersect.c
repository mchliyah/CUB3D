/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 02:26:40 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/30 13:54:52 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/cub.h"

bool	has_wall_at(t_cub *cub, double x, double y)
{
	int	x1;
	int	y1;

	x1 = floor(x / TILESIZE);
	y1 = floor(y / TILESIZE);
	if (x1 < 0 || x1 >= cub->map.map_width || y1 < 0 || y1 >= cub->map.map_height)
		return (true);
	if (cub->map.parsing[y1][x1] == WALL)
		return (true);
	return (false);
}

void	get_first_horz_intersection(t_player *player, t_ray *ray)
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
	if ((ray->is_facing_right && ray->x_step < 0))
		ray->x_step *= -1;
	if (!ray->is_facing_right && ray->x_step > 0)
		ray->x_step *= -1;
	ray->next_horz_x = ray->x_intercept;
	ray->next_horz_y = ray->y_intercept;
}

void	horizontal_intersection(t_cub *cub, t_player *player, t_ray *ray)
{
	int	i;

	get_first_horz_intersection(player, ray);
	while (ray->next_horz_x >= 0 && ray->next_horz_x <= cub->map.map_width * TILESIZE
		&& ray->next_horz_y >= 0 && ray->next_horz_y <= cub->map.map_height * TILESIZE)
	{
		i = 0;
		if (ray->is_facing_up)
			i = 1;
		if (has_wall_at(cub, ray->next_horz_x, ray->next_horz_y - i))
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

void	get_first_vert_intersect(t_player *player, t_ray *ray)
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
	if ((ray->is_facing_up && ray->y_step > 0))
		ray->y_step *= -1;
	if (!ray->is_facing_up && ray->y_step < 0)
		ray->y_step *= -1;
	ray->next_vert_x = ray->x_intercept;
	ray->next_vert_y = ray->y_intercept;
}

void	vertical_intersection(t_cub *cub, t_player *player, t_ray *ray)
{
	int	i;

	get_first_vert_intersect(player, ray);
	while (ray->next_vert_x >= 0 && ray->next_vert_x <= cub->map.map_width * TILESIZE
		&& ray->next_vert_y >= 0 && ray->next_vert_y <= cub->map.map_height * TILESIZE)
	{
		i = 0;
		if (!ray->is_facing_right)
		i = 1;
		if (has_wall_at(cub, ray->next_vert_x - i, ray->next_vert_y))
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
