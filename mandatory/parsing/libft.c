/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:40:37 by hsaidi            #+#    #+#             */
/*   Updated: 2023/01/05 14:46:23 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static int	words(char *str, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] && str[i] != c)
		{
			i++;
			j++;
		}
		while (str[i] && str[i] != c)
			i++;
	}
	return (j);
}

static int	carcts(char *str, char c)
{
	int			i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	return (i);
}

static char	*allocandfill(char **tab, char *src, char c)
{
	int			i;
	int			j;
	int			k;

	j = 0;
	k = 0;
	while (src[k] == c)
		k++;
	while (j < words(src, c))
	{
		i = 0;
		tab[j] = malloc(sizeof(char) * (carcts(&src[k], c) + 1));
		if (!tab[j])
			return (NULL);
		while (src[k] != c && src[k])
			tab[j][i++] = src[k++];
		tab[j][i] = '\0';
		while (src[k] == c && src[k])
			k++;
		j++;
	}
	tab[j] = NULL;
	return (*tab);
}

char	**ft_split(char const *s, char c)
{
	int			j;
	char		**tab;
	char		*str;

	j = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	tab = malloc(sizeof(char *) * (words(str, c) + 1));
	if (!tab)
		return (NULL);
	tab[j] = allocandfill(tab, str, c);
	return (tab);
}
