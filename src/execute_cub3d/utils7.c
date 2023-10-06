/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:17:12 by shikim            #+#    #+#             */
/*   Updated: 2023/10/06 13:55:54 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	move_forward(t_player *player, t_map *map_info)
{
	if (is_movable_place(map_info, (int)(player->pos_y + player->dir_y * MOVE_SPEED), (int)(player->pos_x + player->dir_x * MOVE_SPEED)) == TRUE)
	{
		player->pos_x += player->dir_x * MOVE_SPEED;
		player->pos_y += player->dir_y * MOVE_SPEED;
		printf("x:%f y:%f\n", player->pos_x, player->pos_y);
		printf("x:%d y:%d\n", (int)player->pos_x, (int)player->pos_y);
	}
	return ;
}

void	move_left(t_player *player, t_map *map_info)
{
	if (is_movable_place(map_info, (int)(player->pos_y + player->dir_y * MOVE_SPEED + 0.1), (int)(player->pos_x - player->dir_x * MOVE_SPEED)) == TRUE)
	{
		player->pos_x -= player->dir_y * MOVE_SPEED;
		player->pos_y += player->dir_x * MOVE_SPEED;
		printf("x:%f y:%f\n", player->pos_x, player->pos_y);
		printf("x:%d y:%d\n", (int)player->pos_x, (int)player->pos_y);
	}
}

void	move_back(t_player *player, t_map *map_info)
{
	if (is_movable_place(map_info, (int)(player->pos_y - player->dir_y * MOVE_SPEED - 0.1), (int)(player->pos_x - player->dir_x * MOVE_SPEED - 0.1)) == TRUE)
	{
		player->pos_x -= player->dir_x * MOVE_SPEED;
		player->pos_y -= player->dir_y * MOVE_SPEED;
		printf("x:%f y:%f\n", player->pos_x, player->pos_y);
		printf("x:%d y:%d\n", (int)player->pos_x, (int)player->pos_y);
	}
}

void	move_right(t_player *player, t_map *map_info)
{
	if (is_movable_place(map_info, (int)(player->pos_y - player->dir_y * MOVE_SPEED - 0.1), (int)(player->pos_x + player->dir_x * MOVE_SPEED + 0.1)) == TRUE)
	{
		player->pos_x += player->dir_y * MOVE_SPEED;
		player->pos_y -= player->dir_x * MOVE_SPEED;
		printf("x:%f y:%f\n", player->pos_x, player->pos_y);
		printf("x:%d y:%d\n", (int)player->pos_x, (int)player->pos_y);
	}
}