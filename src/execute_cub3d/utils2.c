/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:19:48 by shikim            #+#    #+#             */
/*   Updated: 2023/09/22 19:30:39 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_window	*init_window(void)
{
	t_window	*window;

	window = (t_window *)malloc(sizeof(t_window));
	if (window == NULL)
		ctrl_error("failed to malloc\n");
	else
	{
		window->time = 0;
		window->old_time = 0;
		window->mlx = mlx_init();
		window->win = mlx_new_window(window->mlx, 640, 480, "CUB3D");
	}
	return (window);
}
