/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:27:39 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/13 17:15:05 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "cub.h"

// bool	init(t_cub *cub)
// {
// 	if (!windowinit())
// 		exit_error("eroor windows ");
// }

int	key_press(int key, t_cub *cub)
{
	if (key == 53)
	{
		mlx_destroy_window(cub->window.mlx, cub->window.win);
		exit(0);
	}
	return (0);
}

int	t_close(t_cub *cub)
{
	mlx_destroy_window(cub->window.mlx, cub->window.win);
	exit(0);
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
	cub.window.win = mlx_new_window(cub.window.mlx, X, Y, "FDF");
	cub.window.img = mlx_new_image(cub.window.mlx, X, Y);
	cub.window.img_adrs = mlx_get_data_addr(cub.window.img, &cub.window.bpp, &cub.window.len, &cub.window.endian);
	mlx_put_image_to_window(cub.window.mlx, cub.window.win, cub.window.img, 0, 0);
	mlx_hook(cub.window.win, 2, 0, key_press, &cub);
	mlx_hook(cub.window.win, 17, 0, t_close, &cub);
	mlx_loop(cub.window.mlx);
	return (0);
}
