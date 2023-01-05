/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 04:43:26 by mchliyah          #+#    #+#             */
/*   Updated: 2023/01/05 20:26:39 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../includes/cub.h"

void	get_player_pos(t_cub *cub)
{
	int	i;
	int	j;

	i = 8;
	j = 0;
	while (i < cub->map.height)
	{
		j = 0;
		while (j < ft_strlen1(cub->map.parsing[i]))
		{
			if (cub->map.parsing[i][j] == 'N' || cub->map.parsing[i][j] == 'S'
				|| cub->map.parsing[i][j] == 'E'
				|| cub->map.parsing[i][j] == 'W')
			{
				cub->player.symbol = cub->map.parsing[i][j];
				cub->player.x = j * TILESIZE + (TILESIZE / 2);
				cub->player.y = i * TILESIZE + (TILESIZE / 2);
			}
			j++;
		}
		i++;
	}
}

void	player_update(t_cub *cub)
{
	if (cub->player.rot_angle > 0 && cub->player.rot_angle < M_PI)
		cub->player.facing_up = false;
	else
		cub->player.facing_up = true;
	if (cub->player.rot_angle < 0.5 * M_PI
		|| cub->player.rot_angle > 1.5 * M_PI)
		cub->player.facing_right = true;
	else
		cub->player.facing_right = false;
}
