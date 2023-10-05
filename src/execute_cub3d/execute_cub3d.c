/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:12:23 by shikim            #+#    #+#             */
/*   Updated: 2023/09/23 17:10:37 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	execute_cub3d(t_map *map_info)
{
	t_player	*player;
	t_window	*window;

	player = init_player(map_info);
	window = init_window();
	mlx_key_hook(window->win, key_hook, window);
	render_graphic(map_info, player, window);
	mlx_loop(window->mlx);
	return ;
}
