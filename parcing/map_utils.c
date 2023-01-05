/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:16:02 by hsaidi            #+#    #+#             */
/*   Updated: 2023/01/04 14:39:00 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int	first_wall(t_map *map)
{
	int	i;

	i = 0;
	if (!map->valid_i)
	{
		printf("valid i in first wall %d\n", map->valid_i);
		return (1);
	}
	if(!map->parsing[map->valid_i])
	{
		printf("valid i in first wall after %d\n", map->valid_i);
		return (1);
	}
	printf("first wall valid %d\n", map->valid_i);
	while (map->valid_i && map->parsing[map->valid_i][i])
	{
		if (map->parsing[map->valid_i][i] != '1'
			&& !space(map->parsing[map->valid_i][i])
			&& map->parsing[map->valid_i][i] != '\n')
		{
			printf("error\ncheck first wall\n");
			exit(0);
		}
		i++;
	}
	return (0);
}

int	last_wall(t_map *map, int last_wal)
{
	int	p;
	int	i;

	if (!map->valid_i || !map->parsing[map->valid_i])
		return (1);
	printf("last wall valid %d\n", last_wal);
	i = last_wal;
	while (map->parsing[i])
		i++;
	p = 0;
	while (map->parsing[i - 1][p])
	{
		if (map->parsing[i - 1][p] != '1'
			&& !space(map->parsing[i - 1][p])
			&& map->parsing[i - 1][p] != '\n')
		{
			printf("error\ncheck last wall\n");
			exit(0);
		}
		p++;
	}
	return (0);
}

int	ft_wrong_characters(char *str, int i)
{
	if (str[i] != '0' && str[i] != '1' && str[i] != 'E'
		&& str[i] != 'S' && str[i] != 'N' && str[i] != 'W'
		&& str[i] != '\n' && !space(str[i]))
	{
		printf("error\ninvalid character\n");
		exit(1);
	}
	return (0);
}
