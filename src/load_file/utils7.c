/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:27:20 by shikim            #+#    #+#             */
/*   Updated: 2023/09/21 15:05:07 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_north_is_empty(t_map *map_info, char **map, int h, int w)
{
	if (h - 1 < 0)
		ctrl_error("map must be closed by wall\n");
	else if (is_empty_space(map[h - 1][w]) == FALSE && map[h - 1][w] != '1')
		ctrl_error("map must be closed by wall\n");
	return ;
}

void	check_south_is_empty(t_map *map_info, char **map, int h, int w)
{
	if (h + 1 >= map_info->height)
		ctrl_error("map must be closed by wall\n");
	else if (is_empty_space(map[h + 1][w]) == FALSE && map[h + 1][w] != '1')
		ctrl_error("map must be closed by wall\n");
	return ;
}

void	check_east_is_empty(t_map *map_info, char **map, int h, int w)
{
	if (w + 1 >= map_info->width)
		ctrl_error("map must be closed by wall\n");
	else if (is_empty_space(map[h][w + 1]) == FALSE && map[h][w + 1] != '1')
		ctrl_error("map must be closed by wall\n");
	return ;
}

void	check_west_is_empty(t_map *map_info, char **map, int h, int w)
{
	if (w - 1 < 0)
		ctrl_error("map must be closed by wall\n");
	else if (is_empty_space(map[h][w - 1]) == FALSE && map[h][w - 1] != '1')
		ctrl_error("map must be closed by wall\n");
	return ;
}
