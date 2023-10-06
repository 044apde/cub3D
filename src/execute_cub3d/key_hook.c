/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:08:32 by shikim            #+#    #+#             */
/*   Updated: 2023/10/06 13:10:05 by shikim           ###   ########.fr       */
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
	if ((y >= 0 && y <= map_height) && (x >= 0 && x <= map_width))
	{
		if (is_empty_space(map[y][x]) == TRUE)
			return (TRUE);
	}
	return (FALSE);
}

void	move_player(t_player *player, t_map *map_info, int keycode)
{
	if (keycode == KEY_W)
	{
		if (is_empty_space(map_info->map[(int)player->pos_y][(int)(player->pos_x + player->dir_x * MOVE_SPEED + 0.1)]) == TRUE)
			player->pos_x += player->dir_x * MOVE_SPEED;
		printf("%d %d\n", (int)player->pos_y, (int)(player->pos_x + player->dir_x * MOVE_SPEED + 0.1));
		if (is_empty_space(map_info->map[(int)(player->pos_y + player->dir_y * MOVE_SPEED + 0.1)][(int)player->pos_x]) == TRUE)
			player->pos_y += player->dir_y * MOVE_SPEED;
		printf("%d %d\n", (int)player->pos_y, (int)(player->pos_x + player->dir_x * MOVE_SPEED + 0.1));
	}
	else if (keycode == KEY_A)
	{
		if (is_empty_space(map_info->map[(int)player->pos_y][(int)(player->pos_x - player->dir_x * MOVE_SPEED - 0.1)]) == TRUE)
			player->pos_x -= player->dir_y * MOVE_SPEED;
		printf("%d %d\n", (int)player->pos_y, (int)(player->pos_x + player->dir_x * MOVE_SPEED + 0.1));
		if (is_empty_space(map_info->map[(int)(player->pos_y + player->dir_y * MOVE_SPEED + 0.1)][(int)player->pos_x]) == TRUE)
			player->pos_y += player->dir_x * MOVE_SPEED;
		printf("%d %d\n", (int)player->pos_y, (int)(player->pos_x + player->dir_x * MOVE_SPEED + 0.1));
	}
	else if (keycode == KEY_S)
	{
		if (is_empty_space(map_info->map[(int)player->pos_y][(int)(player->pos_x - player->dir_x * MOVE_SPEED - 0.1)]) == TRUE)
			player->pos_x -= player->dir_x * MOVE_SPEED;
		printf("%d %d\n", (int)player->pos_y, (int)(player->pos_x + player->dir_x * MOVE_SPEED + 0.1));
		if (is_empty_space(map_info->map[(int)(player->pos_y - player->dir_y * MOVE_SPEED - 0.1)][(int)player->pos_x]) == TRUE)
			player->pos_y -= player->dir_y * MOVE_SPEED;
		printf("%d %d\n", (int)player->pos_y, (int)(player->pos_x + player->dir_x * MOVE_SPEED + 0.1));
	}
	else if (keycode == KEY_D)
	{
		if (is_empty_space(map_info->map[(int)player->pos_y][(int)(player->pos_x + player->dir_x * MOVE_SPEED + 0.1)]) == TRUE)
			player->pos_x += player->dir_y * MOVE_SPEED;
		printf("%d %d\n", (int)player->pos_y, (int)(player->pos_x + player->dir_x * MOVE_SPEED + 0.1));
		if (is_empty_space(map_info->map[(int)(player->pos_y - player->dir_y * MOVE_SPEED - 0.1)][(int)player->pos_x]) == TRUE)
			player->pos_y -= player->dir_x * MOVE_SPEED;
		printf("%d %d\n", (int)player->pos_y, (int)(player->pos_x + player->dir_x * MOVE_SPEED + 0.1));
	}
	return ;
}

void	rotate_player(t_player *player, t_map *map_info, int keycode)
{
	double	old_dir_x;
	double	old_plane_x;

	if (keycode == 124)
	{
		old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-ROT_SPEED) - player->dir_y * sin(-ROT_SPEED);
		player->dir_y = old_dir_x * sin(-ROT_SPEED) + player->dir_y * cos(-ROT_SPEED);
		old_plane_x =  player->plane_x;
		player->plane_x = player->plane_x * cos(-ROT_SPEED) - player->plane_y * sin(-ROT_SPEED);
		player->plane_y = old_plane_x * sin(-ROT_SPEED) + player->plane_y * cos(-ROT_SPEED);
		printf("y: %d x: %d\n", (int)player->pos_y, (int)(player->pos_x + player->dir_x * MOVE_SPEED));
	}
	else if (keycode == 123)
	{
		old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(ROT_SPEED) - player->dir_y * sin(ROT_SPEED);
		player->dir_y = old_dir_x * sin(ROT_SPEED) + player->dir_y * cos(ROT_SPEED);
		old_plane_x =  player->plane_x;
		player->plane_x = player->plane_x * cos(-ROT_SPEED) - player->plane_y * sin(ROT_SPEED);
		player->plane_y = old_plane_x * sin(ROT_SPEED) + player->plane_y * cos(ROT_SPEED);
		printf("y: %d x: %d\n", (int)player->pos_y, (int)(player->pos_x + player->dir_x * MOVE_SPEED));
	}
	return ;
}

int	key_hook(int keycode, t_render *temp)
{
	t_map		*map_info;
	t_player	*player;
	double		old_dir_x;
	double		old_plane_x;

	map_info = temp->map_info;
	player = temp->player;
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
		end_cub3d();
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
		move_player(player, map_info, keycode);
	else if (keycode == 124 || keycode == 123)
		rotate_player(player, map_info, keycode);
	return (0);
}
