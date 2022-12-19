/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:21:26 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/19 01:13:42 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub.h"

void my_mlx_pixel_put(t_window *data, int x, int y, unsigned int color)
{
	char *dst;
	if (x >=0 && x < X && y >= 0 && y < Y)
	{
		dst = data->img_adrs + (y * data->line_length + x *
			(data->bits_per_pixel / 8));
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
				my_mlx_pixel_put(&cub->window, pos.x * TILESIZE +
					j, pos.y * TILESIZE + i, color);
		i++;
	}
}

void	get_cordinates(t_cub *cub)
{
	cub->ray.x_start = cub->player.x;
	cub->ray.y_start = cub->player.y;
	cub->ray.x_end = cub->player.x +
		(cub->player.ray_len * cos(cub->player.rot_angle));
	cub->ray.y_end = cub->player.y +
		(cub->player.ray_len * sin(cub->player.rot_angle));

    cub->ray.dx = abs(cub->ray.x_end - cub->ray.x_start);
    cub->ray.dy = abs(cub->ray.y_end - cub->ray.y_start);
	if (cub->ray.x_start < cub->ray.x_end)
		cub->ray.sx = 1;
	else
		cub->ray.sx = -1;
	if (cub->ray.y_start < cub->ray.y_end)
		cub->ray.sy = 1;
	else
		cub->ray.sy = -1;
	if (cub->ray.dx > cub->ray.dy)
		cub->ray.err = cub->ray.dx / 2;
	else
		cub->ray.err = -cub->ray.dy / 2;
}

void render_ray(t_cub *cub)
{
	get_cordinates(cub);
    while (1)
    {
    	my_mlx_pixel_put(&cub->window, cub->ray.x_start, cub->ray.y_start, white);
        if (cub->ray.x_start == cub->ray.x_end && cub->ray.y_start == cub->ray.y_end)
            break;
        cub->ray.e2 = cub->ray.err;
        if (cub->ray.e2 > -cub->ray.dx)
        {
            cub->ray.err -= cub->ray.dy;
            cub->ray.x_start += cub->ray.sx;
        }
        if (cub->ray.e2 < cub->ray.dy)
        {
            cub->ray.err += cub->ray.dx;
            cub->ray.y_start += cub->ray.sy;
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
	render_ray(cub);
}

t_ax	S_W_colision(t_cub *cub, int key)
{
	t_ax pos;

	if (key == S_KEY)
	{
		pos.x = cub->player.x - cub->player.speed_mov * cos(cub->player.rot_angle);
		pos.y = cub->player.y - cub->player.speed_mov * sin(cub->player.rot_angle);
	}
	if (key == W_KEY)
	{
		pos.x = cub->player.x + cub->player.speed_mov * cos(cub->player.rot_angle);
		pos.y = cub->player.y + cub->player.speed_mov * sin(cub->player.rot_angle);
	}
	return (pos);
}

t_ax	A_D_colision(t_cub *cub, int key)
{
	t_ax pos;

	if (key == A_KEY)
	{
		pos.x = cub->player.x + cub->player.speed_mov * cos(cub->player.rot_angle - M_PI_2);
		pos.y = cub->player.y + cub->player.speed_mov * sin(cub->player.rot_angle - M_PI_2);
	}
	if (key == D_KEY)
	{
		pos.x = cub->player.x + cub->player.speed_mov * cos(cub->player.rot_angle + M_PI_2);
		pos.y = cub->player.y + cub->player.speed_mov * sin(cub->player.rot_angle + M_PI_2);
	}
	return (pos);
}

bool colision(t_cub *cub , int key)
{
	t_ax pos;

	if (key == S_KEY || key == W_KEY)
		pos = S_W_colision(cub, key);
	if (key == A_KEY || key == D_KEY)
		pos = A_D_colision(cub, key);
	if (map[pos.y / (TILESIZE)][pos.x / (TILESIZE)] == wall)
		return (true);
	return (false);
}

void	A_D_events(t_cub *cub)
{
	if(cub->player.move[0] == D_KEY)
	{
		if (!colision(cub, D_KEY))
		{
			cub->player.y += cub->player.speed_mov * sin(cub->player.rot_angle + M_PI_2);
			cub->player.x += cub->player.speed_mov * cos(cub->player.rot_angle + M_PI_2);
		}
	}
	else if(cub->player.move[0] == A_KEY)
	{
		if (!colision(cub, A_KEY))
		{
			cub->player.y += cub->player.speed_mov * sin(cub->player.rot_angle - M_PI_2);
			cub->player.x += cub->player.speed_mov * cos(cub->player.rot_angle - M_PI_2);
		}
	}
}

void	S_W_events(t_cub *cub)
{
	if(cub->player.move[1] == S_KEY)
	{
		if (!colision(cub, S_KEY))
		{
			cub->player.y -= cub->player.speed_mov * sin(cub->player.rot_angle);
			cub->player.x -= cub->player.speed_mov * cos(cub->player.rot_angle);
		}
	}
	else if(cub->player.move[1] == W_KEY)
	{
		if (!colision(cub, W_KEY))
		{
			cub->player.y += cub->player.speed_mov * sin(cub->player.rot_angle);
			cub->player.x += cub->player.speed_mov * cos(cub->player.rot_angle);
		}
	}
}

void events(t_cub *cub)
{
	if (cub->player.move[0] == D_KEY || cub->player.move[0] == A_KEY)
		A_D_events(cub);
	if (cub->player.move[1] == S_KEY || cub->player.move[1] == W_KEY)
		S_W_events(cub);
	if (cub->player.move[2] == LEFT_KEY)
		cub->player.rot_angle -= cub->player.speed_rot;
	else if (cub->player.move[2] == RIGHT_KEY)
		cub->player.rot_angle += cub->player.speed_rot;
}

int	render(t_cub *cub)
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
	events(cub);
	mlx_put_image_to_window(cub->window.mlx, cub->window.win, cub->window.img, 0, 0);
	return (0);
}
