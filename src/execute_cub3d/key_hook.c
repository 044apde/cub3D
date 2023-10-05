/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:08:32 by shikim            #+#    #+#             */
/*   Updated: 2023/10/05 23:47:37 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	end_cub3d(void)
{
	printf("End game..\n");
	exit(0);
}

void	move_player(t_player *player, t_map *map_info, int keycode)
{
	if (keycode == KEY_W)
	{
		printf("y: %d x: %d\n", (int)player->pos_y, (int)(player->pos_x + player->dir_x * MOVE_SPEED));
		if (map_info->map[(int)player->pos_y][(int)(player->pos_x + player->dir_x * MOVE_SPEED)] != WALL)
			player->pos_x += player->dir_x * MOVE_SPEED;
		if (map_info->map[(int)(player->pos_y + player->dir_y * MOVE_SPEED)][(int)player->pos_x] != WALL)
			player->pos_y += player->dir_y * MOVE_SPEED;
	}
	else if (keycode == KEY_A)
	{
		printf("y: %d x: %d\n", (int)player->pos_y, (int)(player->pos_x + player->dir_x * MOVE_SPEED));
		if (map_info->map[(int)player->pos_y][(int)(player->pos_x - player->dir_x * MOVE_SPEED)] != WALL)
			player->pos_x -= player->dir_y * MOVE_SPEED;
		if (map_info->map[(int)(player->pos_y + player->dir_y * MOVE_SPEED)][(int)player->pos_x] != WALL)
			player->pos_y += player->dir_x * MOVE_SPEED;
	}
	else if (keycode == KEY_S)
	{
		printf("y: %d x: %d\n", (int)player->pos_y, (int)(player->pos_x + player->dir_x * MOVE_SPEED));
		if (map_info->map[(int)player->pos_y][(int)(player->pos_x - player->dir_x * MOVE_SPEED)] != WALL)
			player->pos_x -= player->dir_x * MOVE_SPEED;
		if (map_info->map[(int)(player->pos_y - player->dir_y * MOVE_SPEED)][(int)player->pos_x] != WALL)
			player->pos_y -= player->dir_y * MOVE_SPEED;
	}
	else if (keycode == KEY_D)
	{
		printf("y: %d x: %d\n", (int)player->pos_y, (int)(player->pos_x + player->dir_x * MOVE_SPEED));
		if (map_info->map[(int)player->pos_y][(int)(player->pos_x + player->dir_x * MOVE_SPEED)] != WALL)
			player->pos_x += player->dir_y * MOVE_SPEED;
		if (map_info->map[(int)(player->pos_y - player->dir_y * MOVE_SPEED)][(int)player->pos_x] != WALL)
			player->pos_y -= player->dir_x * MOVE_SPEED;
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
	}
	else if (keycode == 123)
	{
		old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(ROT_SPEED) - player->dir_y * sin(ROT_SPEED);
		player->dir_y = old_dir_x * sin(ROT_SPEED) + player->dir_y * cos(ROT_SPEED);
		old_plane_x =  player->plane_x;
		player->plane_x = player->plane_x * cos(-ROT_SPEED) - player->plane_y * sin(ROT_SPEED);
		player->plane_y = old_plane_x * sin(ROT_SPEED) + player->plane_y * cos(ROT_SPEED);
	}
	return ;
}

int	key_hook(int keycode, t_temp *temp)
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
