/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:11:10 by mchliyah          #+#    #+#             */
/*   Updated: 2023/01/05 20:15:16 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../includes/cub.h"

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

bool	init_xpm(t_cub *cub, void *path, t_textur *textur)
{
	textur->img = mlx_xpm_file_to_image(cub->window.mlx, path,
			&textur->width, &textur->height);
	if (!textur->img)
		return (false);
	textur->img_adrs = mlx_get_data_addr(textur->img, &textur->bits_per_pixel,
			&textur->line_length, &textur->endian);
	return (true);
}

bool	init_mlx(t_cub *cub)
{
	cub->window.mlx = mlx_init();
	cub->window.win = mlx_new_window(cub->window.mlx, X, Y, "cub3D");
	cub->window.img = mlx_new_image(cub->window.mlx, X, Y);
	cub->window.img_adrs = mlx_get_data_addr(cub->window.img,
			&cub->window.bits_per_pixel, &cub->window.line_length,
			&cub->window.endian);
	if (!init_xpm(cub, cub->map.no, &cub->no))
		return (false);
	if (!init_xpm(cub, cub->map.so, &cub->so))
		return (false);
	if (!init_xpm(cub, cub->map.we, &cub->we))
		return (false);
	if (!init_xpm(cub, cub->map.ea, &cub->ea))
		return (false);
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
	cub->player.speed_mov = 2.5;
	cub->player.speed_rot = 1.2 * (M_PI / 180);
	if (cub->player.symbol == 'N')
		cub->player.rot_angle = M_PI / 2;
	else if (cub->player.symbol == 'S')
		cub->player.rot_angle = 3 * M_PI / 2;
	else if (cub->player.symbol == 'W')
		cub->player.rot_angle = 0;
	else
		cub->player.rot_angle = M_PI;
	player_update(cub);
	return (true);
}
     