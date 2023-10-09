/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:08:32 by shikim            #+#    #+#             */
/*   Updated: 2023/10/09 17:45:19 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	end_cub3d(void)
{
	printf("End game..\n");
	exit(0);
}

int	is_movable_place(t_map *map_info, int y, int x)
{
	char	**map;
	int		map_height;
	int		map_width;

	map = map_info->map;
	map_height = map_info->height;
	map_width = map_info->width;
	if ((y >= 0 && y < map_height) && (x >= 0 && x < map_width))
	{
		if (is_empty_space(map[y][x]) == TRUE)
			return (TRUE);
	}
	return (FALSE);
}

void	move_player(t_player *player, t_map *map_info, int keycode)
{
	if (keycode == KEY_W)
		move_forward(player, map_info);
	else if (keycode == KEY_A)
		move_left(player, map_info);
	else if (keycode == KEY_S)
		move_back(player, map_info);
	else if (keycode == KEY_D)
		move_right(player, map_info);
	return ;
}

void	rotate_player(t_player *p, int keycode)
{
	double	old_dir_x;
	double	old_plane_x;

	if (keycode == 124)
	{
		old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(-ROTSPEED) - p->dir_y * sin(-ROTSPEED);
		p->dir_y = old_dir_x * sin(-ROTSPEED) + p->dir_y * cos(-ROTSPEED);
		old_plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(-ROTSPEED) - p->plane_y * sin(-ROTSPEED);
		p->plane_y = old_plane_x * sin(-ROTSPEED) + p->plane_y * cos(-ROTSPEED);
	}
	else if (keycode == 123)
	{
		old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(ROTSPEED) - p->dir_y * sin(ROTSPEED);
		p->dir_y = old_dir_x * sin(ROTSPEED) + p->dir_y * cos(ROTSPEED);
		old_plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(ROTSPEED) - p->plane_y * sin(ROTSPEED);
		p->plane_y = old_plane_x * sin(ROTSPEED) + p->plane_y * cos(ROTSPEED);
	}
	return ;
}

int	key_hook(int keycode, t_render *temp)
{
	t_map		*map_info;
	t_player	*player;

	map_info = temp->map_info;
	player = temp->player;
	if (keycode == 53)
		end_cub3d();
	else if (keycode == KEY_W || keycode == KEY_A \
			|| keycode == KEY_S || keycode == KEY_D)
		move_player(player, map_info, keycode);
	else if (keycode == 124 || keycode == 123)
		rotate_player(player, keycode);
	return (0);
}
