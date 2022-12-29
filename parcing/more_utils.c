/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:43:08 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/28 20:19:22 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void init_data(t_map *map)
{
    map->no = NULL;
    map->ea = NULL;
    map->so = NULL;
    map->we = NULL;
    map->player_count = 0;
    map->player_x = -1;
    map->player_y = -1;
}