/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 04:12:10 by hsaidi            #+#    #+#             */
/*   Updated: 2023/01/01 18:19:58 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int	reading(t_map *map, char **av)
{
	int		i;
	int		j;
	int		flag;
	int		count;
	char	*var;
	char	*colors;
	int		index_info;

	i = 0;
	index_info = file_one(map, 1);
	while ((av[i] && i < index_info))
	{
		count = 0;
		j = 0;
		while (space(av[i][j]))
			j++;
		flag = check_top2(av[i], j);
		if (flag == PATH_F || flag == PATH_C)
		{
			map->char_count++;
			av[i][ft_strlen(av[i]) - 1] = 0;
			colors = ft_substr(av[i], j + 1, ft_strlen(av[i]));
			color_checking(map, colors, flag);
		}
		if (flag == PATH_NO || flag == PATH_EA
			|| flag == PATH_SO || flag == PATH_WE)
		{
			map->char_count++;
			av[i][ft_strlen(av[i]) - 1] = 0;
			var = ft_substr(av[i], j + 2, ft_strlen(av[i]));
			texters(map, var, j, flag);
		}
		i++;
	}
	if (flag == -1 && av[i][j] != '\n')
	{
		printf("erorr\n");
		exit(1);
	}
	return (0);
}
