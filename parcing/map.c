/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:36:25 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/14 15:01:49 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// bool	get_map(t_map *map, char **av)
// {
// 	char	*line;
// 	int		m_fd;
// 	int		count;

// 	map = malloc(sizeof(t_map));
// 	if (!map)
// 		exit_error("malloc fall !!");
// 	m_fd = open(av[1], O_RDONLY);
// 	line = get_next_line(m_fd);
// 	count = 0;
// 	map->textr = malloc(sizeof(char *) * 5);
// 	map->textr = malloc(sizeof(char *) * 3);
// 	while (line)
// 	{
// 		while (line && count < 4)
// 		{
// 			map->textr[count++] = line;
// 			line = get_next_line(m_fd);
// 		}
// 		free(line);
// 		line = get_next_line(m_fd);
// 		if (line && count > 4 && count < 7)
// 		{
// 			while (line && count < 7)
// 			{
// 				map->colrs[count - 5] = line;
// 				line = get_next_line(m_fd);
// 			}
// 			free(line);
// 			line = get_next_line(m_fd);
// 		}
// 	}
// 	return (true);
// }
