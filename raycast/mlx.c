/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 01:58:41 by mchliyah          #+#    #+#             */
/*   Updated: 2023/01/02 19:39:30 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/cub.h"

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

	if (x >= 0 && x < textur->line_length && y >= 0 && y < textur->line_length)
	{
		dst = textur->img_adrs + (y * textur->line_length + x
				* (textur->bits_per_pixel / 8));
		return (*(unsigned int *)dst);
	}
	return (RED);
}
