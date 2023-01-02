/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:21:26 by mchliyah          #+#    #+#             */
/*   Updated: 2023/01/02 23:18:00 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/cub.h"


void	render_wall(t_cub *cub, t_ray *ray, int i, double wall_hheight, t_textur *textur)
{
	int		j;
	int		x;
	int		y;
	int		color;
	int		wall_top_pixel;
	int		wall_bottom_pixel;

	(void)ray;
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
	// if (ray->hit_horz)
		x = i % TILESIZE; 
	// else
	// 	x = j % TILESIZE;
	while (j < wall_bottom_pixel)
	{
		// printf("line length is %d\n", textur->line_length);
		y = (j - wall_top_pixel) * ((TILESIZE) / wall_hheight);
		// y = j % (int)wall_hheight;
		color = get_pixel_color(textur, x, y % textur->line_length);
		my_mlx_pixel_put(&cub->window, i, j, color);
		j++;
	}
}

void	thre_d_projection(t_cub *cub, t_wall *wall)
{
	t_ray	ray;
	t_textur	*textur;
	int		i;

	i = 0;
	while (i < X)
	{
		ray = cub->ray[i];
		wall->distance = (Y / 2) / tan(cub->player.fov / 2);
		// if (wall->distance < 15)
		// 	wall->distance = 15;
		wall->correct_dist = ray.distance
			* cos(ray.angle - cub->player.rot_angle);
		wall->hheight = ((TILESIZE / wall->correct_dist) * wall->distance);
		if (ray.hit_vert && !ray.is_facing_right)
			textur = cub->no;
		else if (ray.hit_vert && ray.is_facing_right)
			textur = cub->so;
		else if (ray.hit_horz && !ray.is_facing_up)
			textur = cub->ea;
		else if (ray.hit_horz && ray.is_facing_up)
			textur = cub->we;
		render_wall(cub, &ray, i, wall->hheight, textur);
		i++;
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
