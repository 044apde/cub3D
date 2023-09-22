/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_graphic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:13:41 by shikim            #+#    #+#             */
/*   Updated: 2023/09/22 21:30:19 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (ray == NULL)
		ctrl_error("falied to malloc\n");
	return (ray);
}

void	render_graphic(t_map *map_info, t_player *player)
{
	int		x;
	t_ray	*ray;

	x = -1;
	ray = init_ray();
	printf("dir_x  :%f dir_y  :%f\n", player->dir_x, player->dir_y);
	printf("plane_x:%f  plane_y:%f\n", player->plane_x, player->plane_y);
	printf("=== === === === === === === ===\n");
	while (++x <= map_info->width)
	{
		calculate_ray_dir(ray, player, map_info, x);
		calculate_where_is_ray_in(ray, player, map_info);
		calculate_delta_dist(ray);
		calculate_side_dist(ray, player);
		printf("side_dist_x:%f side_dist_y:%f\n", ray->side_dist_x, ray->side_dist_y);
	}
	return ;
}
