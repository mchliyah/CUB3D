/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:46:43 by hsaidi            #+#    #+#             */
/*   Updated: 2023/01/04 22:00:40 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int	ft_isdigit(int k)
{
	if (k >= '0' && k <= '9')
		return (1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	if (!s1)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*s1;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
			len = ft_strlen(s);
	s1 = (char *)malloc(sizeof(char) * len + 1);
	if (!s1)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	if (start < size)
	{
		while (i < len)
		{
			s1[i] = s[start];
			start++;
			i++;
		}
	}
	s1[i] = '\0';
	return (s1);
}
