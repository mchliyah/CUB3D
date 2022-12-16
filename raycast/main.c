/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:27:39 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/16 05:32:16 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "cub.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	(void)ac;
	(void)av;
	if (!init_player(&cub))
		exit(EXIT_FAILURE);
	// 	exit_error("init error");
	// if (!parse_map(cub))
	cub.window.mlx = mlx_init();
	cub.window.win = mlx_new_window(cub.window.mlx, X, Y, "cub3D");
	cub.window.img = mlx_new_image(cub.window.mlx, X, Y);
	cub.window.img_adrs = mlx_get_data_addr(cub.window.img, &cub.window.bits_per_pixel, &cub.window.line_length, &cub.window.endian);
	render(&cub);
	mlx_put_image_to_window(cub.window.mlx, cub.window.win, cub.window.img, 0, 0);
	mlx_hook(cub.window.win, 2, 1L << 0, buttons, &cub);
	mlx_hook(cub.window.win, 17, 0, t_close, &cub);
	mlx_loop(cub.window.mlx);
	return (0);
}
