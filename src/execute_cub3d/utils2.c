/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:19:48 by shikim            #+#    #+#             */
/*   Updated: 2023/10/06 17:23:53 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_window	*init_window(void)
{
	t_window	*win;

	win = (t_window *)malloc(sizeof(t_window));
	if (win == NULL)
		ctrl_error("failed to malloc\n");
	else
	{
		win->time = 0;
		win->old_time = 0;
		win->mlx = mlx_init();
		win->win = mlx_new_window(win->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "CUB");
	}
	return (win);
}
