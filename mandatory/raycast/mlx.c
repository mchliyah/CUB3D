/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:58:16 by mchliyah          #+#    #+#             */
/*   Updated: 2023/01/06 12:58:19 by mchliyah         ###   ########.fr       */
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
