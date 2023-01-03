/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:11:10 by mchliyah          #+#    #+#             */
/*   Updated: 2023/01/03 10:08:51 by mchliyah         ###   ########.fr       */
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
	int	i;

	cub->window.mlx = mlx_init();
	cub->window.win = mlx_new_window(cub->window.mlx, X, Y, "cub3D");
	cub->window.img = mlx_new_image(cub->window.mlx, X, Y);
	cub->window.img_adrs = mlx_get_data_addr(cub->window.img,
			&cub->window.bits_per_pixel, &cub->window.line_length,
			&cub->window.endian);
	cub->no.img = mlx_xpm_file_to_image(cub->window.mlx, cub->map.no, &i, &i);
	cub->no.img_adrs = mlx_get_data_addr(cub->no.img,
			&cub->no.bits_per_pixel, &cub->no.line_length,
			&cub->no.endian);
	cub->ea.img = mlx_xpm_file_to_image(cub->window.mlx, cub->map.ea, &i, &i);
	cub->ea.img_adrs = mlx_get_data_addr(cub->ea.img,
			&cub->ea.bits_per_pixel, &cub->ea.line_length,
			&cub->ea.endian);
	cub->we.img = mlx_xpm_file_to_image(cub->window.mlx, cub->map.we, &i, &i);
	cub->we.img_adrs = mlx_get_data_addr(cub->we.img,
			&cub->we.bits_per_pixel, &cub->we.line_length,
			&cub->we.endian);
	cub->so.img = mlx_xpm_file_to_image(cub->window.mlx, cub->map.so, &i, &i);
	cub->so.img_adrs = mlx_get_data_addr(cub->so.img,
			&cub->so.bits_per_pixel, &cub->so.line_length,
			&cub->so.endian);
	return (true);
}

void	set_map_width(t_cub *cub)
{
	int	i;
	int	j;

	i = cub->map.valid_i;
	cub->map.width = 0;
	while (i < cub->map.height)
	{
		j = 0;
		while (cub->map.parsing[i][j])
			j++;
		if (j > cub->map.width)
			cub->map.width = j;
		i++;
	}
}

bool	init_player(t_cub *cub)
{
	set_map_width(cub);
	get_player_pos(cub);
	cub->player.move[0] = -1;
	cub->player.move[1] = -1;
	cub->player.move[2] = -1;
	cub->player.mouse_x = 0;
	cub->player.mouse_y = 0;
	cub->player.fov = M_PI / 3;
	cub->player.speed_mov = 2.2;
	cub->player.speed_rot = 1.2 * (M_PI / 180);
	cub->player.rot_angle = M_PI_2;
	player_update(cub);
	return (true);
}
