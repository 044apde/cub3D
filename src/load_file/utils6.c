/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:29:50 by shikim            #+#    #+#             */
/*   Updated: 2023/09/20 16:44:48 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_map_component(char component)
{
	if (component == '0')
		return (TRUE);
	else if (component == '1')
		return (TRUE);
	else if (component == 'N')
		return (TRUE);
	else if (component == 'S')
		return (TRUE);
	else if (component == 'E')
		return (TRUE);
	else if (component == 'W')
		return (TRUE);
	else if (component == ' ')
		return (TRUE);
	return (FALSE);
} 