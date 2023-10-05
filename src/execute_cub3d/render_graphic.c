/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_graphic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:13:41 by shikim            #+#    #+#             */
/*   Updated: 2023/10/05 12:23:38 by shikim           ###   ########.fr       */
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

void	free_renderm_memory(t_ray *ray, t_wall *wall)
{
	free(ray);
	free(wall);
	return ;
}

void	draw_screen(t_map *map_info, t_player *player, t_window *window)
{
	int				x;
	unsigned int	buffer[WINDOW_HEIGHT][WINDOW_WIDTH];
	t_ray			*ray;
	t_wall			*wall;

	x = -1;
	ray = init_ray();
	wall = init_wall();
	while (++x <= WINDOW_WIDTH)
	{
		calculate_ray_dir(ray, player, map_info, x);
		calculate_where_is_ray_in(ray, player, map_info);
		calculate_delta_dist(ray);
		calculate_side_dist(ray, player);
		find_wall(ray, map_info);
		calculate_distance_to_wall(ray, player);
		calculate_wall_height(wall, ray);
		draw_vertical_line(x, wall, window, ray);
	}
	free_renderm_memory(ray, wall);
}

void	render_graphic(t_map *map_info, t_player *player, t_window *window)
{
	draw_background(window, map_info);
	draw_screen(map_info, player, window);
	return ;
}
