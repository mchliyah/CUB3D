/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 04:43:26 by mchliyah          #+#    #+#             */
/*   Updated: 2023/01/05 14:47:03 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../includes/cub.h"

void	get_player_pos(t_cub *cub)
{
	int	i;
	int	j;

	i = 8;
	j = 0;
	while (i < cub->map.height)
	{
		j = 0;
		while (j < ft_strlen1(cub->map.parsing[i]))
		{
			if (cub->map.parsing[i][j] == 'N' || cub->map.parsing[i][j] == 'S'
				|| cub->map.parsing[i][j] == 'E'
				|| cub->map.parsing[i][j] == 'W')
			{
				cub->player.symbol = cub->map.parsing[i][j];
				cub->player.x = j * TILESIZE + (TILESIZE / 2);
				cub->player.y = i * TILESIZE + (TILESIZE / 2);
			}
			j++;
		}
		i++;
	}
}

void	dda(t_cub *cub)
{
	t_ax	end;
	t_ax	strt;
	t_ax	d;
	t_ax	incr;
	int		i;

	strt.x = cub->player.x * SCL;
	strt.y = cub->player.y * SCL;
	end.x = (cub->player.x - (80 * cos(cub->player.rot_angle))) * SCL;
	end.y = (cub->player.y - (80 * sin(cub->player.rot_angle))) * SCL;
	d.x = cub->player.x * SCL - end.x;
	d.y = cub->player.y * SCL - end.y;
	if (fabs(d.x) > fabs(d.y))
		incr.steps = fabs(d.x);
	else
		incr.steps = fabs(d.y);
	incr.x = d.x / (float) incr.steps;
	incr.y = d.y / (float) incr.steps;
	i = -1;
	while (++i <= incr.steps)
	{
		my_mlx_pixel_put(&cub->window, strt.x, strt.y, RED);
		strt.x += incr.x;
		strt.y += incr.y;
	}
}

void	render_player(t_cub *cub)
{
	int	i;
	int	j;

	i = cub->player.y * SCL - 2;
	while (i < cub->player.y * SCL + 2)
	{
		j = cub->player.x * SCL - 2;
		while (++j < cub->player.x * SCL + 2)
			my_mlx_pixel_put(&cub->window, j, i, RED);
		i++;
	}
	dda(cub);
}

void	player_update(t_cub *cub)
{
	if (cub->player.rot_angle > 0 && cub->player.rot_angle < M_PI)
		cub->player.facing_up = false;
	else
		cub->player.facing_up = true;
	if (cub->player.rot_angle < 0.5 * M_PI
		|| cub->player.rot_angle > 1.5 * M_PI)
		cub->player.facing_right = true;
	else
		cub->player.facing_right = false;
}
