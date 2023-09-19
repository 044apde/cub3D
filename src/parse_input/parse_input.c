/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:18:42 by shikim            #+#    #+#             */
/*   Updated: 2023/09/19 20:28:00 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*parse_input(char *input)
{
	char	*map_path;

	check_map_name(input);
	map_path = make_map_path(input);
	check_map_file(map_path);
	return (map_path);
}
