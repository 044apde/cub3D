/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:27:23 by shikim            #+#    #+#             */
/*   Updated: 2023/09/19 17:57:28 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	compare_no_path(t_texture *texture, char *path)
{
	if (compare_str(path, texture->so_path) == TRUE)
		ctrl_error("texture path is duplicated\n");
	else if (compare_str(path, texture->we_path) == TRUE)
		ctrl_error("texture path is duplicated\n");
	else if (compare_str(path, texture->ea_path) == TRUE)
		ctrl_error("texture path is duplicated\n");
	else
		return ;
}

void	compare_so_path(t_texture *texture, char *path)
{
	if (compare_str(path, texture->no_path) == TRUE)
		ctrl_error("texture path is duplicated\n");
	else if (compare_str(path, texture->we_path) == TRUE)
		ctrl_error("texture path is duplicated\n");
	else if (compare_str(path, texture->ea_path) == TRUE)
		ctrl_error("texture path is duplicated\n");
	else
		return ;
}

void	compare_we_path(t_texture *texture, char *path)
{
	if (compare_str(path, texture->so_path) == TRUE)
		ctrl_error("texture path is duplicated\n");
	else if (compare_str(path, texture->no_path) == TRUE)
		ctrl_error("texture path is duplicated\n");
	else if (compare_str(path, texture->ea_path) == TRUE)
		ctrl_error("texture path is duplicated\n");
	else
		return ;
}

void	compare_ea_path(t_texture *texture, char *path)
{
	if (compare_str(path, texture->so_path) == TRUE)
		ctrl_error("texture path is duplicated\n");
	else if (compare_str(path, texture->we_path) == TRUE)
		ctrl_error("texture path is duplicated\n");
	else if (compare_str(path, texture->no_path) == TRUE)
		ctrl_error("texture path is duplicated\n");
	else
		return ;
}
