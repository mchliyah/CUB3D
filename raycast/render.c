/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:21:26 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/17 00:20:01 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub.h"

void my_mlx_pixel_put(t_window *data, int x, int y, unsigned int color)
{
	char *dst;
	if (x >=0 && x < X && y >= 0 && y < Y)
	{
		dst = data->img_adrs + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void render_Square(t_cub *cub, t_ax pos, unsigned int color)
{
	int i = 0;
	int j = 0;
	while (i < TILESIZE - 1)
	{
		j = -1;
		while (++j < TILESIZE - 1)
				my_mlx_pixel_put(&cub->window, pos.x * TILESIZE + j, pos.y * TILESIZE + i, color);
		i++;
	}
}

void draw_line(t_cub *cub)
{
	int xstart;
	int ystart;
	int xend;
	int yend;

	xstart = cub->player.x;
	ystart = cub->player.y;
	xend = cub->player.x + (cub->player.ray_len * cos(cub->player.rot_angle));
	yend = cub->player.y + (cub->player.ray_len * sin(cub->player.rot_angle));


    int dx, dy, sx, sy, err, e2;

    dx = abs(xend - xstart);
    dy = abs(yend - ystart);
    sx = xstart < xend ? 1 : -1;
    sy = ystart < yend ? 1 : -1;
    err = (dx > dy ? dx : -dy) / 2;

    while (1)
    {
        my_mlx_pixel_put(&cub->window, xstart, ystart, 0xFF0000);
        if (xstart == xend && ystart == yend)
            break;
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            xstart += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            ystart += sy;
        }
    }
}

void	render_player(t_cub *cub)
{
	double i;
	double j;

	j = cub->player.y - 2;

	while (j < cub->player.y + 2)
	{
		i = cub->player.x - 2;
		while (i < cub->player.x + 2)
		{
			my_mlx_pixel_put(&cub->window, i, j, blue);
			i++;
		}
		j++;
	}
	draw_line(cub);
	// render_ray(cub);
}

void render(t_cub *cub)
{
	t_ax pos;
	
	pos.x = 0;
	pos.y = 0;
	while (pos.y < 5)
	{
		pos.x = 0;
		while (pos.x < ft_strlen1(map[pos.y]))
		{
			if (map[pos.y][pos.x] == wall)
				render_Square(cub, pos, red);
			else if (map[pos.y][pos.x] == empty || map[pos.y][pos.x] == cub->player.symbol)
				render_Square(cub, pos, green);
			pos.x++;
		}
		pos.y++;
	}
	render_player(cub);
}
