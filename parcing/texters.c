/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:00:52 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/30 10:07:03 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int is_not_texter(char *str, int i)
{
	if ((str[i] == 'N' && str[i + 1] == 'O') 
		|| (str[i] == 'S' && str[i + 1] == 'O') 
		|| (str[i] == 'E' && str[i + 1] == 'A') 
		|| (str[i] == 'W' && str[i + 1] == 'E'))
			return (0);
	return(1);
}

int		check_top2(char *var, int j)
{
	if (var[j] == 'N' && var[j + 1] == 'O' && space(var[j + 2]))
		return(PATH_NO);
	if (var[j] == 'S' && var[j + 1] == 'O' && space(var[j + 2]))
		return(PATH_SO);
	if (var[j] == 'W' && var[j + 1] == 'E' && space(var[j + 2]))
		return(PATH_WE);
	if (var[j] == 'E' && var[j + 1] == 'A' && space(var[j + 2]))
		return(PATH_EA);
	if (var[j] == 'F' && space(var[j + 1]))
		return(PATH_F);
	if (var[j] == 'C' && space(var[j + 1]))
		return(PATH_C);
	else
		return (-1);
}

int texters(t_map *map ,char *av, int i, int flag, int count)
{
	while(space(*av))
		av++;
	if (flag == PATH_NO && !map->no)
	{
		count++;
		map->no = av;

	}
	else if (flag == PATH_SO && !map->so)
	{
		count++;
		map->so = av;
	}
	else if (flag == PATH_WE && !map->we)
	{
		count++;
		map->we = av;
	}
	else if (flag == PATH_EA && !map->ea)
	{
		count++;
		map->ea = av;
	}
	else
	{
		printf("error\n Duplication\n");
		exit(1);
	}
	return(count);
}