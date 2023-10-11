/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:17:12 by shikim            #+#    #+#             */
/*   Updated: 2023/10/11 16:21:51 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	move_forward(t_player *player, t_map *map_info)
{
	if (is_movable_place(map_info, player, (int)(player->pos_y + \
		player->dir_y * MOVE_TEMP), \
			(int)(player->pos_x + player->dir_x * MOVE_TEMP)) == TRUE)
	{
		player->pos_y += player->dir_y * MOVE_SPEED;
		player->pos_x += player->dir_x * MOVE_SPEED;
	}
	return ;
}

void	move_left(t_player *player, t_map *map_info)
{
	if (is_movable_place(map_info, player, (int)(player->pos_y + \
		player->dir_x * MOVE_TEMP), \
			(int)(player->pos_x - player->dir_y * MOVE_TEMP)) == TRUE)
	{
		player->pos_y += player->dir_x * MOVE_SPEED;
		player->pos_x -= player->dir_y * MOVE_SPEED;
	}
}

void	move_back(t_player *player, t_map *map_info)
{
	if (is_movable_place(map_info, player, (int)(player->pos_y - \
		player->dir_y * MOVE_TEMP), \
			(int)(player->pos_x - player->dir_x * MOVE_TEMP)) == TRUE)
	{
		player->pos_y -= player->dir_y * MOVE_SPEED;
		player->pos_x -= player->dir_x * MOVE_SPEED;
	}
}

void	move_right(t_player *player, t_map *map_info)
{
	if (is_movable_place(map_info, player, (int)(player->pos_y - \
		player->dir_x * MOVE_TEMP), \
			(int)(player->pos_x + player->dir_y * MOVE_TEMP)) == TRUE)
	{
		player->pos_y -= player->dir_x * MOVE_SPEED;
		player->pos_x += player->dir_y * MOVE_SPEED;
	}
}
