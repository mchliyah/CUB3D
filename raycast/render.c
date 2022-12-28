/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:21:26 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/28 01:50:49 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	render_square(t_cub *cub, t_ax pos, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < TILESIZE - 1)
	{
		j = -1;
		while (++j < TILESIZE - 1)
			my_mlx_pixel_put(&cub->window, pos.x * TILESIZE
				+ j, pos.y * TILESIZE + i, color);
		i++;
	}
}

// void	render_player(t_cub *cub)
// {
// 	double	i;
// 	double	j;

// 	j = cub->player.y - 2;
// 	while (j < cub->player.y + 2)
// 	{
// 		i = cub->player.x - 2;
// 		while (i < cub->player.x + 2)
// 		{
// 			my_mlx_pixel_put(&cub->window, i, j, blue);
// 			i++;
// 		}
// 		j++;
// 	}
// }

void	render_map(t_cub *cub)
{
	t_ax	pos;

	pos.x = 0;
	pos.y = 0;
	while (pos.y < mapHeight)
	{
		pos.x = 0;
		while (pos.x < mapWidth)
		{
			if (map[pos.y][pos.x] == wall)
				render_square(cub, pos, gray);
			else if (map[pos.y][pos.x] == empty
				|| map[pos.y][pos.x] == cub->player.symbol)
				render_square(cub, pos, white);
			pos.x++;
		}
		pos.y++;
	}
}

int	render(t_cub *cub)
{
	render_map(cub);
	// render_player(cub);
	cast_rays(cub);
	events(cub);
	mlx_put_image_to_window(cub->window.mlx,
		cub->window.win, cub->window.img, 0, 0);
	return (0);
}
