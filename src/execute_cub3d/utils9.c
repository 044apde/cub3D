/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:56:01 by shikim            #+#    #+#             */
/*   Updated: 2023/10/11 13:38:18 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_pass_right(t_map *info, t_player *player)
{
	if (player->dir_y > 0)
	{
		if ((info->map[(int)player->pos_y + 1][(int)player->pos_x] == '1') \
			&& (info->map[(int)player->pos_y][(int)player->pos_x + 1] == '1'))
			return (FALSE);
	}
	else
	{
		if ((info->map[(int)player->pos_y - 1][(int)player->pos_x] == '1') \
			&& (info->map[(int)player->pos_y][(int)player->pos_x + 1] == '1'))
			return (FALSE);
	}
	return (TRUE);
}

int	check_pass_left(t_map *info, t_player *player)
{
	if (player->dir_y > 0)
	{
		if ((info->map[(int)(player->pos_y + 1)][(int)(player->pos_x)] == '1') \
			&& (info->map[(int)(player->pos_y)][(int)(player->pos_x - 1)] \
				== '1'))
			return (FALSE);
	}
	else
	{
		if ((info->map[(int)player->pos_y - 1][(int)player->pos_x] == '1') \
			&& (info->map[(int)player->pos_y][(int)player->pos_x - 1] == '1'))
			return (FALSE);
	}
	return (TRUE);
}

int	check_pass_diagonally(t_map *map_info, t_player *player, int y, int x)
{
	if ((int)player->pos_x != x && (int)player->pos_y != y)
	{
		if (player->dir_x > 0)
		{
			if (check_pass_right(map_info, player) == FALSE)
				return (FALSE);
		}
		else if (player->dir_x < 0)
		{
			if (check_pass_left(map_info, player) == FALSE)
				return (FALSE);
		}
	}
	return (TRUE);
}

void	calculate_side_dist_x(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		if (ray->delta_dist_x == NO_VALUE)
			ray->side_dist_x = NO_VALUE;
		else
			ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		if (ray->delta_dist_x == NO_VALUE)
			ray->side_dist_x = NO_VALUE;
		else
			ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x) * \
				ray->delta_dist_x;
	}
}

void	calculate_side_dist_y(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		if (ray->delta_dist_y == NO_VALUE)
			ray->side_dist_y = NO_VALUE;
		else
			ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		if (ray->delta_dist_y == NO_VALUE)
			ray->side_dist_y = NO_VALUE;
		else
			ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y) * \
				ray->delta_dist_y;
	}
}
