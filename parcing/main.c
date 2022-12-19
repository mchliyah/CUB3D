/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:02:16 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/19 03:08:45 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_is_map(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_strchr("01SMNEW", av[i]) || av[i] == 32)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_borders(t_map *map, int i)
{

	if ((map->parsing[i][0] != '1'&& map->parsing[i][0] != 32))
		return (1);
	if((map->parsing[i][ft_strlen(map->parsing[i]) - 2] != '1'))
		return (1);
	else
		return 0;
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
	while(map.parsing[i])
	{
		if(check_is_map(map.parsing[i]) == 0)
		{
			//printf("character %c\n" , map.parsing[i][0]);
			if(ft_check_borders(&map, i) == 1)
			{	
				printf("error\n map not valid\n");
				return(0);
			}
			else
				printf("->>%s" , map.parsing[i]);
			// else if(map.parsing[i][map.map_width - 1] != '1' 
			// 	|| map.parsing[i][map.map_width - 1] != 32)
		}
		i++;
	}
    return(0);
}