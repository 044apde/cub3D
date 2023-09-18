/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:10:55 by shikim            #+#    #+#             */
/*   Updated: 2023/09/17 17:08:27 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

int	main(int argc, char **argv)
{
	char	*map_path;
	t_map	*map_info;

	if (argc != 2)
	{
		show_error("need one map file\n");
		return (1);
	}
	map_path = parse_input(argv[1]);
	map_info = load_file(map_path);
	execute_window(map_info); 
	return (0);
}
