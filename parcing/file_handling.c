/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:36:25 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/23 08:42:42 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ft_check_file(char **argv, char *filename)
{
	int	lent;
	int	p;
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (!filename || fd < 0)
		return (0);
	lent = ft_strlen(filename);
	p = lent - 1;
	while (p > 0)
	{
		if (filename[p] == '.' && p + 3 == lent - 1)
		{
			if (filename[p + 1] == 'c' && filename[p + 2] == 'u'
				&& filename[p + 3] == 'b')
				return (1);
			else
				return (0);
		}
		p--;
	}
	return (0);
}

// int	check_borders(char **map, int i)
// {
// 	int j=0;
// 	printf("map-> %s\n",map[i]);
// 	if (map[i][0] != '1' && map[i][0] != '\0' && map[i][0] != ' ')
// 	{
// 		printf("map invalid 1\n");
// 		exit(0);
// 	}
// 	while (map[i] && i == 0)
// 	{
// 		if (map[i][j] == '\0' || map[i][j] == '\t'
// 			|| map[i][j] == '\n')
// 			{
// 				printf("map invalid 2\n");
// 				exit(0);
// 			}
// 			i++;
// 	}
// 	return (0);
// }