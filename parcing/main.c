/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:02:16 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/18 15:09:13 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_is_map(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_strchr("01SMNEW", av[i]))
			return (0);	
		i++;
	}
	return (1);
}

int	ft_check_borders(char *line)
{
	t_map *map;
	printf("in check borders\n");
	while (*line)
	{
		if (*line != '1' && !space(*line))
			return (0);
		line++;
	}
	return (1);
}


int	main(int ac, char **av)
{
	t_map	map;

	int i = 0;
	if (ac != 2 || !ft_check_file(av,av[1]))
	{	
		printf("wrong arg!");
		exit(0);
	}
	ft_count_width(av, &map);
	ft_count_height(av, &map);
	ft_asssign_map(av, &map);
	while(map.parsing[i])
	{	
		if(check_is_map(map.parsing[i]) == 0)
			printf("%s" , map.parsing[i]);
		i++;
		// if (ft_wall_check(&map) == 1)
		// {
		// 	printf("\n\n walls!\n");
		// 	return (1);
		// }
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
    return(0);
}