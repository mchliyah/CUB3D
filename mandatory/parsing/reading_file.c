/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:36:13 by hsaidi            #+#    #+#             */
/*   Updated: 2023/01/05 14:45:58 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

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
	map->width = ft_strlen(str) - 1;
	free (str);
}

void	ft_count_hheight(char **argv, t_map *map)
{
	char	*str;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	map->height = 0;
	while (str)
	{
		map->height += 1;
		free (str);
		str = get_next_line(fd);
	}
}

void	ft_asssign_map(char **argv, t_map *map)
{
	int	i;
	int	fd;

	fd = open(argv[1], O_RDONLY);
	map->parsing = malloc(sizeof(char *) * (map->height + 1));
	i = -1;
	while (++i < map->height)
		map->parsing[i] = get_next_line(fd);
	map->parsing[i] = NULL;
}

void	get_data(char **av, t_map *map)
{
	ft_count_width(av, map);
	ft_count_hheight(av, map);
	ft_asssign_map(av, map);
	return ;
}
