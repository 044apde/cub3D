/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:10:48 by shikim            #+#    #+#             */
/*   Updated: 2023/09/16 14:31:21 by shikim           ###   ########.fr       */
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

char	*make_map_path(char *map_name)
{
	char	*map_path;

	map_path = "map/";
	map_path = ft_strjoin(map_path, map_name);
	return (map_path);
}

void	check_map_name(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len <= 4)
	{
		show_error("check map name\n");
		exit(1);
	}
	if (map_name[len - 1] != 'b' ||
		map_name[len - 2] != 'u' ||
		map_name[len - 3] != 'c' ||
		map_name[len - 4] != '.')
	{
		show_error("check map extension\n");
		exit(1);
	}
	return ;
}

t_map	*init_map_info(char *map_path)
{
	t_map	*map_info;

	map_info = (t_map *)malloc(sizeof(t_map));
	if (map_info == NULL)
	{
		show_error("failed to malloc\n");
		exit(1);
	}
	map_info->height = -1;
	map_info->width = -1;
	map_info->map = NULL;
	map_info->texture = NULL;
	return (map_info);
}

void	check_map_path(char *map_path)
{
	int	fd;

	fd = open_file(map_path);
	close (fd);
	return ;
}

t_map	*parse_map_info(char *map_name)
{
	char	*map_path;
	t_map	*map_info;
	int	 	fd;

	check_map_name(map_name);
	map_path = make_map_path(map_name);
	check_map_path(map_path);
	map_info = init_map_info(map_path);
	set_map_info(map_info, map_path);
	return (map_info);
}
