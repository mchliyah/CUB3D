/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:40:37 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/31 20:17:15 by hsaidi           ###   ########.fr       */
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
