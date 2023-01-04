/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:39:11 by hsaidi            #+#    #+#             */
/*   Updated: 2023/01/01 18:46:57 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

// void color_int(t_map *map, int col, int flag)
// {
// 	if (flag == PATH_F && map->floor == -1)
// 	{

// 			map->floor += col;
// 			printf("\n---%d---\n",map->floor);
// 	}
// 	if (flag == PATH_C && map->ceiling == -1)
// 	{
// 			map->ceiling = (col[0] << 16) + (col[1] << 8) + col[2];

// 	}
// 	else
// 	{
// 			printf("\n---%d---\n",col[1]);
// 		printf("color error\n");
// 		exit(1);
// 	}
// }

// void check_texter(char *av)
// {
// 	int fd;

// 	if (av == NULL)
// 	{
// 		printf("error\nempty file\n");
// 		exit(0);
// 	}
// 	fd = open(av, 0644);
// 	if(fd < 0)
// 	{
// 		printf("error\n file invalid\n");
// 		exit(0);
// 	}
// }

// void	render_mini_map(t_cub *cub)
// {
// 	t_ax	pos;

// 	pos.x = 0;
// 	pos.y = cub->map.valid_i;
// 	while (pos.y < cub->map.map_height)
// 	{
// 		pos.x = 0;
// 		while (pos.x < ft_strlen1(cub->map.parsing[(int)pos.y]))
// 		{
// 			if (cub->map.parsing[(int)pos.y][(int)pos.x] == WALL)
// 				render_square(cub, pos, GRAY);
// 			else if (cub->map.parsing[(int)pos.y][(int)pos.x] == EMPTY
// 				|| cub->map.parsing[(int)pos.y][(int)pos.x]
// 				== cub->player.symbol)
// 				render_square(cub, pos, WHITE);
// 			pos.x++;
// 		}
// 		pos.y++;
// 	}
// 	render_player(cub);
// }

// void	render_wall(t_cub *cub, int i, double wall_height, int color)
// {
// 	int		j;
// 	int		wall_top_pixel;
// 	int		wall_bottom_pixel;

// 	j = -1;
// 	while (++j < Y / 2 - (wall_height / 2))
// 		my_mlx_pixel_put(&cub->window, i, j, cub->map.ceiling);
// 	j = Y / 2 + (wall_height / 2) - 1;
// 	while (++j < Y)
// 		my_mlx_pixel_put(&cub->window, i, j, cub->map.floor);
// 	wall_top_pixel = Y / 2 - (wall_height / 2);
// 	if (wall_top_pixel < 0)
// 		wall_top_pixel = 0;
// 	wall_bottom_pixel = Y / 2 + (wall_height / 2);
// 	if (wall_bottom_pixel > Y)
// 		wall_bottom_pixel = Y;
// 	j = wall_top_pixel;
// 	while (j < wall_bottom_pixel)
// 	{
// 		my_mlx_pixel_put(&cub->window, i, j, color);
// 		j++;
// 	}
// }

// void	thre_d_projection(t_cub *cub, t_wall *wall)
// {
// 	t_ray	ray;
// 	int		i;

// 	i = -1;
// 	while (++i < X)
// 	{
// 		ray = cub->ray[i];
// 		wall->distance = (Y / 2) / tan(cub->player.fov / 2);
// 		if (wall->distance < 15)
// 			wall->distance = 15;
// 		wall->correct_dist = ray.distance
// 			* cos(ray.angle - cub->player.rot_angle);
// 		wall->height = ((TILESIZE / wall->correct_dist) * wall->distance) * 2;
// 		if (ray.hit_vert && ray.v_distance < ray.h_distance)
// 			wall->color = ORANGE;
// 		if (ray.hit_vert && ray.v_distance < ray.h_distance
// 			&& ray.is_facing_right)
// 			wall->color = BLUE;
// 		if (ray.hit_horz && ray.h_distance < ray.v_distance)
// 			wall->color = GREEN;
// 		if (ray.hit_horz && ray.h_distance < ray.v_distance && ray.is_facing_up)
// 			wall->color = RED;
// 		render_wall(cub, i, wall->height, wall->color);
// 	}
// }

// int	render(t_cub *cub)
// {
// 	t_wall	wall;

// 	player_update(cub);
// 	cast_rays(cub);
// 	thre_d_projection(cub, &wall);
// 	render_mini_map(cub);
// 	events(cub);
// 	mlx_put_image_to_window(cub->window.mlx,
// 		cub->window.win, cub->window.img, 0, 0);
// 	return (0);
// }