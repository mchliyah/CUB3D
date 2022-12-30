/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:11:10 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/30 13:54:49 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/cub.h"

void	init_ray(t_ray *ray)
{
	ray->hit_horz = false;
	ray->hit_vert = false;
	ray->angle = normalize_angle(ray->angle);
	if (ray->angle > 0 && ray->angle < M_PI)
		ray->is_facing_up = false;
	else
		ray->is_facing_up = true;
	if (ray->angle < 0.5 * M_PI || ray->angle > 1.5 * M_PI)
		ray->is_facing_right = true;
	else
		ray->is_facing_right = false;
}

bool	init_mlx(t_cub *cub)
{
	cub->window.mlx = mlx_init();
	cub->window.win = mlx_new_window(cub->window.mlx, X, Y, "cub3D");
	cub->window.img = mlx_new_image(cub->window.mlx, X, Y);
	cub->window.img_adrs = mlx_get_data_addr(cub->window.img,
			&cub->window.bits_per_pixel, &cub->window.line_length,
			&cub->window.endian);
	return (true);
}

bool	init_player(t_cub *cub)
{
	get_player_pos(cub);
	cub->player.move[0] = -1;
	cub->player.move[1] = -1;
	cub->player.move[2] = -1;
	cub->player.fov = M_PI / 3;
	cub->player.speed_mov = 3;
	cub->player.speed_rot = 3 * (M_PI / 180);
	cub->player.rot_angle = M_PI_2;
	player_update(cub);
	return (true);
}
