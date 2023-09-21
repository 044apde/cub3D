/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:10:55 by shikim            #+#    #+#             */
/*   Updated: 2023/09/21 15:07:13 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

void	test_leak(void)
{
	system("leaks cub3D");
}

int	main(int argc, char **argv)
{
	char	*map_path;
	t_map	*map_info;

	atexit(test_leak);
	if (argc != 2)
	{
		show_error("need one map file\n");
		return (1);
	}
	map_path = parse_input(argv[1]);
	map_info = load_file(map_path);
	free(map_path);
	free_map_info(map_info);
	return (0);
}
