/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:12:23 by shikim            #+#    #+#             */
/*   Updated: 2023/10/08 14:55:13 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	*make_image(t_window *window, char *texpath, t_texture_info *texture)
{
	void	*image;

	image = mlx_xpm_file_to_image(window->mlx, texpath, \
		&texture->width, &texture->height);
	if (image == NULL)
		ctrl_error("wrong texture");
	return (image);
}

t_texture_info	*open_texture(char *texture_path, t_window *window)
{
	t_temp_data		data;
	t_texture_info	*texture;
	int				row;
	int				col;

	texture = (t_texture_info *)malloc(sizeof(t_texture_info));
	if (texture == NULL)
		ctrl_error("wrong texture");
	data.image = make_image(window, texture_path, texture);
	data.temp = (int *)mlx_get_data_addr(data.image, \
		&data.bpp, &data.line_size, &data.endian);
	texture->data = (int *)malloc(sizeof(int) * \
		(texture->width * texture->height));
	row = -1;
	while (++row < texture->height)
	{
		col = -1;
		while (++col < texture->width)
			texture->data[texture->width * row + col] = \
				data.temp[texture->width * row + col];
	}
	return (texture);
}

t_texture_set	*init_texture_set(t_map *map_info, t_window *win)
{
	t_texture_set	*texture_set;

	texture_set = (t_texture_set *)malloc(sizeof(t_texture_set));
	if (texture_set == NULL)
		ctrl_error("failed to malloc\n");
	else
	{
		texture_set->n_texture = open_texture(map_info->texture->no_path, win);
		texture_set->s_texture = open_texture(map_info->texture->so_path, win);
		texture_set->e_texture = open_texture(map_info->texture->ea_path, win);
		texture_set->w_texture = open_texture(map_info->texture->we_path, win);
		texture_set->ceil = create_trgb(map_info->texture->c_color);
		texture_set->floor = create_trgb(map_info->texture->f_color);
	}
	return (texture_set);
}

t_render	*init_render(t_player *player, t_window *window, t_map *map_info)
{
	t_render	*render;

	render = (t_render *)malloc(sizeof(t_render));
	if (render == NULL)
		ctrl_error("failed to malloc\n");
	else
	{
		render->map_info = map_info;
		render->player = player;
		render->window = window;
		render->texture_set = init_texture_set(map_info, window);
	}
	return (render);
}

void	execute_cub3d(t_map *map_info)
{
	t_player	*player;
	t_window	*window;
	t_render	*render;

	player = init_player(map_info);
	window = init_window();
	render = init_render(player, window, map_info);
	mlx_hook(window->win, 2, 1L << 0, key_hook, render);
	mlx_loop_hook(window->mlx, render_graphic, render);
	mlx_loop(window->mlx);
	// free_render_memory(render);
	return ;
}
