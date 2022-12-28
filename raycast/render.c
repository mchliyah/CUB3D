/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:21:26 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/28 08:13:59 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	render_square(t_cub *cub, t_ax pos, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < TILESIZE * SCL)
	{
		j = -1;
		while (++j < TILESIZE * SCL)
			my_mlx_pixel_put(&cub->window, pos.x * TILESIZE * SCL
				+ j, pos.y * TILESIZE * SCL + i, color);
		i++;
	}
}

void	render_mini_map(t_cub *cub)
{
	t_ax	pos;
	int		i;

	pos.x = 0;
	pos.y = 0;
	while (pos.y < mapHeight)
	{
		pos.x = 0;
		while (pos.x < mapWidth)
		{
			if (map[pos.y][pos.x] == WALL)
				render_square(cub, pos, gray);
			else if (map[pos.y][pos.x] == empty
				|| map[pos.y][pos.x] == cub->player.symbol)
				render_square(cub, pos, white);
			pos.x++;
		}
		pos.y++;
	}
	i = -1;
	while (++i < X)
		draw_line(cub->player.x * SCL, cub->player.y * SCL,
			cub->ray[i].wall_hit_x * SCL, cub->ray[i].wall_hit_y * SCL, cub);
}

void	draw_wall(t_cub *cub, int i, double wall_height, int color)
{
	int		j;
	int		wall_top_pixel;
	int		wall_bottom_pixel;

	j = -1;
	while (++j < Y / 2 - (wall_height / 2))
		my_mlx_pixel_put(&cub->window, i, j, aqua);
	j = Y / 2 + (wall_height / 2) - 1;
	while (++j < Y)
		my_mlx_pixel_put(&cub->window, i, j, maroon);
	wall_top_pixel = Y / 2 - (wall_height / 2);
	wall_bottom_pixel = Y / 2 + (wall_height / 2);
	j = wall_top_pixel;
	while (j < wall_bottom_pixel)
	{
		my_mlx_pixel_put(&cub->window, i, j, color);
		j++;
	}
}
// {
// 	double	x;
// 	double	y;

// 	x = i;
// 	y = Y / 2 - (wall_strip_height / 2);
// 	while (y < wall_strip_height)
// 	{
// 		my_mlx_pixel_put(&cub->window, x, y, green);
// 		y++;
// 	}
// 	x++;
// }

void	thre_d_projection(t_cub *cub, t_wall *wall)
{
	t_ray	ray;
	int		i;


	i = -1;
	while (++i < X)
	{
		ray = cub->ray[i];
		wall->distance = (Y / 2) / tan(cub->player.fov / 2);
		wall->correct_distance = ray.distance * cos(ray.angle - cub->player.rot_angle);
		wall->height = ((TILESIZE / wall->correct_distance) * wall->distance) * 2;
		wall->color = orange - 200 / wall->correct_distance;
		draw_wall(cub, i, wall->height, wall->color);
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
	cast_rays(cub);
	thre_d_projection(cub, &wall);
	render_mini_map(cub);
	events(cub);
	mlx_put_image_to_window(cub->window.mlx,
		cub->window.win, cub->window.img, 0, 0);
	return (0);
}
