/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:27:39 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/30 15:04:07 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "includes/cub.h"

int	main(int ac, char **av)
{
	t_cub	cub;
	// t_map	map;

	if (ac != 2 || !ft_check_file(av, av[1]))
	{	
		printf("wrong arg!");
		exit(0);
	}
	get_data(av, &cub.map);
	init_data(&cub.map);
	if_map_valid(&cub.map);
	if (!init_player(&cub) || !init_mlx(&cub))
		exit(EXIT_FAILURE);
	cub.map.valid_i = 8;
	render(&cub);
	keyhook_loop(&cub);
	return (0);
}
