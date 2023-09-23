/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:08:31 by shikim            #+#    #+#             */
/*   Updated: 2023/09/23 15:56:50 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_vertical_line(int x, t_wall *wall, t_window *window)
{
	int	h;

	h = wall->draw_start;
	while (h < wall->draw_end)
	{
		mlx_pixel_put(window->mlx, window->win, x, h, 0xFFFFFF);
		++h;
	}
	return ;
}