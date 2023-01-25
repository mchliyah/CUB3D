/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:23:44 by hsaidi            #+#    #+#             */
/*   Updated: 2023/01/06 13:23:48 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	assignming(t_map *map, int i, int j, int flag)
{
	char	*colors;
	char	*var;

	if (flag == PATH_F || flag == PATH_C)
	{
		map->char_count++;
		map->parsing[i][ft_strlen(map->parsing[i]) - 1] = 0;
		colors = ft_substr(map->parsing[i], j + 1, ft_strlen(map->parsing[i]));
		color_checking(map, colors, flag);
		free(colors);
	}
	if (flag == PATH_NO || flag == PATH_EA
		|| flag == PATH_SO || flag == PATH_WE)
	{
		map->char_count++;
		map->parsing[i][ft_strlen(map->parsing[i]) - 1] = 0;
		var = ft_substr(map->parsing[i], j + 2, ft_strlen(map->parsing[i]));
		texters(map, var, flag);
		if (!check_xpm(var))
		{
			printf("error\n xpm\n");
			exit(1);
		}
	}	
}

int	reading(t_map *map)
{
	int		i;
	int		j;
	int		flag;
	int		index_info;

	i = 0;
	index_info = file_one(map, 1);
	map->valid_i = index_info + 1;
	map->char_count = 0;
	while ((map->parsing[i] && i <= index_info))
	{
		j = 0;
		while (space(map->parsing[i][j]))
			j++;
		flag = check_top2(map->parsing[i], j);
		if (flag == -1 && map->parsing[i][j] != '\n')
		{
			printf("error\nsomething wrong!\n");
			exit(1);
		}
		assignming(map, i, j, flag);
		i++;
	}
	return (0);
}
