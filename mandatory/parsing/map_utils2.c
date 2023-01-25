/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:23:26 by hsaidi            #+#    #+#             */
/*   Updated: 2023/01/06 13:23:29 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	skip_alpha(char *str)
{
	if (str)
	{
		while (*str == 32 || *str == '\t')
			str++;
		if (ft_isdigit(*str) == 1)
			return (1);
	}
	return (0);
}

int	file_one(t_map *map, int flag)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 0;
	j = 0;
	(void)flag;
	while (map->parsing[i])
	{
		j = is_param_first(map->parsing[i]);
		if (!j)
			size++;
		else if (j == 2)
			break ;
		i++;
	}
	return (size - 1);
}
