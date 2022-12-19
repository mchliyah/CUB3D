/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:16:02 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/18 15:09:59 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int space(char pos)
{
    if(pos == 32)
        return(0);
    return(1);
}

int	ft_wrong_characters(char **str)
{
	int	i;
	int	j;

	i = 0;
		//printf("str is : %s \n", str);
	while (str[i])
	{
		//printf("character is : %s \n", str[i]);
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '0' || str[i][j] == '1' || str[i][j] == 'E'
				|| str[i][j] == 'S' || str[i][j] == 'N' || str[i][j] == 'W'
				|| str[i][j] == '\n')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
