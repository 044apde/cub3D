/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:12:23 by shikim            #+#    #+#             */
/*   Updated: 2023/10/07 13:15:07 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_texture_info	*open_texture(char *texture_path, t_window *window)
{
	t_temp_data		data;
	t_texture_info	*texture;
	int				row;
	int				col;

	data.image = mlx_xpm_file_to_image(window->mlx, texture_path, &data.width, &data.height);
	if (data.image == NULL)
		ctrl_error("wrong texture");
	data.temp =  (int *)mlx_get_data_addr(data.image, &data.bpp, &data.line_size, &data.endian);
	texture = (t_texture_info *)malloc(sizeof(t_texture_info));
	if (texture == NULL)
		ctrl_error("wrong texture");
	texture->data = (int *)malloc(sizeof(int) * (data.width * data.height));
	row = -1;
	while (++row < data.height)
	{
		col = -1;
		while (++col < data.width)
			texture->data[data.width * row + col] = data.temp[data.width * row + col];
	}
	return (texture);
}

t_texture_set	*init_texture_set(t_map *map_info, t_window *window)
{
	t_texture_set	*texture_set;

	texture_set = (t_texture_set *)malloc(sizeof(t_texture_set));
	if (texture_set == NULL)
		ctrl_error("failed to malloc\n");
	else
	{
		texture_set->n_texture = open_texture(map_info->texture->no_path, window);
		texture_set->s_texture = open_texture(map_info->texture->so_path, window);
		texture_set->e_texture = open_texture(map_info->texture->ea_path, window);
		texture_set->w_texture = open_texture(map_info->texture->we_path, window);
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
