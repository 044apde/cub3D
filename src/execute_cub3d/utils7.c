/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:17:12 by shikim            #+#    #+#             */
/*   Updated: 2023/10/06 17:26:50 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	move_forward(t_player *player, t_map *map_info)
{
	if (is_movable_place(map_info, (int)(player->pos_y + player->dir_y * MOVE_SPEED), (int)(player->pos_x + player->dir_x * MOVE_SPEED)) == TRUE)
	{
		player->pos_y += player->dir_y * MOVE_SPEED;
		player->pos_x += player->dir_x * MOVE_SPEED;
	}
	return ;
}

void	move_left(t_player *player, t_map *map_info)
{
	if (is_movable_place(map_info, (int)(player->pos_y + player->dir_x * MOVE_SPEED), (int)(player->pos_x - player->dir_y * MOVE_SPEED)) == TRUE)
	{
		player->pos_y += player->dir_x * MOVE_SPEED;
		player->pos_x -= player->dir_y * MOVE_SPEED;
	}
}

void	move_back(t_player *player, t_map *map_info)
{
	if (is_movable_place(map_info, (int)(player->pos_y - player->dir_y * MOVE_SPEED), (int)(player->pos_x - player->dir_x * MOVE_SPEED)) == TRUE)
	{
		player->pos_y -= player->dir_y * MOVE_SPEED;
		player->pos_x -= player->dir_x * MOVE_SPEED;
	}
}

void	move_right(t_player *player, t_map *map_info)
{
	if (is_movable_place(map_info, (int)(player->pos_y - player->dir_x * MOVE_SPEED), (int)(player->pos_x + player->dir_y * MOVE_SPEED)) == TRUE)
	{
		player->pos_y -= player->dir_x * MOVE_SPEED;
		player->pos_x += player->dir_y * MOVE_SPEED;
	}
}