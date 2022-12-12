/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:27:39 by mchliyah          #+#    #+#             */
/*   Updated: 2022/12/12 12:18:00 by mchliyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "cub.h"

bool init(t_cub cub){
	if (!windowinit())
		exit_error("eroor windows ");
}

int	main(int ac, char **av)
{
	t_cub  *cub;

	cub = malloc(sizeof(t_cub));
	if (!init(cub))
		exit_error("init error");
	
	return (0);
}
