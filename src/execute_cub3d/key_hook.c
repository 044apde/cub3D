/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:08:32 by shikim            #+#    #+#             */
/*   Updated: 2023/09/22 19:10:33 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	end_cub3d(void)
{
	printf("End game..\n");
	exit(0);
}

int	key_hook(int keycode, t_window *window)
{
	if (keycode == 53)
		end_cub3d();
	return (0);
}
