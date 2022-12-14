/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:27:39 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/14 19:51:59 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "cub.h"

void my_mlx_pixel_put(t_window *data, int x, int y, int color)
{
	char *dst;

	dst = data->img_adrs + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void render_Square(t_cub cub, t_ax *pos, char c, int color)
{
	int i = 0;
	int j = 0;
	while (i < TILESIZE)
	{
		j = 0;
		while (j < TILESIZE)
		{
			if (c == wall)
				my_mlx_pixel_put(&cub.window, (*pos).x * TILESIZE + j, (*pos).y * TILESIZE + i, color);
			else if (c == playr)
				my_mlx_pixel_put(&cub.window, (*pos).x * TILESIZE + j, (*pos).y * TILESIZE + i, color);
			else
				my_mlx_pixel_put(&cub.window, (*pos).x * TILESIZE + j, (*pos).y * TILESIZE + i, color);
			j++;
		}
		i++;
	}
}

void render(t_cub cub)
{
	t_ax pos;
	
	pos.x = 0;
	pos.y = 0;
	while (pos.y < Y)
	{
		pos.x = 0;
		while (pos.x < X)
		{
			if (map[pos.y][pos.x] == wall)
				render_Square(cub, &pos, wall, red);
			else if (map[pos.y][pos.x] == 'N')
				render_Square(cub, &pos, playr, blue);
			else
				render_Square(cub, &pos, empty, green);
			pos.x++;
		}
		pos.y++;
	}
}

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
	cub.window.win = mlx_new_window(cub.window.mlx, X, Y, "cub3D");
	cub.window.img = mlx_new_image(cub.window.mlx, X, Y);
	cub.window.img_adrs = mlx_get_data_addr(cub.window.img, &cub.window.bits_per_pixel, &cub.window.line_length, &cub.window.endian);
	mlx_put_image_to_window(cub.window.mlx, cub.window.win, cub.window.img, 0, 0);
	render(cub);
	mlx_hook(cub.window.win, 2, 0, key_press, &cub);
	mlx_hook(cub.window.win, 17, 0, t_close, &cub);
	mlx_loop(cub.window.mlx);
	return (0);
}
