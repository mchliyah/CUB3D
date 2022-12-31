/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 04:12:10 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/31 19:03:03 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int	is_color(char *colors, t_map *map)
{
	int		i;
	int		t;
	int		u;

	i = 0;
	t = 0;
	u = 0;
	while (space(*colors))
		colors++;
	while (colors[u])
	{
		if (colors[u] == ',')
			i++;
		u++;
	}
	if (i != 2)
	{
		printf("error\n check your ,");
		exit(0);
	}
	map->col = ft_split(colors, ',');
	while (map->col[t])
	{
		i = 0;
		while (map->col[t][i])
		{
			if (!ft_isdigit(map->col[t][i]))
			{
				printf("error\ninvalid color\n");
				exit(1);
			}
			i++;
		}
		t++;
	}
	return (t);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	color_checking(t_map *map, char *color_l, int flag)
{
	int	col[3];
	int	lenght;
	int	count;
	int	i;

	count = 0;
	i = 0;
	lenght = is_color(color_l, map);
	while (i < lenght)
	{
		col[i] = atoi(map->col[i]);
		if (col[i] < 0 || col[i] > 255)
		{
			printf("error\n color out of range\n");
			exit(1);
		}
		count++;
		i++;
	}
	if (count != 3)
	{
		printf("error\n colors more or less than 3\n");
		exit(1);
	}
	if (flag == PATH_F && map->floor == -1)
		map->floor = create_trgb(0, col[0], col[1], col[2]);
	else if (flag == PATH_C && map->ceiling == -1)
		map->ceiling = create_trgb(0, col[0], col[1], col[2]);
	else
	{
		printf("color error\n");
		exit(1);
	}		
}

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
