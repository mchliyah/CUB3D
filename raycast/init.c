/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:08:39 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/17 18:11:59 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool    init_mlx(t_cub *cub)
{
    cub->window.mlx = mlx_init();
    cub->window.win = mlx_new_window(cub->window.mlx, X, Y, "cub3D");
    cub->window.img = mlx_new_image(cub->window.mlx, X, Y);
    cub->window.img_adrs = mlx_get_data_addr(cub->window.img,
        &cub->window.bits_per_pixel, &cub->window.line_length,
        &cub->window.endian);
    return (true);
}