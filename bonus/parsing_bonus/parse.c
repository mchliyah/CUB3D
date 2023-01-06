/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:02:16 by hsaidi            #+#    #+#             */
/*   Updated: 2023/01/06 13:15:02 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

int	is_param_first(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	while (str[i])
	{
		if (!is_not_texter(str, i))
			return (0);
		while (space(str[i]))
			i++;
		if ((str[i] == '1' || str[i] == '0' || player(str[i])))
			return (2);
		else
			return (0);
		i++;
	}
	return (0);
}

int	player_protection(t_map *map, int i, int p)
{
	if (!map->parsing[i] || !map->parsing[i + 1])
	{
		printf("error\nsomting wrong\n");
		exit(1);
	}
	map->player_count += 1;
	if (map->player_count != 1 || ((map_c(map->parsing[i][p + 1], 1) != 1)
		|| (map_c(map->parsing[i][p - 1], 1) != 1)
		|| (map_c(map->parsing[i + 1][p], 1) != 1)
		|| (map_c(map->parsing[i - 1][p], 1) != 1))
		|| p > ft_strlen2(map->parsing[i - 1])
		|| p > ft_strlen2(map->parsing[i + 1]))
	{
		printf("error\nMap invalid!\n");
		exit(1);
	}
	return (0);
}

int	zero_protaction(t_map *map, int i, int p)
{
	if (!map->parsing[i] || !map->parsing[i + 1])
	{
		printf("error\nsomting wrong\n");
		exit(1);
	}
	if ((map_c(map->parsing[i][p + 1], 2) != 1)
		|| (map_c(map->parsing[i][p - 1], 2) != 1)
		|| (map_c(map->parsing[i + 1][p], 2) != 1)
		|| (map_c(map->parsing[i - 1][p], 2) != 1)
		|| p > ft_strlen2(map->parsing[i - 1])
		|| p > ft_strlen2(map->parsing[i + 1]))
	{
		printf("error\nMap invalid!\n");
		exit(1);
	}
	return (0);
}

int	ft_check_borders(t_map *map)
{
	int	i;
	int	p;

	if (!map->valid_i || !map->parsing[map->valid_i])
	{
		printf("==wrong map!4\n");
		exit(0);
	}
	i = map->valid_i;
	while (map->parsing[i])
	{
		p = 0;
		while (map->parsing[i][p])
		{
			ft_wrong_characters(map->parsing[i], p);
			if (map->parsing[i][p] == '0')
				zero_protaction(map, i, p);
			if (player(map->parsing[i][p]))
				player_protection(map, i, p);
			p++;
		}
		i++;
	}
	return (i);
}

void	if_map_valid(t_map *map)
{
	int	last_wal;

	if (reading(map))
	{
		printf("wrong map!\n");
		exit(0);
	}
	if (first_wall(map))
	{
		printf("wrong map!\n");
		exit(0);
	}
	last_wal = ft_check_borders(map);
	if (last_wall(map, last_wal))
	{
		printf("wrong map!\n");
		exit(0);
	}
	if ((map->player_count != 1 || map->char_count != 6))
	{
		printf("==wrong map!5\n");
		exit(0);
	}
}
