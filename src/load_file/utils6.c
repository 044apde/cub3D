/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:29:50 by shikim            #+#    #+#             */
/*   Updated: 2023/10/08 15:22:58 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_map_component(char component)
{
	if (component == '0')
		return (TRUE);
	else if (component == '1')
		return (TRUE);
	else if (component == 'N')
		return (TRUE);
	else if (component == 'S')
		return (TRUE);
	else if (component == 'E')
		return (TRUE);
	else if (component == 'W')
		return (TRUE);
	else if (component == ' ')
		return (TRUE);
	return (FALSE);
}

void	check_starting_position(char **map, t_map *map_info)
{
	int	height;
	int	width;
	int	flag_postion;

	height = -1;
	flag_postion = FALSE;
	while (++height < map_info->height)
	{
		width = -1;
		while (++width < map_info->width)
		{
			if (map[height][width] == 'N' || map[height][width] == 'S' || \
				map[height][width] == 'E' || map[height][width] == 'W')
			{
				if (flag_postion == FALSE)
					flag_postion = TRUE;
				else
					ctrl_error("starting point is duplicated\n");
			}
		}
	}
	if (flag_postion == FALSE)
		ctrl_error("there is no starting point\n");
}

int	is_empty_space(char component)
{
	if (component == '0')
		return (TRUE);
	else if (component == 'N')
		return (TRUE);
	else if (component == 'S')
		return (TRUE);
	else if (component == 'E')
		return (TRUE);
	else if (component == 'W')
		return (TRUE);
	return (FALSE);
}

void	check_is_surrouned(char **map, int h, int w, t_map *map_info)
{
	check_north_is_empty(map, h, w);
	check_south_is_empty(map_info, map, h, w);
	check_east_is_empty(map_info, map, h, w);
	check_west_is_empty(map, h, w);
}

void	check_map_is_closed(char **map, t_map *map_info)
{
	int	column;
	int	row;

	column = 0;
	while (column < map_info->height)
	{
		row = 0;
		while (row < map_info->width)
		{
			if (map[column][row] == '0' || map[column][row] == 'N' || \
				map[column][row] == 'S' || map[column][row] == 'E' || \
				map[column][row] == 'W')
				check_is_surrouned(map, column, row, map_info);
			++row;
		}
		++column;
	}
}
