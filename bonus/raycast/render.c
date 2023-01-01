/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:21:26 by mchliyah          #+#    #+#             */
/*   Updated: 2023/01/01 17:07:58 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/cub.h"

void	render_mini_map(t_cub *cub)
{
	t_ax	pos;

	pos.x = 0;
	pos.y = cub->map.valid_i;
	while (pos.y < cub->map.height)
	{
		pos.x = 0;
		while (pos.x < ft_strlen1(cub->map.parsing[(int)pos.y]))
		{
			if (cub->map.parsing[(int)pos.y][(int)pos.x] == WALL)
				render_square(cub, pos, GRAY);
			else if (cub->map.parsing[(int)pos.y][(int)pos.x] == EMPTY
				|| cub->map.parsing[(int)pos.y][(int)pos.x]
				== cub->player.symbol)
				render_square(cub, pos, WHITE);
			pos.x++;
		}
		pos.y++;
	}
	render_player(cub);
}

void	render_wall(t_cub *cub, int i, double wall_hheight, int textur)
{
	int		j;
	int		wall_top_pixel;
	int		wall_bottom_pixel;

	j = -1;
	while (++j < Y / 2 - (wall_hheight / 2))
		my_mlx_pixel_put(&cub->window, i, j, cub->map.ceiling);
	j = Y / 2 + (wall_hheight / 2) - 1;
	while (++j < Y)
		my_mlx_pixel_put(&cub->window, i, j, cub->map.floor);
	wall_top_pixel = Y / 2 - (wall_hheight / 2);
	if (wall_top_pixel < 0)
		wall_top_pixel = 0;
	wall_bottom_pixel = Y / 2 + (wall_hheight / 2);
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
		wall->hheight = ((TILESIZE / wall->correct_dist) * wall->distance);
		if (ray.hit_vert && ray.v_distance < ray.h_distance)
			wall->textur = ORANGE;
		if (ray.hit_vert && ray.v_distance < ray.h_distance
			&& ray.is_facing_right)
			wall->textur = BLUE;
		if (ray.hit_horz && ray.h_distance < ray.v_distance)
			wall->textur = GREEN;
		if (ray.hit_horz && ray.h_distance < ray.v_distance && ray.is_facing_up)
			wall->textur = RED;
		render_wall(cub, i, wall->hheight, wall->textur);
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
	render_mini_map(cub);
	events(cub);
	mlx_put_image_to_window(cub->window.mlx,
		cub->window.win, cub->window.img, 0, 0);
	return (0);
}
