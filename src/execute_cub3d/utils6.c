/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:25:58 by shikim            #+#    #+#             */
/*   Updated: 2023/10/09 17:57:56 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	my_put_pixel(t_image *buffer, int x, int y, int color)
{
	char	*dest;

	dest = NULL;
	if ((0 <= x && x < WINDOW_WIDTH) && (0 <= y && y < WINDOW_HEIGHT))
	{
		dest = buffer->addr + (y * buffer->line_length + x * (buffer->bits_per_pixel / 8));
		*(unsigned int *)dest = color;
	}
	return ;
}

int	get_texture_height(t_ray *ray, t_texture_set *texture_set)
{
	int	height;

	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			height = texture_set->e_texture->height;
		else
			height = texture_set->w_texture->height;
	}
	else
	{
		if (ray->ray_dir_y < 0)
			height = texture_set->s_texture->height;
		else
			height = texture_set->n_texture->height;
	}
	return (height);
}

int	set_color(t_texture_set *texture_set, t_ray *ray, int tex_x, int tex_y)
{
	int	color;

	if (ray->side == 0)
	{
		color = texture_set->w_texture->data[texture_set->w_texture->width * tex_y + tex_x];
		if (ray->ray_dir_x > 0)
			color = texture_set->e_texture->data[texture_set->e_texture->width \
				* tex_y + tex_x];
	}
	if (ray->side == 1)
	{
		color = texture_set->s_texture->data[texture_set->s_texture->width * tex_y + tex_x];
		if (ray->ray_dir_y > 0)
			color = texture_set->n_texture->data[texture_set->n_texture->width \
				* tex_y + tex_x];
	}
	return (color);
}

void	set_pixel_from_texture(t_image *buffer, t_ray *ray, \
	t_texture_set *texture_set, int tex_x)
{
	int		y;
	int		tex_y;
	int		color;
	double	step;
	double	tex_pos;

	step = 1.0 * get_texture_height(ray, texture_set) / ray->line_height;
	tex_pos = (ray->draw_start - WINDOW_HEIGHT / 2 \
		+ ray->line_height / 2) * step;
	y = ray->draw_start - 1;
	while (++y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (get_texture_height(ray, texture_set) - 1);
		tex_pos += step;
		color = set_color(texture_set, ray, tex_x, tex_y);
		my_put_pixel(buffer, ray->x, y, color);
	}
}

void	fill_buffer(t_image *buffer, t_player *player, \
	t_ray *ray, t_texture_set *texture_set)
{
	double	wall_x;
	double	tex_x;

	wall_x = calculate_wall_x(ray->side, player, ray);
	tex_x = calculate_tex_x(ray->side, wall_x, ray, texture_set);
	draw_background(buffer, ray, texture_set);
	set_pixel_from_texture(buffer, ray, texture_set, tex_x);
	return ;
}
