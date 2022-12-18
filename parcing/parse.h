/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:35:54 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/18 11:37:48 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
// # include <mlx.h>
// # include <math.h>
# include "../get_next_line/get_next_line.h"

typedef struct s_map
{
	int		map_width;
	int		map_height;
	char	**parsing;
	int		fd;
}	t_map;

int	ft_check_file(char **argv, char *filename);
int space(char pos);
int	ft_wrong_characters(char **str);
void	ft_asssign_map(char **argv, t_map *map);
void	ft_count_height(char **argv, t_map *map);
void	ft_count_width(char **argv, t_map *map);

#endif