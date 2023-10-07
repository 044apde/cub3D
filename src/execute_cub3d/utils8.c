/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:15:24 by shikim            #+#    #+#             */
/*   Updated: 2023/10/07 13:27:28 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_seperator(char *color_string)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (color_string[i] != '\0' && color_string[i] != '\n')
	{
		if (color_string[i] == ',')
			++count;
		else if (ft_isdigit(color_string[i]) == FALSE)
			return (FALSE);
		++i;
	}
	if (count != 2)
		return (FALSE);
	return (TRUE);
}

int	create_trgb(char *color_string)
{
	int		r;
	int		g;
	int		b;
	char	**color_code;

	if (check_seperator(color_string) == FALSE)
		ctrl_error("color string is invalid\n");
	color_code = ft_split(color_string, ',');
	r = ft_atoi(color_code[0]);
	g = ft_atoi(color_code[1]);
	b = ft_atoi(color_code[2]);
	return (0 << 24 | r << 16 | g << 8 | b);
}
