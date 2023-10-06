/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_graphic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:13:41 by shikim            #+#    #+#             */
/*   Updated: 2023/10/06 23:34:14 by shikim           ###   ########.fr       */
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

void	draw_screen(t_map *map_info, t_player *player, t_window *window, t_texture_set *texture_set)
{
	int				x;
	t_image			buffer;
	t_ray			*ray;

	x = -1;
	ray = init_ray();
	buffer.image = mlx_new_image(window->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	buffer.addr = mlx_get_data_addr(buffer.image, &buffer.bits_per_pixel, \
									&buffer.line_length, &buffer.endian);
	while (++x <= WINDOW_WIDTH)
	{
		calculate_ray_dir(ray, player, map_info, x);
		calculate_where_is_ray_in(ray, player, map_info);
		calculate_delta_dist(ray);
		calculate_side_dist(ray, player);
		find_wall(ray, map_info);
		calculate_distance_to_wall(ray, player);
		calculate_wall_height(ray);
		fill_buffer(&buffer, player, ray, texture_set);
	}
	mlx_put_image_to_window(window->mlx, window->win, buffer.image, 0, 0);
	free(ray);
}

int	render_graphic(t_render *render)
{
	// draw_background(render->window, render->map_info);
	draw_screen(render->map_info, render->player, render->window, render->texture_set);
	return (0);
}
