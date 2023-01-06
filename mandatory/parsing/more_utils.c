/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:43:08 by hsaidi            #+#    #+#             */
/*   Updated: 2023/01/06 12:59:58 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	init_data(t_map *map)
{
	map->no = NULL;
	map->ea = NULL;
	map->so = NULL;
	map->we = NULL;
	map->parsing = NULL;
	map->valid_i = 0;
	map->ceiling = -1;
	map->col = NULL;
	map->floor = -1;
	map->player_count = 0;
	map->char_count = 0;
	map->player_x = -1;
	map->player_y = -1;
}

int	player(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	return (0);
}

int	map_c(char c, int flag)
{
	if (flag == 1)
	{
		if (c == '1' || c == '0')
			return (1);
	}
	if (flag == 2)
	{
		if (c == '1' || c == '0' || player(c))
			return (1);
	}
	return (0);
}

int	space(char pos)
{
	if (pos == 32 || pos == '\t')
		return (1);
	return (0);
}
