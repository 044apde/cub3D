/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:10:55 by shikim            #+#    #+#             */
/*   Updated: 2023/09/16 10:34:00 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

int	main(int argc, char **argv)
{
	t_player	*player;
	t_map		*map_info;

	if (argc != 2)
	{
		show_error("need map file\n");
		return (1);
	}
	map_info = parse_map_info(argv[1]);
	return (0);
}
