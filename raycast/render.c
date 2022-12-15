/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:21:26 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/15 22:38:38 by mchliyah         ###   ########.fr       */
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

void	render_player(t_cub *cub)
{
	double i;
	double j;

	j = cub->player.y - 2;
	
	if (j < 0)
		j = 0;
	while (j < cub->player.y + 2)
	{
		i = cub->player.x - 2;
		if (i < 0)
			i = 0;
		while (i < cub->player.x + 2)
		{
			my_mlx_pixel_put(&cub->window, i, j, blue);
			i++;
		}
		j++;
	}
}

void get_player_pos(t_cub *cub)
{
    int i = 0;
    int j = 0;
    while (i < 5)
    {
        j = 0;
        while (j < ft_strlen1(map[i]))
        {
            if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
            {
                cub->player.symbol = map[i][j];
                cub->player.x = j * TILESIZE + (TILESIZE / 2);
                cub->player.y = i * TILESIZE + (TILESIZE / 2);
            }
            j++;
        }
        i++;
    }
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
