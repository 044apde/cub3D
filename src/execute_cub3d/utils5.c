/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:08:31 by shikim            #+#    #+#             */
/*   Updated: 2023/10/05 12:25:14 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_vertical_line(int x, t_wall *wall, t_window *window, t_ray *ray)
{
	int	h;
	int	color;

	h = wall->draw_start;
	if (ray->side == 0)
		color = 0x009000; // 초록색
	else
		color = 0x000080; // 남색
	while (h < wall->draw_end)
	{
		mlx_pixel_put(window->mlx, window->win, x, h, color);
		++h;
	}
	return ;
}

void	draw_background(t_window *window, t_map	*map_info)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "texture/sky.xpm";
	int		img_width;
	int		img_height;
	int		x;
	int		y;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			mlx_put_image_to_window(window->mlx, window->win, img, x, y);
			x += img_width;
		}
		y += img_height;
	}
	relative_path = "texture/floor.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	y = WINDOW_HEIGHT / 2;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			mlx_put_image_to_window(window->mlx, window->win, img, x, y);
			x += img_width;
		}
		y += img_height;
	}
	return ;
}

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
