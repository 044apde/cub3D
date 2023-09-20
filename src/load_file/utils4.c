/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:27:09 by shikim            #+#    #+#             */
/*   Updated: 2023/09/20 15:53:42 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	set_map_width(t_map *map_info, char *line)
{
	int	width;

	width = 0;
	while (line[width] != '\0' && line[width] != '\n')
		++width;
	if (map_info->width < width)
		map_info->width = width;
	return ;
}

char	*skip_empty_line(int fd)
{
	char	*line;

	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		else if (compare_str(line, "\n") == TRUE)
			;
		else
			break ;
		free(line);
	}
	return (line);
}

void	set_map_width_height(t_map *map_info, int fd)
{
	char	*line;
	int		empty_line_flag;

	line = skip_empty_line(fd);
	while (TRUE)
	{
		if (line == NULL)
			break ;
		else if (compare_str(line, "\n") == TRUE)
			empty_line_flag = TRUE;
		else if (is_map_element(line) == TRUE)
		{
			if (empty_line_flag == TRUE)
				ctrl_error("empty line between map element\n");
			map_info->height = map_info->height + 1;
			set_map_width(map_info, line);
		}
		else
			ctrl_error("invalid map element\n");
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	get_map(t_map *map_info, int fd, char *map_path)
{
	set_map_width_height(map_info, fd);
	printf("width: %d height: %d\n", map_info->width, map_info->height);
	map_info->map =  make_map_array(map_info, map_path);
	// check_map_is_closed(map_info->map);
	return ;
}
