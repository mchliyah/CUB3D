/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:02:16 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/15 12:20:53 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
void	ft_count_is_valid(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	// map->coin_counter = 0;
	// map->player_counter = 0;
	// map->door_counter = 0;
	// while (map->map_parser[j])
	// {
	// 	i = 0;
	// 	while (map->map_parser[j][i])
	// 	{
	// 		if (map->map_parser[j][i] == 'C')
	// 			map->coin_counter += 1;
	// 		if (map->map_parser[j][i] == 'P')
	// 			map->player_counter += 1;
	// 		if (map->map_parser[j][i] == 'E')
	// 			map->door_counter += 1;
	// 		i++;
	// 	}
	// 	j++;
	// }
}

int	ft_wrong_characters(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '0' || str[i][j] == '1' || str[i][j] == 'E'
				|| str[i][j] == 'S' || str[i][j] == 'N' || str[i][j] == 'W'
				|| str[i][j] == '\n')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_count_width(char **argv, t_map *map)
{
	int		fd;
	char	*str;

	printf("in c_width\n");
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

	printf("in c_width\n");
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
	printf("in assign\n");
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

int main(int ac, char **av)
{
	t_map	map;

	int i =0;
	if (ac != 2)
	{	
		printf("too many arg!");
		exit(0);
	}
	ft_count_width(av, &map);
	ft_count_height(av, &map);
	ft_asssign_map(av, &map);
	while (i <= map.map_height && map.parsing[i] != NULL)
	{
		printf("map -> %s",map.parsing[i]);
		i++;
	}
	printf("\n");
	if (!ft_wrong_characters(map.parsing))
	{
		printf("check your characters!\n");
		return (0);
	}
    return(0);
}