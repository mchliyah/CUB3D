/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:54:14 by hsaidi            #+#    #+#             */
/*   Updated: 2023/01/01 18:19:38 by hsaidi           ###   ########.fr       */
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
