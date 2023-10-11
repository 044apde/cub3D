/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:10:55 by shikim            #+#    #+#             */
/*   Updated: 2023/10/11 13:41:37 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

void	check(void)
{
	system("leaks cub3D");
	return ;
}

int	main(int argc, char **argv)
{
	char	*map_path;
	t_map	*map_info;

	atexit(check);
	if (argc != 2)
	{
		show_error("need one map file\n");
		return (1);
	}
	map_path = parse_input(argv[1]);
	map_info = load_file(map_path);
	execute_cub3d(map_info);
	free(map_path);
	free_map_info(map_info);
	return (0);
}
