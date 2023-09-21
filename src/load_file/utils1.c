/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:12:59 by shikim            #+#    #+#             */
/*   Updated: 2023/09/20 17:46:13 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_map	*init_map_info(void)
{
	t_map	*map_info;

	map_info = (t_map *)malloc(sizeof(t_map));
	if (map_info == NULL)
		ctrl_error("failed to malloc\n");
	else
	{
		map_info->height = 0;
		map_info->width = 0;
		map_info->map = NULL;
		map_info->player = NULL;
		map_info->texture = NULL;
	}
	return (map_info);
}

t_texture	*init_texture(void)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	if (texture == NULL)
		ctrl_error("X failed to malloc\n");
	else
	{
		texture->c_color = NULL;
		texture->f_color = NULL;
		texture->no_path = NULL;
		texture->ea_path = NULL;
		texture->so_path = NULL;
		texture->we_path = NULL;
	}
	return (texture);
}

void	get_texture(t_map *map_info, int fd)
{
	char	*line;
	int		count_texture;

	map_info->texture = init_texture();
	count_texture = 0;
	while (count_texture < 6)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		else if (compare_str(line, "\n") == TRUE)
			;
		else if (is_map_element(line) == TRUE)
			ctrl_error("check element order\n");
		else if (is_texture_element(line) != FALSE)
			count_texture += set_texture_path(map_info, line);
		else
			ctrl_error("invalid element\n");
		free(line);
	}
	if (count_texture != 6)
		ctrl_error("check texture element\n");
}
