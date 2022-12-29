/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:35:54 by hsaidi            #+#    #+#             */
/*   Updated: 2022/12/29 06:35:51 by hsaidi           ###   ########.fr       */
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

enum e_path
{
	PATH_NO,
	PATH_SO,
	PATH_EA,
	PATH_WE,
	PATH_F,
	PATH_C,
};

typedef struct s_map
{
	int		map_width;
	int		map_height;
	char	**col;
	int		player_count;
	int		player_x;
	int		more_maps;
	int		player_y;
	char	**parsing;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_map;

void	get_data(char **av, t_map *map);
int		check_xpm(char **argv, char *filename);
int		ft_check_file(char **argv, char *filename);
int		space(char pos);
int		ft_wrong_characters(char *str, int i);
void	ft_asssign_map(char **argv, t_map *map);
void	ft_count_height(char **argv, t_map *map);
void	ft_count_width(char **argv, t_map *map);
int		player(char c);
void	init_data(t_map *map);
int		skip_alpha(char *str);
int		ft_isdigit(int k);
int		map_c(char c, int flag);
int		first_wall(t_map *map);
int		last_wall(t_map *map);
int		skip_space(char *sp, int i);
int		ft_strcmp(char *s1, char *s2);
int		file_one(t_map *map, int flag);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
int		reading(t_map *map, char **av);
int		check_is_map(t_map *map, char **av);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif