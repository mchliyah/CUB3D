/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:02:16 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/14 15:20:31 by hsaidi           ###   ########.fr       */
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

void	ft_count_height(char **argv, t_map*map)
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

int main(void)
{
    printf("is here \n");
    return(0);
}