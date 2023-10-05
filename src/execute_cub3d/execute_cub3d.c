/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:12:23 by shikim            #+#    #+#             */
/*   Updated: 2023/10/05 23:48:06 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	execute_cub3d(t_map *map_info)
{
	t_player	*player;
	t_window	*window;
	t_temp		temp;

	player = init_player(map_info);
	window = init_window();
	temp.player = player;
	temp.window = window;
	temp.map_info = map_info;
	mlx_hook(window->win, 2, 1L<<0, key_hook, &temp);
	mlx_loop_hook(window->mlx, render_graphic, &temp);
	mlx_loop(window->mlx);
	return ;
}
