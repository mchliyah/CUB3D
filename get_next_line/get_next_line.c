/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:28:50 by hsaidi            #+#    #+#             */
/*   Updated: 2022/02/16 21:25:37 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_for_me(char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_strlcpy(line, s, i + 1);
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *s)
{
	char	*next;
	int		i;
	int		len;

	i = 0;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	len = ft_strlen(s);
	next = (char *)malloc(sizeof(char ) * (len - i + 1));
	if (!next)
		return (NULL);
	ft_strlcpy(next, s + i, len - i + 1);
	free (s);
	return (next);
}

char	*ft_read(int fd, char *stable)
{
	char	*buff;
	int		nofbr;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	nofbr = 1;
	while (!ft_strchr(stable, '\n') && nofbr != 0)
	{
		nofbr = read(fd, buff, BUFFER_SIZE);
		if (nofbr == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nofbr] = '\0';
		stable = ft_strjoin(stable, buff);
	}
	free(buff);
	return (stable);
}

char	*get_next_line(int fd)
{
	static char	*stable;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stable = ft_read(fd, stable);
	if (!stable)
	{
		free(stable);
		return (NULL);
	}
	line = get_line_for_me(stable);
	stable = get_rest(stable);
	return (line);
}

// int main ()
// {
// 	int fd = open ("text",O_RDONLY);
// 	char *line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s",line);
// 		line = get_next_line(fd);
// 	}
// }