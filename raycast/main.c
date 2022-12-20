/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:27:39 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/19 17:20:12 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "cub.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	(void)ac;
	(void)av;
	if (!init_player(&cub) || !init_mlx(&cub)/* || !init_map(&cub) || !init_textures(&cub)*/)
		exit(EXIT_FAILURE);
	render(&cub);
	keyhook_loop(&cub);
	return (0);
}
