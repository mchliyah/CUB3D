/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 04:12:10 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/30 10:38:26 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int is_color(char *colors, t_map *map)
{
	char **str;
	int i=0;
	int t=0;
	int col;
	int u =0;

	while (space(*colors))
	 	colors++;
	while (colors[u])
	{
		if (colors[u] == ',')
			i++;
		u++;
	}
	// printf("test <%s>\n",colors);
	if (i != 2)
	{
		printf("error\n check your ,");
		exit(0);
	}	
	map->col = ft_split(colors, ',');
	while (map->col[t])
	{
		i = 0;
		while(map->col[t][i])
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
// void color_int(t_map *map, int col, int flag)
// {
// 	if (flag == PATH_F && map->floor == -1)
// 	{

// 			map->floor += col;
// 			printf("\n---%d---\n",map->floor);
// 	}
// 	if (flag == PATH_C && map->ceiling == -1)
// 	{
// 			map->ceiling = (col[0]) + ( col[1] ) + col[2];

// 	}
// 	else
// 	{
// 			printf("\n---%d---\n",col[1]);
// 		printf("color error\n");
// 		exit(1);
// 	}
// }

void color_checking(t_map *map, char *color_l, int flag)
{
	int	col[3];
	int lenght;
	int	i;

	i = 0;
	lenght =  is_color(color_l, map);
	while(i < lenght)
	{
		col[i] = atoi(map->col[i]);
		
		if (col[i] < 0 || col[i] > 255)
		{
			printf("error\n color out of range\n");
			exit(1);
		}
		else
		{
			printf("\n--%d---\n",col[i]);
			//color_int(map, col[i], flag);
		}
		i++;
	}
}


// void check_texter(char *av)
// {
// 	int fd;

// 	if (av == NULL)
// 	{
// 		printf("error\nempty file\n");
// 		exit(0);
// 	}
// 	fd = open(av, 0644);
// 	if(fd < 0)
// 	{
// 		printf("error\n file invalid\n");
// 		exit(0);
// 	}
// }


int reading(t_map *map, char **av)
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
		// printf("index info : %d\n", index_info);
		count = 0;
		j = 0;
		while(space(av[i][j]))
		 	j++;
		flag = check_top2(av[i], j);
		if(flag == -1 && av[i][j] != '\n' )
		{
			printf("error\n");
			exit(0);
		}
		if(flag == PATH_F || flag == PATH_C)
		{
			map->char_count++;
			av[i][ft_strlen(av[i])- 1] = 0;
			colors = ft_substr(av[i], j + 1, ft_strlen(av[i]));
			color_checking(map, colors, flag);
		}
		if(flag == PATH_NO || flag == PATH_EA 
			|| flag == PATH_SO || flag == PATH_WE)
		{
			map->char_count++;
			av[i][ft_strlen(av[i])- 1] = 0;
			var = ft_substr(av[i], j + 2, ft_strlen(av[i]));
			// check_xpm(av, var);
			texters(map, var, j, flag, count);
		}
		i++;
	}
	if (map->char_count != 6)
	{
		printf("erorr\n");
		exit(1);
	}
	return(0);
}
