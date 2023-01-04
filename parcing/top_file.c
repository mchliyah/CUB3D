/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 04:12:10 by hsaidi            #+#    #+#             */
/*   Updated: 2023/01/04 15:21:17 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int	reading(t_map *map, char **av)
{
	int		i;
	int		j;
	int		flag;
	char	*var;
	char	*colors;
	int		index_info;

	i = 0;
	(void)av;
	index_info = file_one(map, 1);
	map->valid_i = index_info + 1;
	map->char_count = 0;
	while ((map->parsing[i] && i < index_info))
	{
		j = 0;
		while (space(map->parsing[i][j]))
			j++;
		printf("map->parsing = %s\n", map->parsing[i]);
		flag = check_top2(map->parsing[i], j);
		if (flag == PATH_F || flag == PATH_C)
		{
			map->char_count++;
			map->parsing[i][ft_strlen(map->parsing[i]) - 1] = 0;
			colors = ft_substr(map->parsing[i], j + 1, ft_strlen(map->parsing[i]));
			color_checking(map, colors, flag);
		}
		if (flag == PATH_NO || flag == PATH_EA
			|| flag == PATH_SO || flag == PATH_WE)
		{
			map->char_count++;
			map->parsing[i][ft_strlen(map->parsing[i]) - 1] = 0;
			var = ft_substr(map->parsing[i], j + 2, ft_strlen(map->parsing[i]));
			texters(map, var, j, flag);
		}
		printf("i == %d\n", i);
		printf("flag == %d\n", flag);
		printf("map cahar count %d\n", map->char_count);
		i++;
	}
	if (flag == -1 && map->parsing[i][j] != '\n')
	{
		printf("erorr\n");
		exit(1);
	}
	return (0);
}
