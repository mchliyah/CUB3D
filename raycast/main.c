/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:27:39 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/15 00:49:49 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "cub.h"

int	buttons(int key, t_cub *cub)
{
	if (key == 0)
		cub->player.x -= 5;
	if (key == 2)
		cub->player.x += 5;
	if (key == 13)
		cub->player.y -= 5;
	if (key == 1)
		cub->player.y += 5;
	render(cub);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	(void)ac;
	(void)av;
	// if (!init(cub))
	// 	exit_error("init error");
	cub.window.mlx = mlx_init();
	cub.window.win = mlx_new_window(cub.window.mlx, X, Y, "cub3D");
	cub.window.img = mlx_new_image(cub.window.mlx, X, Y);
	cub.window.img_adrs = mlx_get_data_addr(cub.window.img, &cub.window.bits_per_pixel, &cub.window.line_length, &cub.window.endian);
	render(&cub);
	mlx_put_image_to_window(cub.window.mlx, cub.window.win, cub.window.img, 0, 0);
	mlx_key_hook(cub.window.win, buttons, &cub);
	mlx_hook(cub.window.win, 2, 0, key_press, &cub);
	mlx_hook(cub.window.win, 17, 0, t_close, &cub);
	mlx_loop(cub.window.mlx);
	return (0);
}
