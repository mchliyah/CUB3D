/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:27:39 by mchliyah          #+#    #+#             */
/*   Updated: 2023/01/05 15:29:10 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/cub.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2 || !ft_check_file(av, av[1]))
	{	
		printf("wrong arg!");
		exit(0);
	}
	init_data(&cub.map);
	get_data(av, &cub.map);
	if_map_valid(&cub.map);
	if (!init_player(&cub) || !init_mlx(&cub))
		exit(EXIT_FAILURE);
	render(&cub);
	keyhook_loop(&cub);
	return (0);
}
