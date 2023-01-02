/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:39:11 by hsaidi            #+#    #+#             */
/*   Updated: 2023/01/01 18:18:23 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

// void color_int(t_map *map, int col, int flag)
// {
// 	if (flag == PATH_F && map->floor == -1)
// 	{

// 			map->floor += col;
// 			printf("\n---%d---\n",map->floor);
// 	}
// 	if (flag == PATH_C && map->ceiling == -1)
// 	{
// 			map->ceiling = (col[0] << 16) + (col[1] << 8) + col[2];

// 	}
// 	else
// 	{
// 			printf("\n---%d---\n",col[1]);
// 		printf("color error\n");
// 		exit(1);
// 	}
// }

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