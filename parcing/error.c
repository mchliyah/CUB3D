/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:47:16 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/12 20:22:57 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	exit_error(char *strerr)
{
	write(2, strerr, ft_strlen(strerr));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
