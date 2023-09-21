/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:29:50 by shikim            #+#    #+#             */
/*   Updated: 2023/09/21 15:08:57 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*move_to_map_element(int fd)
{
	char	*line;

	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		else if (compare_str(line, "\n") == TRUE)
			;
		else if (is_texture_element(line) != FALSE)
			;
		else if (is_map_element(line) == TRUE)
			break ;
		free(line);
	}
	return (line);
}

char	**init_map(t_map *map_info)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (map_info->height + 1));
	i = 0;
	if (map == NULL)
		ctrl_error("faild to malloc\n");
	else
	{
		map[map_info->height] = NULL;
		while (map[i] != NULL)
		{
			map[i] = (char *)malloc(sizeof(char) *(map_info->width + 1));
			if (map[i] == NULL)
				ctrl_error("faild to malloc\n");
			map[i][map_info->width] = '\0';
			++i;
		}
	}
	return (map);
}

void	set_map_component(char **map, char *line)
{
	static int	height = 0;
	int			width;

	width = 0;
	while (line[width] != '\0' && line[width] != '\n')
	{
		if (is_map_component(line[width]) == FALSE)
			ctrl_error("check map element's component\n");
		map[height][width] = line[width];
		width++;
	}
	height++;
	return ;
}

void	pre_set_map(char **map, t_map *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		while (j < map_info->width)
		{
			map[i][j] = ' ';
			j++;
		}
		i++;
	}
	return ;
}

char	**make_map_array(t_map *map_info, char *map_path)
{
	int		fd;
	char	*line;
	char	**map;

	fd = open_file(map_path);
	line = move_to_map_element(fd);
	map = init_map(map_info);
	pre_set_map(map, map_info);
	while (TRUE)
	{
		if (line == NULL)
			break ;
		else if (compare_str(line, "\n") == TRUE)
			;
		else if (is_map_element(line) == TRUE)
			set_map_component(map, line);
		else
			ctrl_error("invalid map element\n");
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
