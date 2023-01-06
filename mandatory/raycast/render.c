/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:21:26 by mchliyah          #+#    #+#             */
/*   Updated: 2023/01/05 16:59:41 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../includes/cub.h"

void	render_floor_ceiling(t_cub *cub, t_wall *wall, int i)
{
	int	j;

	j = -1;
	while (++j < wall->top_pixel)
		my_mlx_pixel_put(&cub->window, i, j, cub->map.ceiling);
	j = wall->bottom_pixel - 1;
	while (++j <= Y)
		my_mlx_pixel_put(&cub->window, i, j, cub->map.floor);
}

void	render_wall(t_cub *cub, int i, t_wall *wall, t_textur *textur)
{
	int		j;
	int		x;
	int		y;
	int		save_top_pixel;

	save_top_pixel = wall->top_pixel;
	if (wall->top_pixel < 0)
		wall->top_pixel = 0;
	if (wall->bottom_pixel > Y)
		wall->bottom_pixel = Y;
	j = wall->top_pixel;
	if (cub->ray[i].hit_horz)
		x = ((int)cub->ray[i].horz_hit_x % TILESIZE * textur->width) / TILESIZE;
	else
		x = ((int)cub->ray[i].vert_hit_y % TILESIZE * textur->width) / TILESIZE;
	while (j <= wall->bottom_pixel)
	{
		y = ((j - save_top_pixel) / (wall->height)) * textur->height;
		my_mlx_pixel_put(&cub->window, i, j,
			get_pixel_color(textur, x % textur->width, y % textur->height));
		j++;
	}
	render_floor_ceiling(cub, wall, i);
}

void	thre_d_projection(t_cub *cub, t_wall *wall)
{
	t_ray		ray;
	t_textur	*textur;
	int			i;

	i = 0;
	while (i < X)
	{
		ray = cub->ray[i];
		wall->distance = (Y / 2) / tan(cub->player.fov / 2);
		wall->correct_dist = ray.distance
			* cos(ray.angle - cub->player.rot_angle);
		wall->height = ((TILESIZE / wall->correct_dist) * wall->distance);
		if (ray.hit_vert && !ray.is_facing_right)
			textur = &cub->we;
		else if (ray.hit_vert && ray.is_facing_right)
			textur = &cub->ea;
		else if (ray.hit_horz && !ray.is_facing_up)
			textur = &cub->so;
		else if (ray.hit_horz && ray.is_facing_up)
			textur = &cub->no;
		wall->top_pixel = Y / 2 - (wall->height / 2);
		wall->bottom_pixel = wall->top_pixel + wall->height;
		render_wall(cub, i, wall, textur);
		i++;
	}
}

int	render(t_cub *cub)
{
	t_wall	wall;

	player_update(cub);
	cast_rays(cub);
	thre_d_projection(cub, &wall);
	events(cub);
	mlx_put_image_to_window(cub->window.mlx,
		cub->window.win, cub->window.img, 0, 0);
	return (0);
}
