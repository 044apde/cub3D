/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:29:50 by shikim            #+#    #+#             */
/*   Updated: 2023/09/20 17:40:01 by shikim           ###   ########.fr       */
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

	height = 0;
	flag_postion = FALSE;
	while (height < map_info->height)
	{
		width = 0;
		while (width < map_info->width)
		{
			if (map[height][width] == 'N' || map[height][width] == 'S' || \
				map[height][width] == 'E' || map[height][width] == 'W')
			{
				if (flag_postion == FALSE)
					flag_postion = TRUE;
				else
					ctrl_error("starting point is duplicated\n");
			}
			++width;
		}
		++height;
	}
}

void	check_map_is_closed()
{
	
	return ;
}
