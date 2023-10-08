/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:08:37 by shikim            #+#    #+#             */
/*   Updated: 2023/10/08 15:10:58 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ctrl_error(char *error_message)
{
	show_error(error_message);
	exit(1);
}

void	show_error(char *error_message)
{
	write(2, "\033[0;35mError\n", ft_strlen("\033[0;35mError\n"));
	write(2, error_message, ft_strlen(error_message));
	write(2, "\033[0;0m", ft_strlen("\033[0;0m"));
	return ;
}
