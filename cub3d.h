/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:15:46 by shikim            #+#    #+#             */
/*   Updated: 2023/09/19 23:10:30 by shikim           ###   ########.fr       */
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
char	*trim_path(char *path);
void	free_map_info(t_map *map_info);

// PARSE INPUT
char	*parse_input(char *input);
char	*make_map_path(char *map_name);
void	check_map_name(char *map_name);
void	check_map_file(char *map_path);

// LOAD FILE
t_map	*load_file(char *map_path);
t_map	*init_map_info(void);
void	get_map(t_map *map_info, int fd, char *map_path);
void	get_texture(t_map *map_info, int fd);
void	compare_no_path(t_texture *texture, char *path);
void	compare_so_path(t_texture *texture, char *path);
void	compare_we_path(t_texture *texture, char *path);
void	compare_ea_path(t_texture *texture, char *path);
int		is_texture_identifier(char *str);
int		is_texture_element(char *line);
int		is_map_element(char *line);
void	is_valid_path(int identifier, char *path, t_texture *texture);
int		set_texture_path(t_map *map_info, char *line);

#endif