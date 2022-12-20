/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:36:13 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/19 00:49:24 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_count_width(char **argv, t_map *map)
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
	{
		printf("you need a map");
		exit (0);
	}
	map->map_width = ft_strlen(str) - 1;
	free (str);
}

void	ft_count_height(char **argv, t_map *map)
{
	char	*str;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	map->map_height = 0;
	while (str)
	{
		map->map_height += 1;
		free (str);
		str = get_next_line(fd);
	}
}

void	ft_asssign_map(char **argv, t_map *map)
{
	int	i;
	int	fd;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	map->parsing = malloc(sizeof(char *) * map->map_height + 1);
	while (i <= map->map_height)
	{
		map->parsing[i] = get_next_line(fd);
		i++;
	}
	map->parsing[i] = 0;
}
	// if (!ft_wrong_characters(map.parsing))
	// {
	// 	printf("\n\n check your characters!\n");
	// 	return (1);
	// }
	// if (ft_wall_check(&map) == 1)
	// {
	// 	printf("\n\n walls!\n");
	// 	return (1);
	// }	
	//ft_map_size(&map);



			// if (ft_wall_check(&map) == 1)
		// {
		// 	printf("\n\n walls!\n");
		// 	return (1);
		// }