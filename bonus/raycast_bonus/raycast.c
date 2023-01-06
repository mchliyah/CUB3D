/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 22:42:49 by mchliyah          #+#    #+#             */
/*   Updated: 2023/01/05 14:47:03 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../includes/cub.h"

double	distance(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	set_ray_distance(t_player *player, t_ray *ray)
{
	ray->h_distance = distance(player->x, player->y,
			ray->horz_hit_x, ray->horz_hit_y);
	if (!ray->hit_horz)
		ray->h_distance = INT_MAX;
	ray->v_distance = distance(player->x, player->y,
			ray->vert_hit_x, ray->vert_hit_y);
	if (!ray->hit_vert)
		ray->v_distance = INT_MAX;
	if (ray->h_distance < ray->v_distance)
	{
		ray->distance = ray->h_distance;
		ray->wall_hit_x = ray->horz_hit_x;
		ray->wall_hit_y = ray->horz_hit_y;
		ray->hit_horz = true;
		ray->hit_vert = false;
	}
	else
	{
		ray->distance = ray->v_distance;
		ray->wall_hit_x = ray->vert_hit_x;
		ray->wall_hit_y = ray->vert_hit_y;
		ray->hit_vert = true;
		ray->hit_horz = false;
	}
}

void	cast_ray(t_cub *cub, t_player *player, t_ray *ray, int i)
{
	init_ray(&ray[i]);
	horizontal_intersection(cub, player, &ray[i]);
	vertical_intersection(cub, player, &ray[i]);
	set_ray_distance(player, &ray[i]);
	if (i + 1 < X)
		ray[i + 1].angle = ray[i].angle + player->fov / X;
}

void	cast_rays(t_cub *cub)
{
	t_ray		*ray;
	t_player	player;
	int			i;

	player = cub->player;
	ray = cub->ray;
	ray[0].angle = player.rot_angle - (player.fov / 2);
	i = -1;
	while (++i < X)
		cast_ray(cub, &player, ray, i);
}
