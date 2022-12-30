/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:02:16 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/30 14:49:51 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

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

int is_param_first(char *str)
{
	int i;

	i = 0;
	while((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	while(str[i])
	{

		if (!is_not_texter(str, i))
			return(0);
		while (space(str[i]))
			i++;
		if ((str[i] == '1' || str[i] == '0' || player(str[i])))
			return (1);
		else
			return (0);
		i++;
	}
	return (0);
}

int	file_one(t_map *map, int flag)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	(void)flag;
	while(map->parsing[i])
	{
		if (!is_param_first(map->parsing[i]))
		{
			size++;
			// printf("wahya hamid : *%s*\n", map->parsing[i]);
		}
		i++;
	}
	// printf("SIZE : %d\n",size);
	return(size - 1);
}

int	check_is_map(t_map *map, char **av)
{
	int i;
	int	p;
	int invalid;

	invalid = 0; 
	i = 0;
	(void)map;
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

	i = map->valid_i;
	if (!map->parsing[i])
		return (1);
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
					printf("error\nMap invalid!1\n");
					exit(1);
				}
			}
			if (player(map->parsing[i][p]))
			{
				map->player_count += 1;
				// printf("player count : %d\n", map->player_count);
				printf("i : %d\n, p : %d\n", i, p);
				if (map->player_count != 1 || ((map_c(map->parsing[i][p + 1], 1)!= 1) || (map_c(map->parsing[i][p - 1], 1) != 1)
					|| (map_c(map->parsing[i + 1][p], 1)!= 1) || (map_c(map->parsing[i - 1][p], 1)!= 1)))
				{
					printf("error\nMap invalid!2\n");
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

	map->valid_i = 0;
	map->valid_i = check_is_map(map, map->parsing);
	if(reading(map, map->parsing) || first_wall(map) || ft_check_borders(map) || last_wall(map))
	{
		printf("wrong map!\n");
		exit(0);
	}
}

// int	main(int ac, char **av)
// {
	
//     return(0);
// }