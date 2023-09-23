/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:24:07 by shikim            #+#    #+#             */
/*   Updated: 2023/09/23 16:08:05 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	absolutilize(double num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}

void	calculate_ray_dir(t_ray *ray, t_player *player, t_map *map_info, int x)
{
	int	map_width;

	map_width = map_info->width;
	ray->camera_x = 2 * (x / (double)map_width) - 1;
	ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera_x;
	return ;
}

void	calculate_where_is_ray_in(t_ray *ray, t_player *player, t_map *map_info)
{
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	printf("map_x:%d map_y:%d ", ray->map_x, ray->map_y);
	return ;
}

void	calculate_delta_dist(t_ray *ray)
{
	if (ray->ray_dir_x != 0)
		ray->delta_dist_x = sqrt(1 + (ray->ray_dir_y * ray->ray_dir_y) / (ray->ray_dir_x * ray->ray_dir_x));
	else
		ray->delta_dist_x = 0;
	if (ray->ray_dir_y != 0)
		ray->delta_dist_y = sqrt(1 + (ray->ray_dir_x * ray->ray_dir_x) / (ray->ray_dir_y * ray->ray_dir_y));
	else
		ray->delta_dist_y = 0;
	printf("ray_dir_x: %f ray_dir_y: %f delta_dist_x: %f delta_dist_y: %f\n", ray->ray_dir_x, ray->ray_dir_y , ray->delta_dist_x, ray->delta_dist_y);
	return ;
}
