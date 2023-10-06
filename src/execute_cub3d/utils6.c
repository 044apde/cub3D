/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:25:58 by shikim            #+#    #+#             */
/*   Updated: 2023/10/06 00:20:30 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	my_put_pixel(t_image *buffer, int x, int y, int color)
{
	char	*dest;

	dest = buffer->addr + (y * buffer->line_length + x * (buffer->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
	return ;
}

void	set_pixel_from_texture(t_image *buffer, t_ray *ray, t_texture_set *texture_set)
{
	int		y;
	int		tex_y;
	int		color;
	double	step;
	double	tex_pos;

	step = 1.0 * TEXTURE_HEIGHT / ray->line_height;
	tex_pos = (ray->draw_start - WINDOW_HEIGHT / 2 + ray->line_height / 2) * step;
	y = ray->draw_start - 1;
	while (++y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (TEXTURE_HEIGHT - 1);
		tex_pos += step;
		if (ray->side == 0)
		{
			color = 0xFFFF00;
			if (ray->step_x > 0)
				color = 0x8b00ff;
		}
		if (ray->side == 1)
		{
			color = 0xff00000;
			if (ray->step_y > 0)
				color = 0x0067a3;
		}
		my_put_pixel(buffer, ray->x, y, color);
	}
	return ;
}

void	fill_buffer(t_image *buffer, t_player *player, t_ray *ray, t_texture_set *texture_set)
{
	double	wall_x;
	double	tex_x;

	wall_x = calculate_wall_x(ray->side, player, ray);
	tex_x = calculate_tex_x(ray->side, wall_x, ray);
	set_pixel_from_texture(buffer, ray, texture_set);
	return ;
}
