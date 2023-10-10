/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:42:25 by shikim            #+#    #+#             */
/*   Updated: 2023/10/10 15:13:49 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	open_file(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		show_error("can't open file\n");
		exit(1);
	}
	return (fd);
}

void	show_map(char **map, t_map *map_info)
{
	int	width;
	int	height;

	height = 0;
	while (height < map_info->height)
	{
		width = 0;
		while (width < map_info->width)
		{
			printf("%c", map[height][width]);
			width++;
		}
		printf("\n");
		height++;
	}
}
