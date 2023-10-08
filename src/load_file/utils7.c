/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:27:20 by shikim            #+#    #+#             */
/*   Updated: 2023/10/08 14:24:10 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	trim_texture_path(t_map *map_info)
{
	char	*dangling;

	dangling = map_info->texture->no_path;
	map_info->texture->no_path = ft_strtrim(map_info->texture->no_path, "\n");
	free(dangling);
	dangling = map_info->texture->so_path;
	map_info->texture->so_path = ft_strtrim(map_info->texture->so_path, "\n");
	free(dangling);
	dangling = map_info->texture->ea_path;
	map_info->texture->ea_path = ft_strtrim(map_info->texture->ea_path, "\n");
	free(dangling);
	dangling = map_info->texture->we_path;
	map_info->texture->we_path = ft_strtrim(map_info->texture->we_path, "\n");
	free(dangling);
	return ;
}

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
