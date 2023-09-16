/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:15:46 by shikim            #+#    #+#             */
/*   Updated: 2023/09/16 13:59:52 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "src/gnl/get_next_line.h"

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define WINDOW_HEIGHT 576
# define WINDOW_WIDTH 1024
# define NO 11
# define SO 12
# define WE 13
# define EA 14
# define F 15
# define C 16

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_texture
{
	int		count_texture;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}	t_texture;

typedef struct s_map
{
	char		**map;
	int			height;
	int			width;
	t_texture	*texture;
}	t_map;

// UTILS
void	show_error(char *error_message);
void	ctrl_error(char *error_message);
int		compare_str(char *str1, char *str2);

// PARSE
t_map	*parse_map_info(char *map_name);
int		open_file(char *map_path);
int		is_map_information(char *line);
int		is_texture_information(char *line);
int		is_map_componenet(char component);
void	set_map_info(t_map *map_info, char *map_path);

#endif