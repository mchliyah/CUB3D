/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 20:16:27 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/31 20:32:19 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

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

int	skip_space(char *sp, int i)
{
	while (space(sp[i]))
		i++;
	return (i);
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

int	check_is_map(char **av)
{
	int	i;
	int	p;
	int	invalid;

	invalid = 0;
	i = 0;
	while (av[i])
	{
		p = 0;
		while (av[i][p])
		{
			if ((skip_alpha(av[i]) == 0))
				invalid = 1;
			else
			{
				invalid = 0;
				break ;
			}
			p++;
		}
		if (invalid != 1)
			break ;
		invalid = 0;
		i++;
	}
	return (i);
}
