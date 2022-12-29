/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 04:12:10 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/29 20:40:42 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		check_top2(char *var, int j)
{
	//printf("|->%s\n", var);
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
	printf("test <%s>\n",colors);
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
				printf("dig|%c|\n", map->col[t][i]);
				printf("error\ninvalid color\n");
				exit(1);
			}
			i++;
		}
		t++;
	}
	return (t);	
}
void color_checking(t_map *map, char *color_l)
{
	int	col[3];
	int lenght;
	int	i;

	i = 0;
	lenght =  is_color(color_l, map);
	while(i < lenght)
	{
		col[i] = atoi(map->col[i]);
		printf("the nb is |%d|\n", col[i]);
		i++;
	}
}

int texters(t_map *map ,char *av, int i, int flag, int count)
{
	int fd;

	while(space(*av))
		av++;
	if (flag == PATH_NO && !map->no)
	{
		printf("av |%s|\n", av);
		count++;
		map->no = av;
	}
	else if (flag == PATH_SO && !map->so)
	{
		count++;
		map->so = av;
		printf("av |%s|\n", map->so);
	}
	else if (flag == PATH_WE && !map->we)
	{
		count++;
		map->we = av;
		printf("av |%s|\n", map->we);

	}
	else if (flag == PATH_EA && !map->ea)
	{
		count++;
		map->ea = av;
		printf("av |%s|\n", map->ea);
	}
	else
	{
		printf("error\n Duplication\n");
		exit(1);
	}
	return(count);
}

// int check_texter(t_map *map)
// {

// 	if (av == NULL)
// 	{
// 		printf("error\nempty file\n");
// 		exit(0);
// 	}
	// fd = open(av, 0644);
	// if(fd < 0)
	// {
	// 	printf("error\n file invalid\n");
	// 	//exit(0);
	// }
	// else 
	// 	printf("nice nice\n");

// }
// need to check here fd open and use sub str

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
	while (av[i] && i < index_info)
	{
		// check the count here
		count = 0;
		j = 0;
		while(space(av[i][j]))
		 	j++;
		flag = check_top2(av[i], j);
		if(flag == -1 && av[i][j] != '\n')
		{
			printf("error\n");
			exit(0);
		}
		if(flag == PATH_F || flag == PATH_C)
		{
			av[i][ft_strlen(av[i])- 1] = 0;
			colors = ft_substr(av[i], j + 1, ft_strlen(av[i]));
			//printf("here |%c|\n", av[i][ft_strlen(av[i])- 1]);
			color_checking(map, colors);
		}
		if(flag == PATH_NO || flag == PATH_EA 
			|| flag == PATH_SO || flag == PATH_WE)
		{
			var = ft_substr(av[i], j + 2, ft_strlen(av[i]));
			//printf("else|%s|\n", var);
			texters(map, var, j, flag, count);
			check_xpm(av, var);
		}
		i++;
	}
	return(0);
}
