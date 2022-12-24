/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 04:43:26 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/24 20:01:17 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_player_pos(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mapHeight)
	{
		j = 0;
		while (j < mapWidth)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W')
			{
				cub->player.symbol = map[i][j];
				cub->player.x = j * TILESIZE + (TILESIZE / 2);
				cub->player.y = i * TILESIZE + (TILESIZE / 2);
			}
			j++;
		}
		i++;
	}
}

bool	init_player(t_cub *cub)
{
	get_player_pos(cub);
	cub->player.move[0] = -1;
	cub->player.move[1] = -1;
	cub->player.move[2] = -1;
	cub->player.fov = M_PI / 3;
	cub->player.speed_mov = 3.2;
	cub->player.speed_rot = 3.2 * (M_PI / 180);
	cub->player.rot_angle = M_PI; // to check if it's correct
	return (true);
}
