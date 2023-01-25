/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:01:18 by mchliyah          #+#    #+#             */
/*   Updated: 2023/01/06 13:28:48 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../includes/cub.h"

void	my_mlx_pixel_put(t_window *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x >= 0 && x < X && y >= 0 && y < Y)
	{
		dst = data->img_adrs + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	get_pixel_color(t_textur *textur, int x, int y)
{
	char	*dst;

	dst = textur->img_adrs + (y * textur->line_length + x
			* (textur->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	get_square_color(t_cub *cub, int i, int j)
{
	if (cub->map.parsing[j][i] == WALL && j >= cub->map.valid_i)
		return (GRAY);
	else if (cub->map.parsing[j][i] == EMPTY
		|| cub->map.parsing[j][i] == cub->player.symbol)
		return (WHITE);
	else
		return (BLACK);
}
