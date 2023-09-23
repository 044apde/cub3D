/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_graphic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:13:41 by shikim            #+#    #+#             */
/*   Updated: 2023/09/23 16:06:08 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (ray == NULL)
		ctrl_error("falied to malloc\n");
	else
	{
		ray->hit = 0;
	}
	return (ray);
}

t_wall	*init_wall(void)
{
	t_wall	*wall;

	wall = (t_wall *)malloc(sizeof(t_wall));
	if (wall == NULL)
		ctrl_error("falid to malloc\n");
	return(wall);
}

void	render_graphic(t_map *map_info, t_player *player, t_window *window)
{
	int		x;
	t_ray	*ray;
	t_wall	*wall;

	x = 0;
	ray = init_ray();
	wall = init_wall();
	printf("dir_x  :%f dir_y  :%f\n", player->dir_x, player->dir_y);
	printf("plane_x:%f  plane_y:%f\n", player->plane_x, player->plane_y);
	printf("=== === === === === === === ===\n");
	while (x <= 20)
	{
		ray->hit = 0;
		calculate_ray_dir(ray, player, map_info, x);
		calculate_where_is_ray_in(ray, player, map_info);
		calculate_delta_dist(ray);
		// calculate_side_dist(ray, player);
		// find_wall(ray, map_info);
		// calculate_distance_to_wall(ray, player);
		// calculate_wall_height(wall, ray);
		// draw_vertical_line(x, wall, window);
		// printf("side_dist_x:%f side_dist_y:%f\n", ray->side_dist_x, ray->side_dist_y);
		x++;
	}
	free(ray);
	return ;
}
