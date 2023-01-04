/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:35:54 by hsaidi            #+#    #+#             */
/*   Updated: 2023/01/04 18:04:02 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
// # include <mlx.h>
// # include <math.h>
# include "get_next_line.h"

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
	int		valid_i;
	int		width;
	int		height;
	char	**col;
	int		player_count;
	int		player_x;
	int		char_count;
	int		player_y;
	char	**parsing;
	int		floor;
	int		ceiling;
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}	t_map;

				//parsing//

void	get_data(char **av, t_map *map);
int		check_xpm(char **argv, char *filename);
int		ft_check_file(char **argv, char *filename);
int		space(char pos);
int		ft_wrong_characters(char *str, int i);
void	ft_asssign_map(char **argv, t_map *map);
void	ft_count_hheight(char **argv, t_map *map);
void	ft_count_width(char **argv, t_map *map);
int		player(char c);
void	init_data(t_map *map);
int		skip_alpha(char *str);
int		map_c(char c, int flag);
int		is_not_texter(char *str, int i);
int		first_wall(t_map *map);
void	texters(t_map *map ,char *av, int i, int flag);
int		last_wall(t_map *map, int last_wal);
int		skip_space(char *sp, int i);
int		check_top2(char *var, int j);
int		file_one(t_map *map, int flag);
int		check_is_map(char **av);
void	color_checking(t_map *map, char *color_l, int flag);
int		file_one(t_map *map, int flag);
int		create_trgb(int t, int r, int g, int b);
int		is_color(char *colors, t_map *map);
int		is_param_first(char *str);
int		player_protection(t_map *map, int i, int p);
int		skip_alpha(char *str);
int	reading(t_map *map);

				//libft//
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isdigit(int k);
int		ft_strcmp(char *s1, char *s2);

//add by mchliyah
void	if_map_valid(t_map *map);
#endif