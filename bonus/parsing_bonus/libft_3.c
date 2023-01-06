/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 03:18:54 by hsaidi            #+#    #+#             */
/*   Updated: 2023/01/06 03:19:14 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static int	ft_checklong(int res, int count, int is_neg)
{
	if (count > 19)
	{
		if (is_neg == -1)
			return (0);
		else if (is_neg == 1)
			return (-1);
	}
	return (res * is_neg);
}

static int	ft_loop(const char *str, int i, int count, int is_neg)
{
	int	p;
	int	res;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i++] - '0');
		count++;
	}
	p = ft_checklong(res, count, is_neg);
	return (p);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	is_neg;
	int	count;
	int	p;

	is_neg = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	if (is_neg == -1 || str[i] == '+')
		i++;
	count = 0;
	p = ft_loop(str, i, count, is_neg);
	return (p);
}