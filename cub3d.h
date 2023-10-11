/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:15:46 by shikim            #+#    #+#             */
/*   Updated: 2023/10/11 14:16:05 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include "src/gnl/get_next_line.h"
# include "mlx/mlx.h"

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define WINDOW_HEIGHT 720
# define WINDOW_WIDTH 1280
# define TEXTURE_HEIGHT 64
# define TEXTURE_WIDTH 64
# define NO 11
# define SO 12
# define WE 13
# define EA 14
# define F 15
# define C 16
# define NO_VALUE 9999999
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define MOVE_SPEED 0.1
# define MOVE_TEMP 0.2
# define ROTSPEED 0.2
# define WALL 1
# define ON_DESTROY 17

typedef struct s_texture_info
{
	int	*data;
	int	width;
	int	height;
}	t_texture_info;

typedef struct s_temp_data
{
	void	*image;
	int		*texture;
	int		bpp;
	int		line_size;
	int		endian;
	int		*temp;
}	t_temp_data;

typedef struct s_texture_set
{
	t_texture_info	*n_texture;
	t_texture_info	*s_texture;
	t_texture_info	*e_texture;
	t_texture_info	*w_texture;
	int				ceil;
	int				floor;
}	t_texture_set;

typedef struct s_speed
{
	double	move_speed;
	double	rot_speed;
}	t_speed;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		map_x;
	int		map_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		x;
}	t_ray;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	double	time;
	double	old_time;
}	t_window;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	char	direction;
}	t_player;

typedef struct s_texture_path
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
	int			count_height;
	int			width;
	t_texture	*texture;
	t_player	*player;
}	t_map;

typedef struct s_image
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_render
{
	t_map			*map_info;
	t_player		*player;
	t_window		*window;
	t_texture_set	*texture_set;
}	t_render;

// UTILS
void		show_error(char *error_message);
void		ctrl_error(char *error_message);
void		free_two_dimension_array(char **array);
int			compare_str(char *str1, char *str2);
int			open_file(char *map_path);
char		*trim_path(char *path);
void		free_map_info(t_map *map_info);
void		show_map(char **map, t_map *map_info);
void		free_render_memory(t_render	*render);

// PARSE INPUT
char		*parse_input(char *input);
char		*make_map_path(char *map_name);
void		check_map_name(char *map_name);
void		check_map_file(char *map_path);

// LOAD FILE
t_map		*load_file(char *map_path);
t_map		*init_map_info(void);
void		get_map(t_map *map_info, int fd, char *map_path);
void		get_texture(t_map *map_info, int fd);
void		compare_no_path(t_texture *texture, char *path);
void		compare_so_path(t_texture *texture, char *path);
void		compare_we_path(t_texture *texture, char *path);
void		compare_ea_path(t_texture *texture, char *path);
int			is_texture_identifier(char *str);
int			is_texture_element(char *line);
int			is_map_element(char *line);
void		is_valid_path(int identifier, char *path, t_texture *texture);
int			set_texture_path(t_map *map_info, char *line);
char		**make_map_array(t_map *map_info, char *map_path);
int			is_map_component(char component);
void		check_starting_position(char **map, t_map *map_info);
void		check_map_is_closed(char **map, t_map *map_info);
void		check_north_is_empty(char **map, int h, int w);
void		check_south_is_empty(t_map *map_info, char **map, int h, int w);
void		check_east_is_empty(t_map *map_info, char **map, int h, int w);
void		check_west_is_empty(char **map, int h, int w);
int			is_empty_space(char component);
void		trim_texture_path(t_map *map_info);

// CUB3D
void		execute_cub3d(t_map *map_info);
int			render_graphic(t_render *temp);
int			key_hook(int keycode, t_render *temp);
int			event_hook(t_window *temp);
void		end_cub3d(void);
t_player	*init_player(t_map *map_info);
t_window	*init_window(void);
double		absolutilize(double num);
void		calculate_side_dist(t_ray *ray, t_player *player);
void		calculate_ray_dir(t_ray *ray, t_player *player, \
				t_map *map_info, int x);
void		calculate_where_is_ray_in(t_ray *ray, \
				t_player *player);
void		calculate_delta_dist(t_ray *ray);
void		find_wall(t_ray *ray, t_map *map_info);
void		calculate_distance_to_wall(t_ray *ray, t_player *player);
void		calculate_wall_height(t_ray *ray);
double		calculate_wall_x(int side, t_player *player, t_ray *ray);
int			calculate_tex_x(int side, double wall_x, \
				t_ray *ray, t_texture_set *texture_set);
void		my_put_pixel(t_image *buffer, int x, int y, int color);
void		fill_buffer(t_image *buffer, t_player *player, \
				t_ray *ray, t_texture_set *texture_set);
void		move_forward(t_player *player, t_map *map_info);
void		move_left(t_player *player, t_map *map_info);
void		move_back(t_player *player, t_map *map_info);
void		move_right(t_player *player, t_map *map_info);
int			is_movable_place(t_map *map_info, t_player *player, int y, int x);
int			create_trgb(char *color_string);
void		draw_background(t_image *buffer, t_ray *ray, \
				t_texture_set *texture_set);
void		calculate_side_dist_x(t_ray *ray, t_player *player);
void		calculate_side_dist_y(t_ray *ray, t_player *player);
int			check_pass_diagonally(t_map *map_info, \
				t_player *player, int y, int x);

#endif