/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:16:02 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/23 08:43:03 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int space(char pos)
{
    if(pos == 32 || pos == '\t')
        return(1);
    return(0);
}

// char	*ft_strdup(const char *s1)
// {
// 	int		i;
// 	char	*str;

// 	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
// 	if (!str)
// 		return (NULL);
// 	if (!s1)
// 		return (NULL);
// 	i = -1;
// 	while (s1[++i])
// 		str[i] = s1[i];
// 	str[i] = '\0';
// 	return (str);
// }

int player(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			return (1);
	return (0);
}

int	map_c(char c, int flag)
{
	if(flag == 1)
	{
		if (c == '1' || c == '0')
			return (1);
	}
	if (flag == 2)
	{
		if (c == '1' || c == '0' || player(c))
			return (1);
	}
	return (0);
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
				|| str[i][j] == '\n' || str[i][j] == 32)
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
