/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:21:26 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/29 17:04:31 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	render_rays(t_cub *cub)
{
	t_ax	pos_end;
	int	i;

	i = -1;
	while (++i < X)
	{
		pos_end.x = cub->ray[i].wall_hit_x * SCL;
		pos_end.y = cub->ray[i].wall_hit_y * SCL;
		draw_line(cub->player.x * SCL, cub->player.y * SCL, pos_end, cub);
	}
}

void	render_mini_map(t_cub *cub)
{
	t_ax	pos;

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
	render_rays(cub);
}

void	render_wall(t_cub *cub, int i, double wall_height, int color)
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
		if (ray.hit_vert && ray.v_distance < ray.h_distance)
			wall->color = ORANGE;
		if (ray.hit_vert && ray.v_distance < ray.h_distance && ray.is_facing_right)
			wall->color = BLUE;
		if (ray.hit_horz && ray.h_distance < ray.v_distance)
			wall->color = GREEN;
		if (ray.hit_horz && ray.h_distance < ray.v_distance && ray.is_facing_up)
			wall->color = RED;
		render_wall(cub, i, wall->height, wall->color);
	}
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
 