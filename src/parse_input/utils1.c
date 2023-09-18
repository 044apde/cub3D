/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:20:44 by shikim            #+#    #+#             */
/*   Updated: 2023/09/17 16:35:27 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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
	if (len < 4)
	{
		show_error("check map name\n");
		exit(1);
	}
	if (map_name[len - 1] != 'b' || \
		map_name[len - 2] != 'u' || \
		map_name[len - 3] != 'c' || \
		map_name[len - 4] != '.')
	{
		show_error("check map extension\n");
		exit(1);
	}
	return ;
}

void	check_map_file(char *map_path)
{
	int	fd;

	fd = open_file(map_path);
	close (fd);
	return ;
}