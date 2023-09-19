/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:16:08 by shikim            #+#    #+#             */
/*   Updated: 2023/09/19 23:09:37 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_texture(t_texture *texture)
{
	free (texture->no_path);
	free (texture->so_path);
	free (texture->we_path);
	free (texture->ea_path);
	free (texture->c_color);
	free (texture->f_color);
	return ;
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	return ;
}

void	free_map_info(t_map *map_info)
{
	t_texture *texture;
	t_player *player;
	char	**map;

	texture = map_info->texture;
	player = map_info->player;
	if (texture != NULL)
	{
		free_texture(texture);
		free(texture);
	}
	if (player != NULL)
		free(player);
	if (map != NULL)
	{
		free_map(map);
		free(map);
	}
	free(map_info);
	return ;
}