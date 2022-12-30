/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:36:13 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/30 13:53:46 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

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

void get_data(char **av, t_map *map)
{
	ft_count_width(av, map);
	ft_count_height(av, map);
	ft_asssign_map(av, map);
	return ;
}