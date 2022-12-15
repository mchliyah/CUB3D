/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:20:14 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/15 00:48:50 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
