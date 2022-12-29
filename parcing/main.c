/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:02:16 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/29 18:20:34 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((!s1 || !s2) && !n)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_isdigit(int k)
{
	if (k >= '0' && k <= '9')
		return (1);
	return (0);
}

int skip_alpha(char *str)
{
	if (str)
	{
		while(*str == 32 || *str == '\t')
			str++;
		if(ft_isdigit(*str) == 1)
			return (1);
	}
	return(0);
}

int	file_one(t_map *map, int flag)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while(map->parsing[i])
	{
		if (flag == 1)
		{
			if (skip_alpha(map->parsing[i]) == 0 && (!map_c(*map->parsing[i + 1] , 1)))
				size++;
		}
		i++;
	}
	return(size);
}

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
			if ((skip_alpha(av[i]) == 0))
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

int	ft_check_borders(t_map *map)
{
	int	i;
	int	p;

	while (map->parsing[i])
	{
		p = 0;
		while (map->parsing[i][p])
		{
			ft_wrong_characters(map->parsing[i], p);
			if (map->parsing[i][p] == '0')
			{
				if ((map_c(map->parsing[i][p + 1], 2)!= 1) || (map_c(map->parsing[i][p - 1], 2) !=1)
					|| (map_c(map->parsing[i + 1][p], 2)!= 1) || (map_c(map->parsing[i - 1][p], 2)!= 1))
				{
					printf("error\nMap invalid!\n");
					exit(1);
				}
			}
			if (player(map->parsing[i][p]))
			{
				map->player_count += 1;
				if (map->player_count != 1 || ((map_c(map->parsing[i][p + 1], 1)!= 1) || (map_c(map->parsing[i][p - 1], 1) !=1)
					|| (map_c(map->parsing[i + 1][p], 1)!= 1) || (map_c(map->parsing[i - 1][p], 1)!= 1)))
				{
					printf("error\nMap invalid!\n");
					exit(1);
				}  
			}
			p++;
		}
		i++;
	}
	return (0);
}

int skip_space(char *sp, int i)
{
	while(space(sp[i]))
		i++;
	return(i);
}

void if_map_valid(t_map *map)
{
	int	valid_i;

	valid_i = 0;
	valid_i = check_is_map(map,map->parsing);
	if((first_wall(map) || ft_check_borders(map) || last_wall(map)))
	{
		printf("wrong map!\n");
		exit(0);
	}
	else
	{
		// here u can get the index of valid map(valid_i)
		while(map->parsing[valid_i])  
		{
			printf("parce:%s\n",map->parsing[valid_i]);
			valid_i++;
		}
		printf("*NICE*\n");
	}
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2 || !ft_check_file(av,av[1]))
	{	
		printf("wrong arg!");
		exit(0);
	}
	get_data(av, &map);
	init_data(&map);
	reading(&map, map.parsing);
	 /*i comonted the top of file just to 
	//make sure of something tomorow otherwase rah is working*/
	//if_map_valid(&map);
    return(0);
}