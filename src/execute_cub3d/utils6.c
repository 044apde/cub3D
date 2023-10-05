/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:25:58 by shikim            #+#    #+#             */
/*   Updated: 2023/10/03 17:29:59 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_screen(unsigned int *buffer, t_player *player, t_ray *ray, t_wall *wall)
{
	double	wall_x;
	double	tex_x;

	wall_x = calculate_wall_x(ray->side, player, ray);
	tex_x = calculate_tex_x(ray->side, wall_x, ray);
	fill_buffer(wall, buffer, ray->side, x);
}