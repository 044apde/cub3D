/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:17:29 by shikim            #+#    #+#             */
/*   Updated: 2023/09/17 11:31:02 by shikim           ###   ########.fr       */
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
	texture->f_color = NULL;
	texture->c_color = NULL;
	texture->count_texture = 0;
	return (texture);
}

void	set_texture_path(t_map *map_info, char *line)
{
	int	texture_identifier;

	texture_identifier = is_texture_information(line);
	if (texture_identifier == NO && map_info->texture->no_path == NULL)
		map_info->texture->no_path = ft_split(line, ' ')[1];
	else if (texture_identifier == SO && map_info->texture->so_path == NULL)
		map_info->texture->so_path = ft_split(line, ' ')[1];
	else if (texture_identifier == WE && map_info->texture->we_path == NULL)
		map_info->texture->we_path = ft_split(line, ' ')[1];
	else if (texture_identifier == EA && map_info->texture->ea_path == NULL)
		map_info->texture->ea_path = ft_split(line, ' ')[1];
	else if (texture_identifier == F && map_info->texture->f_color == NULL)
		map_info->texture->f_color = ft_split(line, ' ')[1];
	else if (texture_identifier == C && map_info->texture->c_color == NULL)
		map_info->texture->c_color = ft_split(line, ' ')[1];
	else
		ctrl_error("map information's identifier is duplicated\n");
	map_info->texture->count_texture++;
}

void	show_texture_path(t_texture *texture)
{
	printf("%s", texture->no_path);
	printf("%s", texture->so_path);
	printf("%s", texture->ea_path);
	printf("%s", texture->we_path);
	printf("%s", texture->f_color);
	printf("%s", texture->c_color);
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
		if (is_texture_information(line) != FALSE)
			set_texture_path(map_info, line);
		else if (compare_str(line, "\n") == TRUE)
			;
		else
			ctrl_error("check cub file information order\n");
		free (line);
	}
	if (map_info->texture->count_texture < 6)
		ctrl_error("need six texture information\n");
	show_texture_path(map_info->texture); // Test texture path
}

void	set_map_info(t_map *map_info, char *map_path)
{
	map_info->texture = init_texture();
	set_texture(map_info, map_path);
	return ;
}
