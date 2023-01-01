/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:21:26 by mchliyah          #+#    #+#             */
/*   Updated: 2023/01/01 18:38:17 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/cub.h"

// int	get_color(char *textur)
// {

// }

void	render_wall(t_cub *cub, int i, double wall_hheight, int color)
{
	int		j;
	int		wall_top_pixel;
	int		wall_bottom_pixel;

	wall_top_pixel = Y / 2 - (wall_hheight / 2);
	wall_bottom_pixel = Y / 2 + (wall_hheight / 2);
	if (wall_top_pixel < 0)
		wall_top_pixel = 0;
	if (wall_bottom_pixel > Y)
		wall_bottom_pixel = Y;
	j = -1;
	while (++j < wall_top_pixel)
		my_mlx_pixel_put(&cub->window, i, j, cub->map.ceiling);
	j = wall_bottom_pixel - 1;
	while (++j < Y)
		my_mlx_pixel_put(&cub->window, i, j, cub->map.floor);
	j = wall_top_pixel;
	while (j < wall_bottom_pixel)
	{
		my_mlx_pixel_put(&cub->window, i, j, color);
		j++;
	}
}

void	thre_d_projection(t_cub *cub, t_wall *wall)
{
	t_ray	ray;
	int		i;
	int     color;

	i = -1;
	while (++i < X)
	{
		ray = cub->ray[i];
		wall->distance = (Y / 2) / tan(cub->player.fov / 2);
		// if (wall->distance < 15)
		// 	wall->distance = 15;
		wall->correct_dist = ray.distance
			* cos(ray.angle - cub->player.rot_angle);
		wall->hheight = ((TILESIZE / wall->correct_dist) * wall->distance);
		if (ray.hit_vert && !ray.is_facing_right)
			color = ORANGE;
		else if (ray.hit_vert && ray.is_facing_right)
			color = BLUE;
		else if (ray.hit_horz && !ray.is_facing_up)
			color = BLACK;
		else if (ray.hit_horz && ray.is_facing_up)
			color = GREEN;
		render_wall(cub, i, wall->hheight, color);
	}
}

int	render(t_cub *cub)
{
	t_wall	wall;

	mlx_destroy_image(cub->window.mlx, cub->window.img);
	cub->window.img = mlx_new_image(cub->window.mlx, X, Y);
	cub->window.img_adrs = mlx_get_data_addr(cub->window.img,
			&cub->window.bits_per_pixel, &cub->window.line_length,
			&cub->window.endian);
	player_update(cub);
	cast_rays(cub);
	thre_d_projection(cub, &wall);
	events(cub);
	mlx_put_image_to_window(cub->window.mlx,
		cub->window.win, cub->window.img, 0, 0);
	return (0);
}
