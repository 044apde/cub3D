/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:19:16 by shikim            #+#    #+#             */
/*   Updated: 2023/09/21 16:07:40 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_player_position(t_map *map_info, t_player *player)
{
	char	**map;
	int		h;
	int		w;

	map = map_info->map;
	h = -1;
	while (++h < map_info->height)
	{
		w = -1;
		while (++w < map_info->width)
		{
			if (map[h][w] == 'N' || map[h][w] == 'S' || \
				map[h][w] == 'E' || map[h][w] == 'W')
			{
				player->pos_x = w;
				player->pos_y = h;
				player->direction = map[h][w];
				break ;
			}
		}
	}
	return ;
}

void	init_player_direction(t_player *player)
{ 
	if (player->direction == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (player->direction == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (player->direction == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (player->direction == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
}

void	init_camera_plane(t_player *player)
{
	if (player->direction == 'N')
	{
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (player->direction == 'S')
	{
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (player->direction == 'E')
	{
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (player->direction == 'W')
	{
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
}

t_player	*init_player(t_map *map_info)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (player == NULL)
		ctrl_error("faild to malloc\n");
	else
	{
		init_player_position(map_info, player);
		printf("y:%f x:%f\n", player->pos_y, player->pos_x);
		init_player_direction(player);
		printf("y:%f x:%f\n", player->dir_y, player->dir_x);
		init_camera_plane(player);
		printf("y:%f x:%f\n", player->plane_y, player->plane_x);
	}
	return (player);
}
