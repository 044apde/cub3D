/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:56:01 by shikim            #+#    #+#             */
/*   Updated: 2023/10/11 16:41:17 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_diagonal_move(t_player *player, int y, int x)
{
	int	result;

	result = FALSE;
	if ((int)player->pos_x != x && (int)player->pos_y != y)
	{
		result = TRUE;
	}
	return (result);
}

int	check_where_to_go(t_player *player, int y, int x)
{
	int	where_to_go;

	if (x - (int)player->pos_x > 0)
	{
		if (y - (int)player->pos_y > 0)
			where_to_go = RIGHT_UP;
		else
			where_to_go = RIGHT_DOWN;
	}
	else
	{
		if (y - (int)player->pos_y > 0)
			where_to_go = LEFT_UP;
		else
			where_to_go = LEFT_DOWN;
	}
	return (where_to_go);
}

int	check_pass_diagonally(t_map *map_info, t_player *player, int y, int x)
{
	int	where_to_go;

	if (is_diagonal_move(player, y, x) == FALSE)
		return (TRUE);
	else
	{
		where_to_go = check_where_to_go(player, y, x);
		if (check_diagonal_move(map_info, player, where_to_go) == FALSE)
			return (FALSE);
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
