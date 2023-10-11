/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:00:32 by shikim            #+#    #+#             */
/*   Updated: 2023/10/11 16:37:38 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_diagonal_move(t_map *map_info, t_player *player, int where_to_go)
{
	if (where_to_go == LEFT_DOWN)
	{
		if (map_info->map[(int)player->pos_y][(int)player->pos_x - 1] == '1'\
			&& map_info->map[(int)player->pos_y - 1][(int)player->pos_x] == '1')
			return (FALSE);
	}
	else if (where_to_go == LEFT_UP)
	{
		if (map_info->map[(int)player->pos_y][(int)player->pos_x - 1] == '1' \
			&& map_info->map[(int)player->pos_y + 1][(int)player->pos_x] == '1')
			return (FALSE);
	}
	else if (where_to_go == RIGHT_UP)
	{
		if (map_info->map[(int)player->pos_y][(int)player->pos_x + 1] == '1' \
			&& map_info->map[(int)player->pos_y + 1][(int)player->pos_x] == '1')
			return (FALSE);
	}
	else if (where_to_go == RIGHT_DOWN)
	{
		if (map_info->map[(int)player->pos_y][(int)player->pos_x + 1] == '1' \
			&& map_info->map[(int)player->pos_y - 1][(int)player->pos_x] == '1')
			return (FALSE);
	}
	return (TRUE);
}
