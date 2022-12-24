/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:02:16 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/23 08:44:33 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"


int	check_is_map(t_map *map, char **av)
{
	int i;
	int	p;
	int invalid;

	invalid = 0; 
	i = 0;
	while(av[i])
	{
		p = 0;
		while(av[i][p])
		{
			if(!ft_strchr("01SMNEW", av[i][p]) && !space(av[i][p]))
				invalid = 1;
			else
			{
				invalid = 0;
				break;
			}
			p++;
		}
		if (invalid != 1)
			break;
		invalid = 0;
		i++;
	}
	return (i);
}
int	first_wall(t_map *map)
{
	int h;
	int i;
 
	h = check_is_map(map, map->parsing);
	i = 0;
	while(map->parsing[h][i])
	{
		if (map->parsing[h][i] != '1' && map->parsing[h][i] != 32
			&& map->parsing[h][i] != '\n')
		{
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

	i = check_is_map(map, map->parsing);
	while(map->parsing[i])
		i++;
	p = 0;
	while(map->parsing[i - 1][p])
	{
		if (map->parsing[i - 1][p] != '1' && map->parsing[i - 1][p] != 32
			&& map->parsing[i - 1][p] != '\n')
		{
			printf("error\ncheck first wall\n");
			exit(0);
		}
		p++;
	}
	return (0);
}

int	ft_check_borders(t_map *map)
{
	int	i;
	int	p;
 
	i = check_is_map(map, map->parsing);
	while(map->parsing[i])
	{
		p = 0;
		while(map->parsing[i][p])
		{
			if (map->parsing[i][p] == '0')
			{
				if((map_c(map->parsing[i][p + 1], 2)!= 1) || (map_c(map->parsing[i][p - 1], 2) !=1)
					|| (map_c(map->parsing[i + 1][p], 2)!= 1) || (map_c(map->parsing[i - 1][p], 2)!= 1))
				{
					printf("error\nSAD PRBLM\n");
					exit(1);
				}
			}
			if (player(map->parsing[i][p]))
			{
				if((map_c(map->parsing[i][p + 1], 1)!= 1) || (map_c(map->parsing[i][p - 1], 1) !=1)
					|| (map_c(map->parsing[i + 1][p], 1)!= 1) || (map_c(map->parsing[i - 1][p], 1)!= 1))
				{
					printf("error\nSAD PRBLM\n");
					exit(1);
				} 
			}
			p++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	int i = 0;
	int p =0;
	if (ac != 2 || !ft_check_file(av,av[1]))
	{	
		printf("wrong arg!");
		exit(0);
	}
	ft_count_width(av, &map);
	ft_count_height(av, &map);
	ft_asssign_map(av, &map);
	if(first_wall(&map) || ft_check_borders(&map)||last_wall(&map))
	{
		printf("wrong map!\n");
		exit(0);
	}
	else
		printf("\n*NICE*\n");
    return(0);
}