/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:08:31 by shikim            #+#    #+#             */
/*   Updated: 2023/10/10 15:11:05 by shikim           ###   ########.fr       */
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

int	calculate_tex_x(int side, double wall_x, \
	t_ray *ray, t_texture_set *texture_set)
{
	int	tex_x;

	if (side == 0)
	{
		if (ray->ray_dir_x > 0)
			tex_x = texture_set->e_texture->width - \
				(int)(wall_x * (double)(texture_set->e_texture->width)) - 1;
		else
			tex_x = (int)(wall_x * (double)(texture_set->w_texture->width));
	}
	else
	{
		if (ray->ray_dir_y < 0)
			tex_x = texture_set->s_texture->width - \
				(int)(wall_x * (double)(texture_set->s_texture->width)) - 1;
		else
			tex_x = (int)(wall_x * (double)(texture_set->n_texture->width));
	}
	return (tex_x);
}
