/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:17:29 by shikim            #+#    #+#             */
/*   Updated: 2023/09/16 14:41:00 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_texture	*init_texture(void)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	if (texture == NULL)
	{
		show_error("failed to malloc\n");
		exit(1);
	}
	texture->ea_path = NULL;
	texture->no_path = NULL;
	texture->so_path = NULL;
	texture->we_path = NULL;
	texture->count_texture = 0;
	return (texture);
}

void	set_texture(t_map *map_info, char *map_path)
{
	char	*line;
	int		fd;

	fd = open_file(map_path);
	while (map_info->texture->count_texture < 6)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_texture_information(line) == TRUE)
			set_texture_path();
		else if (compare_str(line, '\n') == TRUE)
			;
		else
			ctrl_error("check cub file information order\n");
		free (line);
	}
	if (map_info->texture->count_texture < 6)
		ctrl_error("cehck cub file texture informaiton\n");
}

void	set_map_info(t_map *map_info, char *map_path)
{
	map_info->texture = init_texture();
	set_texture(map_info, map_path);
	return ;
}
