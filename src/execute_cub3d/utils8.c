/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:15:24 by shikim            #+#    #+#             */
/*   Updated: 2023/10/09 17:37:19 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int check_color_range(char *color_string)
{
	int	rgb;

	if (!color_string)
		return (FALSE);
	else if (ft_strlen(color_string) > 4)
		return (FALSE);
	rgb = ft_atoi(color_string);
	if (rgb < 0 || 255 < rgb)
		return (FALSE);
	return (TRUE);
}

static int	check_seperator(char *color_string)
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

static int	check_array_number(char **array)
{
	int	count;

	count = 0;
	while (array[count] != NULL)
	{
		if (check_color_range(array[count]) == FALSE)
			return (FALSE);
		++count;
	}
	if (count != 3)
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
	if (check_array_number(color_code) == FALSE)
		ctrl_error("color string is invalid\n");
	r = ft_atoi(color_code[0]);
	g = ft_atoi(color_code[1]);
	b = ft_atoi(color_code[2]);
	free(color_code[0]);
	free(color_code[1]);
	free(color_code[2]);
	free(color_code);
	return (0 << 24 | r << 16 | g << 8 | b);
}

void	draw_background(t_image *buffer, t_ray *ray, t_texture_set *texture_set)
{
	int	y;
	int	color;

	y = -1;
	while (++y < ray->draw_start)
	{
		color = texture_set->ceil;
		my_put_pixel(buffer, ray->x, y, color);
	}
	y = ray->draw_end - 1;
	while (++y < WINDOW_HEIGHT)
	{
		color = texture_set->floor;
		my_put_pixel(buffer, ray->x, y, color);
	}
	return ;
}
