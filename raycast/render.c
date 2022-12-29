/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:21:26 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/28 22:34:25 by mchliyah         ###   ########.fr       */
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

void	render_player(t_cub *cub)
{
	int	i;
	int	j;

	i = cub->player.y * SCL - 2;
	while (i < cub->player.y * SCL + 2)
	{
		j = cub->player.x * SCL - 2;
		while (++j < cub->player.x * SCL + 2)
			my_mlx_pixel_put(&cub->window, j, i, RED);
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
			if (map[(int)pos.y][(int)pos.x] == WALL)
				render_square(cub, pos, GRAY);
			else if (map[(int)pos.y][(int)pos.x] == EMPTY
				|| map[(int)pos.y][(int)pos.x] == cub->player.symbol)
				render_square(cub, pos, WHITE);
			pos.x++;
		}
		pos.y++;
	}
	render_player(cub);
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
		my_mlx_pixel_put(&cub->window, i, j, AQUA);
	j = Y / 2 + (wall_height / 2) - 1;
	while (++j < Y)
		my_mlx_pixel_put(&cub->window, i, j, BROWN);
	wall_top_pixel = Y / 2 - (wall_height / 2);
	if (wall_top_pixel < 0)
		wall_top_pixel = 0;
	wall_bottom_pixel = Y / 2 + (wall_height / 2);
	if (wall_bottom_pixel > Y)
		wall_bottom_pixel = Y;
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

	i = -1;
	while (++i < X)
	{
		ray = cub->ray[i];
		wall->distance = (Y / 2) / tan(cub->player.fov / 2);
		if (wall->distance < 15)
			wall->distance = 15;
		wall->correct_dist = ray.distance
			* cos(ray.angle - cub->player.rot_angle);
		wall->height = ((TILESIZE / wall->correct_dist) * wall->distance) * 2;
		wall->color = ORANGE - 200 / wall->correct_dist;
		draw_wall(cub, i, wall->height, wall->color);
	}
}

void	player_update(t_cub *cub)
{
	if (cub->player.rot_angle > 0 && cub->player.rot_angle < M_PI)
		cub->player.facing_up = false;
	else
		cub->player.facing_up = true;
	if (cub->player.rot_angle < 0.5 * M_PI || cub->player.rot_angle > 1.5 * M_PI)
		cub->player.facing_right = true;
	else
		cub->player.facing_right = false;

}

int	render(t_cub *cub)
{
	t_wall	wall;

	
	player_update(cub);
	cast_rays(cub);
	thre_d_projection(cub, &wall);
	render_mini_map(cub);
	events(cub);
	mlx_put_image_to_window(cub->window.mlx,
		cub->window.win, cub->window.img, 0, 0);
	return (0);
}
 