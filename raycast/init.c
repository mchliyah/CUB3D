/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:08:39 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/27 20:08:06 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_ray(t_ray *ray)
{
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
