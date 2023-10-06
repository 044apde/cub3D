/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:12:23 by shikim            #+#    #+#             */
/*   Updated: 2023/10/06 17:20:15 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_render	*init_render(t_player *player, t_window *window, t_map *map_info)
{
	t_render	*render;

	render = (t_render *)malloc(sizeof(t_render));
	if (render == NULL)
		ctrl_error("failed to malloc\n");
	else
	{
		render->map_info = map_info;
		render->player = player;
		render->window = window;
	}
	return (render);
}

void	execute_cub3d(t_map *map_info)
{
	t_player	*player;
	t_window	*window;
	t_render	*render;

	player = init_player(map_info);
	window = init_window();
	render = init_render(player, window, map_info);
	mlx_hook(window->win, 2, 1L << 0, key_hook, render);
	mlx_loop_hook(window->mlx, render_graphic, render);
	mlx_loop(window->mlx);
	free(player);
	free(window);
	free(render);
	return ;
}
