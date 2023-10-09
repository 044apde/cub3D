NAME		=	cub3D
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror 
LDFLAGS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit
SOURCE		=	main.c \
				src/parse_input/parse_input.c src/parse_input/utils1.c \
				src/utils/error.c src/utils/string.c src/utils/file.c src/utils/free_info.c \
				src/load_file/load_file.c src/load_file/utils1.c src/load_file/utils2.c \
				src/load_file/utils3.c src/load_file/utils4.c src/load_file/utils5.c \
				src/load_file/utils6.c src/load_file/utils7.c \
				src/gnl/get_next_line.c \
				src/execute_cub3d/execute_cub3d.c src/execute_cub3d/utils1.c src/execute_cub3d/utils2.c \
				src/execute_cub3d/utils3.c src/execute_cub3d/utils4.c src/execute_cub3d/utils5.c \
				src/execute_cub3d/utils6.c src/execute_cub3d/utils7.c src/execute_cub3d/utils8.c \
				src/execute_cub3d/utils9.c \
				src/execute_cub3d/key_hook.c src/execute_cub3d/render_graphic.c \
				src/utils/free_render_memory.c
HEADER		=	cub3d.h
LIBRARY 	=	libft/libft.a mlx/libmlx.a
OBJECT		=	$(SOURCE:.c=.o)

all			:	$(NAME)

$(NAME)	:	$(OBJECT) $(LIBRARY) $(HEADER)
	$(CC) $(CFLAGS) -o $@ $(OBJECT) $(LIBRARY) $(LDFLAGS)

$(OBJECT)	:	%.o:%.c
	$(CC) $(CFLAGS) -c $(CFALG) $< -o $@

$(LIBRARY):
	$(MAKE) -C libft
	$(MAKE) -C mlx

clean		:
	rm -rf $(NAME) $(OBJECT)
	$(MAKE) -C libft clean
	$(MAKE) -C mlx clean

fclean		:	clean
	$(MAKE) -C libft fclean

re			:	fclean all

.PHONY		:	all clean fclean re 