/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:08:31 by shikim            #+#    #+#             */
/*   Updated: 2023/10/07 13:36:47 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	calculate_wall_x(int side, t_player *player, t_ray *ray)
{
	double	wall_x;

	if (side == 0)
		wall_x = player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor((wall_x));
	return (wall_x);
}

int	calculate_tex_x(int side, double wall_x, t_ray *ray)
{
	int	tex_x;

	tex_x = (int)(wall_x * (double)(TEXTURE_WIDTH));
	if(side == 0 && ray->ray_dir_x > 0)
		tex_x = TEXTURE_WIDTH - tex_x - 1;
	if(side == 1 && ray->ray_dir_y < 0)
		tex_x = TEXTURE_WIDTH - tex_x - 1;
	return (tex_x);
}
