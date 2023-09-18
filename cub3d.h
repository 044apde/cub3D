/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:15:46 by shikim            #+#    #+#             */
/*   Updated: 2023/09/18 14:42:41 by shikim           ###   ########.fr       */
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
	char	*c_color;
	char	*f_color;
}	t_texture;

typedef struct s_map
{
	char		**map;
	int			height;
	int			width;
	t_texture	*texture;
	t_player	*player;
}	t_map;

// UTILS
void	show_error(char *error_message);
void	ctrl_error(char *error_message);
void	free_two_dimension_array(char **array);
int		compare_str(char *str1, char *str2);
int		open_file(char *map_path);

// PARSE INPUT
char	*parse_input(char *input);
char	*make_map_path(char *map_name);
void	check_map_name(char *map_name);
void	check_map_file(char *map_path);

// LOAD FILE
t_map	*init_map_info(void);

#endif