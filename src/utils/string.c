/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:49:56 by shikim            #+#    #+#             */
/*   Updated: 2023/09/19 17:50:52 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	compare_str(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (FALSE);
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (FALSE);
		i++;
	}
	if (str1[i] != '\0' || str2[i] != '\0')
		return (FALSE);
	return (TRUE);
}

void	free_two_dimension_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}

char	*trim_path(char *path)
{
	char	*trimmend_path;
	int		i;

	i = 0;
	if (path == NULL)
		return (NULL);
	else
	{
		while (path[i] != '\n')
			++i;
		path[i] = '\0';
	}
	return (path);
}
