/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:16:02 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/29 07:19:30 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int space(char pos)
{
    if(pos == 32 || pos == '\t')
        return(1);
    return(0);
}

int	first_wall(t_map *map)
{
	int h;
	int i;

	i = 0;
	h = check_is_map(map,map->parsing);
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

int player(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			return (1);
	return (0);
}

int	map_c(char c, int flag)
{
	if(flag == 1)
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
