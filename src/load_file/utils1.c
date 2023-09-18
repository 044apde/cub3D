/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:12:59 by shikim            #+#    #+#             */
/*   Updated: 2023/09/18 16:58:27 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_map	*init_map_info(void)
{
	t_map	*map_info;

	map_info = (t_map *)malloc(sizeof(t_map));
	if (map_info == NULL)
		ctrl_error("failed to malloc\n");
	else
	{
		map_info->height = 0;
		map_info->width = 0;
		map_info->map = NULL;
		map_info->player = NULL;
		map_info->texture = NULL;
	}
	return (map_info);
}

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

	splited_line = ft_split(line, " ");
	result = TRUE;
	if (is_texture_identifier(splited_line[0]) != FALSE)
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
	if (line[0] == '1')
		return (TRUE);
	if (line[0] == 'N')
		return (TRUE);
	if (line[0] == 'W')
		return (TRUE);
	if (line[0] == 'E')
		return (TRUE);
	if (line[0] == 'S')
		return (TRUE);
	return (FALSE);
}

void	is_valid_path(char *path)
{
	
}

void	set_texture_path(t_map *map_info, char *line)
{
	char		**splited_line;
	int			identifier;

	identifier = is_texture_identifier(line);
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
		ctrl_error("check texture element\n");
	is_valid_path(splited_line[1]);
	free_two_dimension_array(splited_line);
}

void	get_texutre(t_map *map_info, int fd)
{
	char	*line;

	while (map_info->texture->count_texture < 6)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		else if (compare_str(line, "\n") == TRUE)
			;
		else if (is_map_element(line) == TRUE)
			ctrl_error("check element order\n");
		else if (is_texture_element(line) != FALSE)
			set_texture_path(map_info, line);
		else
			ctrl_error("invalid element\n");
		free(line);
	}
	if (map_info != 6)
		ctrl_error("check texture element\n");
}
