/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:16:02 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/30 13:53:56 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int	first_wall(t_map *map)
{
	int	i;

	i = 0;
	// h = check_is_map(map, map->parsing);
	if (!map->valid_i || !map->parsing[map->valid_i ])
		return (1);
	while(map->valid_i  && map->parsing[map->valid_i ][i])
	{
		if (map->parsing[map->valid_i ][i] != '1' && !space(map->parsing[map->valid_i ][i])
			&& map->parsing[map->valid_i ][i] != '\n')
		{
			// printf("size %s\n", map->parsing[i]);
			printf("error\ncheck first wall\n");
			exit(0);
		}
		i++;
	}
	return(0);
}

int last_wall(t_map *map)
{
	// map->valid_i nt i;
	int p;

	// i = check_is_map(map,map->parsing);
	if (!map->valid_i  || !map->parsing[map->valid_i])
		return (1);
	while (map->parsing[map->valid_i])
		map->valid_i++;
	p = 0;
	
	while(map->parsing[map->valid_i  - 1][p])
	{
		if (map->parsing[map->valid_i - 1][p] != '1' && !space(map->parsing[map->valid_i - 1][p])
			&& map->parsing[map->valid_i - 1][p] != '\n')
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
