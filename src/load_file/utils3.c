/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:44:08 by shikim            #+#    #+#             */
/*   Updated: 2023/09/19 20:23:39 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <string.h>

int	is_texture_identifier(char *str)
{
	if (str == NULL)
		return (FALSE);
	else if (compare_str("NO", str) == TRUE)
		return (NO);
	else if (compare_str("SO", str) == TRUE)
		return (SO);
	else if (compare_str("WE", str) == TRUE)
		return (WE);
	else if (compare_str("EA", str) == TRUE)
		return (EA);
	else if (compare_str("F", str) == TRUE)
		return (F);
	else if (compare_str("C", str) == TRUE)
		return (C);
	else
		return (FALSE);
}

int	is_texture_element(char *line)
{
	char	**splited_line;
	int		result;

	splited_line = ft_split(line, ' ');
	result = TRUE;
	if (is_texture_identifier(splited_line[0]) == FALSE)
		result = FALSE;
	else if (splited_line[1] == NULL)
		result = FALSE;
	else if (splited_line[2] != NULL)
		result = FALSE;
	free_two_dimension_array(splited_line);
	return (result);
}

int	is_map_element(char *line)
{
	if (line[0] == ' ')
		return (TRUE);
	else if (line[0] == '0')
		return (TRUE);
	else if (line[0] == '1')
		return (TRUE);
	else
		return (FALSE);
}

void	is_valid_path(int identifier, char *path, t_texture *texture)
{
	char	*trimmed_path;

	if (identifier == F || identifier == C)
		return ;
	else if (identifier == NO)
		compare_no_path(texture, path);
	else if (identifier == SO)
		compare_so_path(texture, path);
	else if (identifier == WE)
		compare_we_path(texture, path);
	else if (identifier == EA)
		compare_ea_path(texture, path);
	trimmed_path = trim_path(path);
	close(open_file(trimmed_path));
	return ;
}

int	set_texture_path(t_map *map_info, char *line)
{
	char		**splited_line;
	int			identifier;

	splited_line = ft_split(line, ' ');
	identifier = is_texture_identifier(splited_line[0]);
	if (identifier == NO && map_info->texture->no_path == NULL)
		map_info->texture->no_path = ft_strdup(splited_line[1]);
	else if (identifier == SO && map_info->texture->so_path == NULL)
		map_info->texture->so_path = ft_strdup(splited_line[1]);
	else if (identifier == WE && map_info->texture->we_path == NULL)
		map_info->texture->we_path = ft_strdup(splited_line[1]);
	else if (identifier == EA && map_info->texture->ea_path == NULL)
		map_info->texture->ea_path = ft_strdup(splited_line[1]);
	else if (identifier == C && map_info->texture->c_color == NULL)
		map_info->texture->c_color = ft_strdup(splited_line[1]);
	else if (identifier == F && map_info->texture->f_color == NULL)
		map_info->texture->f_color = ft_strdup(splited_line[1]);
	else
		ctrl_error("identifer is duplicated\n");
	is_valid_path(identifier, splited_line[1], map_info->texture);
	free_two_dimension_array(splited_line);
	return (1);
}
