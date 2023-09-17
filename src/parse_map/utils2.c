/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:16:37 by shikim            #+#    #+#             */
/*   Updated: 2023/09/17 11:33:39 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_map_componenet(char component)
{
	if (component == 9 || component == 32 || component == '1' ||
		component == '0' || component == 'N' || component == 'S' ||
		component == 'E' || component == 'W')
		return (TRUE);
	return (FALSE);
}

int	is_texture_information(char *line)
{
	char	**texture_information;

	texture_information = ft_split(line, ' ');
	if (compare_str(texture_information[0], "NO") == TRUE)
		return (NO);
	if (compare_str(texture_information[0], "SO") == TRUE)
		return (SO);
	if (compare_str(texture_information[0], "WE") == TRUE)
		return (WE);
	if (compare_str(texture_information[0], "EA") == TRUE)
		return (EA);
	if (compare_str(texture_information[0], "F") == TRUE)
		return (F);
	if (compare_str(texture_information[0], "C") == TRUE)
		return (C);
	free_two_dimension_array(texture_information);
	return (FALSE);
}

int	is_map_information(char *line)
{
	if (line[0] == 9 || line[0] == 32 || line[0] == '1')
		return (TRUE);
	return (FALSE);
}
