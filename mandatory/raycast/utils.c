/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:57:48 by mchliyah          #+#    #+#             */
/*   Updated: 2023/01/06 12:57:53 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../includes/cub.h"

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
