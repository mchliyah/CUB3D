/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:16:02 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/30 10:08:35 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	first_wall(t_map *map)
{
	int h;
	int i;

	i = 0;
	h = check_is_map(map,map->parsing);
	if (!h || !map->parsing[h])
		return (1);
	while(h && map->parsing[h][i])
	{
		if (map->parsing[h][i] != '1' && !space(map->parsing[h][i])
			&& map->parsing[h][i] != '\n')
		{
			printf("size %s\n", map->parsing[i]);
			printf("error\ncheck first wall\n");
			exit(0);
		}
		i++;
	}
	return(0);
}

int last_wall(t_map *map)
{
	int i;
	int p;

	i = check_is_map(map,map->parsing);
	if (!i || !map->parsing[i])
		return (1);
	while(map->parsing[i])
		i++;
	p = 0;
	
	while(map->parsing[i - 1][p])
	{
		if (map->parsing[i - 1][p] != '1' && !space(map->parsing[i - 1][p])
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
			printf("str is : %c \n", str[i]);
			printf("error\ninvalid character\n");
			exit(1);
		}
	return (0);
}
